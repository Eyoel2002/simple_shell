#include "shell.h"

/**
 * non_interactive - Handles the shell when not used in an interactive terminal.
 * @shell: A pointer to the shell data structure.
 *
 * This function is responsible for handling the shell when it's not being used
 * in an interactive terminal. It reads input from a source (e.g., a file) and
 * processes the commands in a non-interactive mode.
 *
 * @param shell: A pointer to the shell data structure.
 */
void non_interactive(sh_data *shell)
{
    char *path;
    size_t n = 0;
    int built_r;

    while (_getline(&shell->line, &n, stdin) != -1)
    {
        shell->process++;

        removeNewline(shell->line);
        remove_comment(shell->line);
        shell->tokens = tokenize(shell->line);

        if (shell->tokens == NULL)
            continue;

        built_r = builtins(shell);

        if (built_r == 1)
            continue;

        path = find_path(*shell->tokens);

        if (path != NULL)
        {
            if (_strcmp(path, *shell->tokens) != 0)
            {
                free(*shell->tokens);
                *shell->tokens = strdup(path);
                free(path);
            }
            shell->status = execCmd(shell);
        }
        else
        {
            dprintf(STDERR_FILENO, "%s: %d: %s: not found\n",
                    shell->name, shell->process, *shell->tokens);
            shell->status = EX_NOTFOUND;
        }
        
        free_array(shell->tokens);
    }
    
    free(shell->line);
}
