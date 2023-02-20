#include "shell.h"

/**
 * remove_alias - remove node with key from linked list
 * @head: first node
 * @key: token key of node to remove
 *
 * Return: 0 on sucess -1 on faliure
 */

int remove_alias(alias **head, char *key)
{
	alias *_head, *tmp;

	if (!*head)
		return (-1);

	if (!_strcmp((*head)->key, key))
	{
		_head = *head;
		*head = (*head)->next;
		free(_head->key);
		free(_head->value);
		free(_head);
		return (0);
	}
	_head = *head;
	while (_head->next)
	{
		if (!_strcmp(_head->next->key, key))
		{
			tmp = _head->next;
			_head->next = _head->next->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
		_head = _head->next;
	}

	return (0);
}
