#include "shell.h"
#define l(x) _strlen((x))
#define cch const char

/**
 * _putenv - write to env variables
 * @es: env var value arg pair
 * Return: 0 on success and -1 on faliure
 */

int _putenv(char *es)
{
	char **_environ = environ, **newenviron, **_newenviron;
	int len = 0;

	while (*_environ)
		len++, _environ++;

	newenviron = _malloc(sizeof(char *) * (len + 4));
	_newenviron = newenviron;
	_environ =  environ;
	while (len)
	{
		*_newenviron = _malloc(sizeof(char) * _strlen(*_environ) + 4);
		_strcpy(*_newenviron, *_environ);
		_newenviron++, _environ++, len--;
	}
	*_newenviron = _malloc(sizeof(char) * _strlen(es) + 4);
	_strcpy(*_newenviron, es);
	free(es);
	_newenviron++;
	*_newenviron = NULL;
	free_pp(environ);
	environ = newenviron;
	return (0);
}

/**
 * _setenv - set env variables
 * @name: variable name
 * @value: value
 * @overwrite: overwrite status
 *
 * Return: 0 on success and -1 on faliure
 */

int _setenv(cch *name, cch *value, __attribute__((unused))int overwrite)
{
	char *es, **ep, *var;
	int i = 0;

	if (name == NULL || name[0] == '\0' || value == NULL)
		return (-1);

	if (environ)
	{
		ep = _arrdup(environ);
		while (ep[i])
		{

			var = _strtok(ep[i], "=", 0);
			if (!_strcmp(var, (char *)name))
			{
				free(environ[i]);
				environ[i] = _malloc(_strlen(name) + _strlen(value) + 4);
				_strcpy(environ[i], (char *)name);
				_strcat(environ[i], "=");
				_strcat(environ[i], (char *)value);
				free_pp(ep);
				return (0);
			}
			i++;
		}
		free_pp(ep);
	}
	es = _malloc(_strlen(name) + _strlen(value) + 2);
	if (es == NULL)
		return (-1);
	_strcpy(es, (char *)name), _strcat(es, "="), _strcat(es, (char *)value);
	return ((_putenv(es) != 0) ? -1 : 0);
	free(es);
}

/**
 * _unsetenv - delete env variables
 * @name: name of varaible
 * Return: 0 on success and -1 on faliure
 */

int _unsetenv(const char *name)
{
	char **ep, **sp, *var, *value;

	if (name == NULL || name[0] == '\0')
		return (-1);
	ep = _arrdup(environ);
	free_pp(environ);
	environ = _malloc(sizeof(char *));

	for (sp = ep; *sp != NULL; )
	{

		var = _strtok(*sp, "=", 0);
		if (_strcmp(var, (char *)name))
		{
			value = _strtok(NULL, "=", 0);
			_setenv(var, value, 1);
		}
		sp++;
	}
	free_pp(ep);
	return (0);
}

/**
 * _printenv - print env variables
 */

void _printenv(void)
{
	char **_env = environ;

	if (!_env)
		return;
	_write(-1, NULL, 0);
	while (*_env)
	{
		write(1, *_env, _strlen(*_env));
		write(1, "\n", 1);
		_env++;
	}
	write(1, NULL, 0);
}



/**
 * _getenv - get env variables
 * @name: name of variable
 * Return: pointer to env variables
 */

char *_getenv(const char *name)
{
	int len, i;
	const char *np;
	char **p, *cp;

	if (name == NULL || environ == NULL)
		return (NULL);
	for (np = name; *np && *np != '='; ++np)
		;
	len = np - name;
	for (p = environ; (cp = *p) != NULL; ++p)
	{
		for (np = name, i = len; i && *cp; i--)
			if (*cp++ != *np++)
				break;
		if (i == 0 && *cp++ == '=')
			return (cp);
	}
	return (NULL);
}
