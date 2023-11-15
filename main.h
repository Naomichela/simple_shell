#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/**
 * parse_line - Parses a line into an array of strings.
 * @line: The input line to parse.
 * Return: An array of strings.
 */
char **parse_line(char *line);

/**
 * execute_command - Executes a command with arguments.
 * @command: The command to execute.
 * @argv: Array of arguments.
 * Return: Exit status of the command.
 */
int execute_command(char *command, char **argv);

/**
 * custom_putchar - Outputs a character to the standard output.
 * @ch: The character to output.
 * Return: Number of characters written.
 */
int custom_putchar(char ch);

/**
 * prompt - Displays the command prompt.
 */
void prompt(void);

/**
 * custom_puts - Outputs a string to the standard output.
 * @str: The string to output.
 */
void custom_puts(char *str);

/**
 * custom_strlen - Calculates the length of a string.
 * @str: The input string.
 * Return: Length of the string.
 */
size_t custom_strlen(const char *str);

/**
 * handle_error - Handles error conditions and exits.
 * @message: The error message to display.
 */
void handle_error(const char *message);

/**
 * handle_other_errors - Handles other error conditions.
 */
void handle_other_errors(void);

/**
 * custom_strcmp - Compares two strings.
 * @str1: The first string.
 * @str2: The second string.
 * Return: 0 if strings are equal, an integer less than/greater than 0 otherwise.
 */
int custom_strcmp(const char *str1, const char *str2);

/**
 * custom_memcpy - Copies memory from source to destination.
 * @dest: Destination memory.
 * @src: Source memory.
 * @n: Number of bytes to copy.
 * Return: A pointer to the destination memory.
 */
void *custom_memcpy(void *dest, const void *src, size_t n);

/**
 * execute_child_process - Executes a child process.
 * @argv: Array of arguments.
 */
void execute_child_process(char **argv);

/**
 * custom_atoi - Converts a string to an integer.
 * @str: The input string.
 * Return: The converted integer.
 */
int custom_atoi(const char *str);

#endif

