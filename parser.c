#include "shell.h"

/**
 * parse_args - parse arguments
 * @cmd: tokenized string with arguments
 * @del: delimeter
 * @args: argument vector
 * @mod: delimeter method 0-character 1-string
 *
 * Return: none
 */

void parse_args(char *cmd, const char *del, char ***args, int mod)
{
	char *tokenized = NULL, **tmp, *trimmed_arg;
	int index = 0, i;

	*args = NULL;
	tokenized = _strtok(cmd, del, mod);
	while (tokenized != NULL)
	{
		tmp = (char **)_malloc((_arlen(*args) +  2) * sizeof(char *));
		if (!*args)
			*args = tmp;
		else
		{
			i = 0;
			while ((*args)[i])
			{
				tmp[i] = _strdup((*args)[i]);
				i++;
			}
			free_pp(*args);
			*args = tmp;
		}
		(*args)[index] = NULL;
		trimmed_arg = tokenized;
		if ((tokenized[0] == '"' && tokenized[_strlen(tokenized) - 1] == '"') ||
				(tokenized[0] == '\'' && tokenized[_strlen(tokenized) - 1] == '\''))
		{
			trimmed_arg = _strdup(tokenized + 1);
			trimmed_arg[_strlen(trimmed_arg) - 1] = '\0';
		}
		trim_spaces(&((*args)[index]), trimmed_arg);
		(*args)[index + 1] = NULL;
		if (trimmed_arg != tokenized)
			free(trimmed_arg);
		tokenized = _strtok(NULL, del, mod);
		index++;
	}
}
