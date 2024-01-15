#include "monty.h"

/**
 * is_integer - checks if string is integer
 * @str: string
 * Return: 0 if not, else 1.
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	str += 5;

	while (*str && isspace((unsigned char)*str))
	{
		str++;
	}
	while (*str && isdigit((unsigned char)*str))
	{
		str++;
	}
	return (*str == '\0' || *str == '\n' || *str == '\r');
}
