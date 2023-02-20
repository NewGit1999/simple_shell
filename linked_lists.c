#include "shell.h"

/**
 * add_node - add new node at the end of command list
 * @head: pointer to pointer of first node
 * @cmd: command
 * @op: command delimiter
 *
 * Return: 0 on sucess -1 on failure
 */

int add_node(cmdnode **head, char *cmd, char *op)
{
	cmdnode *newNode = _malloc(sizeof(cmdnode));
	cmdnode *current;

	if (!head)
		return (-1);

	newNode->cmd = _strdup(cmd);
	newNode->op = _strdup(op);
	newNode->estat = 0;
	newNode->next = NULL;
	if (!*head)
		*head = newNode;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;

		current->next = newNode;
	}
	return (0);
}

/**
 * build_list - build command list
 * @cmds: command to be added
 * Return: pointer to first node
 */

cmdnode *build_list(char *cmds)
{
	char **parsedcmd = NULL, **tmp = NULL, **_parsedcmd = NULL;
	cmdnode *head = NULL, *_head = NULL, *tmp2 = NULL, *current, *previous = NULL;
	int len, i = 0;

	parse_args(cmds, "||", &parsedcmd, 1), _parsedcmd = parsedcmd;
	len = _arlen(parsedcmd);
	if (len > 0)
	{
		while (*_parsedcmd)
			add_node(&head, *_parsedcmd, (len > 1) ? "||" : ""), _parsedcmd++;
		free_pp(parsedcmd), _head = head;
		while (_head)
		{
			parse_args(_head->cmd, "&&", &tmp, 1), len = _arlen(tmp);
			if (len > 1)
			{
				i = 0;
				while (tmp[i])
					add_node(&tmp2, tmp[i], "&&"), i++;
				current = _head->next;
				if (previous)
					previous->next = tmp2;
				else
					head = tmp2;
				while (tmp2->next)
				{
					if (!(tmp2->next->next))
						previous = tmp2;
					tmp2 = tmp2->next;
				}
				tmp2->next = current, free(tmp2->op), tmp2->op = _strdup(_head->op);
				free(_head->cmd), free(_head->op), free(_head), _head = tmp2, tmp2 = NULL;
			}
			else
				previous = _head, _head = _head->next;
			free_pp(tmp);
		}
		free(previous->op), previous->op = _strdup("");
	}
	return (head);
}

/**
 * print_nodes - print contents of a linked list
 * @head: first node
 * Return: 0 on sucess -1 on faliure
 */

int print_nodes(cmdnode *head)
{
	if (!head)
		return (-1);

	while (head)
	{
		_write(-1, NULL, 0);
		_write(1, "cmd ", 4);
		_write(1, head->cmd, _strlen(head->cmd));
		_write(1, ", op '", 6);
		_write(1, head->op, _strlen(head->op));
		_write(1, "'\n", 2);
		_write(1, NULL, 0);
		head = head->next;
	}
	return (0);
}

/**
 * free_list - frees a cmdnode list
 * @head: first node
 */

void free_list(cmdnode *head)
{
	cmdnode *tmp;

	if (!head)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->cmd);
		free(tmp->op);
		free(tmp);
	}
	head = NULL;
}

/**
 * add_node_index - add node at the end of list
 * @head: pointer to pointer of first node
 * @cmd: arguments to add
 * @operator: delimiter
 * @pos: index to add node
 *
 * Return: pointer to node
 */

cmdnode *add_node_index(cmdnode **head, char *cmd, char *operator, int pos)
{
	cmdnode *newNode = _malloc(sizeof(cmdnode));
	cmdnode *current = NULL, *tmp = NULL;
	int i = 1;

	if (!head)
		return (NULL);

	newNode->cmd = cmd;
	newNode->op = operator;
	newNode->next = NULL;
	if (!*head)
		*head = newNode;
	else
	{
		current = *head;
		while (current->next && i < pos)
			current = current->next, i++;

		tmp = current->next;
		current->next = newNode;
		newNode->next = tmp;
	}
	return (newNode);
}
