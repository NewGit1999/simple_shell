#include "shell.h"

/**
 * add_alias - add node to linked list
 * @head: first node
 * @key: key to add in node
 * @value: value to be added with the key
 *
 * Return: 0 on sucess -1 on faliure
 */

int add_alias(alias **head, char *key, char *value)
{
	alias *node, *_head;

	if (!head)
		return (-1);

	node = _malloc(sizeof(alias));
	node->key = _strdup(key);
	node->value = _strdup(value);
	node->next = NULL;
	if (!*head)
	{
		*head = node;
		return (0);
	}
	_head = *head;
	while (_head->next)
	{
		if (!_strcmp(_head->key, key))
		{
			free(_head->value);
			_head->value = _strdup(value);
			freealias(node);
			return (0);
		}
		_head = _head->next;

	}
	_head->next = node;
	return (0);
}

/**
 * print_lalias - print contents of linked list
 * @head: first node
 * Return: 0 on sucess -1 on faliure
 */

int print_lalias(alias *head)
{
	if (!head)
		return (-1);

	while (head)
	{


		_write(-1, NULL, 0);
		_write(1, head->key, _strlen(head->key));
		_write(1, "='", 2);
		_write(1, head->value, _strlen(head->value));
		_write(1, "'\n", 2);
		_write(1, NULL, 0);

		head = head->next;
	}
	return (0);
}
/**
 * print_alias - print contents of a node whose key is key
 * @head: first node
 * @key: key of node to be printed
 *
 * Return: 0 on sucess -1 on faliure
 */
int print_alias(alias *head, char *key)
{
	char *msg, *smn;

	if (!head)
	{
		errno = -5;
		msg = _malloc(_strlen("not found ") + _strlen(key) + 4);
		_strcpy(msg, "not found ");
		smn = _malloc(_strlen("alias: ") + _strlen(key) + 4);
		_strcpy(smn, "alias: "), _strcat(smn, key);
		print_error(smn, NULL, msg);
		free(msg), free(smn);
		return (-1);
	}

	while (head)
	{
		if (!_strcmp(head->value, key))
		{
			_write(-1, NULL, 0);
			_write(1, head->key, _strlen(head->key));
			_write(1, "='", 2);
			_write(1, head->value, _strlen(head->value));
			_write(1, "'\n", 2);
			_write(1, NULL, 0);
			return (0);
		}
		head = head->next;
	}
	errno = -3;
	msg = _malloc(_strlen("not found ") + _strlen(key) + 4);
	_strcpy(msg, "not found ");
	smn = _malloc(_strlen("alias: ") + _strlen(key) + 4);
	_strcpy(smn, "alias: "), _strcat(smn, key);
	print_error(smn, NULL, msg);
	free(msg), free(smn);
	return (-1);
}

/**
 * handle_alias - handle flags for aliases
 * @arg: arguments
 * @aliashead: first node
 *
 * Return: 0 on sucess -1 on faliure
 */

int handle_alias(char **arg, alias **aliashead)
{
	int argc = _arlen(arg);
	int i = 0;
	char **tmp = NULL;

	if (argc == 0)
		return (-1);

	if (argc == 1)
		print_lalias(*aliashead);

	if (argc > 1)
	{
		i += 1;
		while (arg[i])
		{
			parse_args(arg[i], "=", &tmp, 0);
			if (_arlen(tmp) > 1)
				add_alias(aliashead, tmp[0], tmp[1]);
			else
				print_alias(*aliashead, tmp[0]);
			free_pp(tmp);
			i++;
		}
	}
	return (0);
}

/**
 * freealias - free alias linked list
 * @head: first node
 * Return: 0 on sucess -1 on faliure
 */

int freealias(alias *head)
{
	alias *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = tmp;
	}
	return (0);
}
