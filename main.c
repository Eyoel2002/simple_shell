#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @ac: Number of command-line arguments.
 * @av: Array of pointers to command-line arguments.
 *
 * Return: The exit status of the shell process.
 */

int main(int ac, char **av)
{
	sh_data shell;
	(void)ac;

	shell.process = 0;
	shell.status = 0;
	shell.name = *av;
	shell.line = NULL;

	if (isatty(STDIN_FILENO))
		interactive(&shell);
	else
		non_interactive(&shell);

	return (shell.status);
}
