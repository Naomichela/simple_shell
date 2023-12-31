#include "main.h"

/**
 * prompt - Displays the command prompt.
 */
void prompt(void)
{
    /* Display the prompt if the standard input is a terminal */
    if (isatty(STDIN_FILENO) == 1)
    {
        custom_puts(" $ ");
    }
}

/**
 * handle_error - Handles error conditions and exits.
 * @message: The error message to display.
 */
void handle_error(const char *message)
{
    /* Print error message along with system error message and exit */
    perror(message);
    exit(EXIT_FAILURE);
}

/**
 * handle_other_errors - Handles other error conditions.
 */
void handle_other_errors(void)
{
    /* Handle other error conditions, such as line length exceeding a limit */
    const char error_message[] = "Error: Line too long\n";
    size_t message_len = custom_strlen(error_message) - 1;

    write(STDERR_FILENO, error_message, message_len);
}

/**
 * main - Entry point of the program.
 * Return: Always 0.
 */
int main(void)
{
    char *line = NULL;
    ssize_t read_status;
    size_t bf = 0;
    char **argv = NULL;

    while (1)
    {
        prompt(); /* Display the command prompt */

        /* Read a line of input from the user */
        read_status = getline(&line, &bf, stdin);

        if (read_status == -1)
        {
            /* If getline returns -1, free memory and exit successfully */
            free(line);
            exit(EXIT_SUCCESS);
        }
        else if (read_status == -2)
        {
            /* If getline returns -2, handle other errors and continue to the next iteration */
            handle_other_errors();
            continue;  /* Skip executing the command and go back to the prompt */
        }
        else
        {
            line[read_status - 1] = '\0'; /* Remove the newline character */

            /* Parse the input line into an array of arguments */
            argv = parse_line(line);

            if (argv[0] != NULL)
            {
                /* Execute the command with the parsed arguments */
                execute_command(argv[0], argv);
            }

            /* Free the memory allocated for the argument array */
            free(argv);
        }
    }

    /* Free the memory allocated for the input line */
    free(line);
    return (0);
}

