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
    sh_data shell; // Initialize the shell data structure.
    (void)ac; // Suppress unused parameter warning.

    shell.process = 0; // Initialize the process count.
    shell.status = 0; // Initialize the shell status.
    shell.name = *av; // Set the shell name to the program's name.
    shell.line = NULL; // Initialize the input command line pointer.

    if (isatty(STDIN_FILENO))
        interactive(&shell); // Run the interactive shell mode.
    else
        non_interactive(&shell); // Run the non-interactive shell mode.

    return (shell.status); // Return the shell's exit status.
}
