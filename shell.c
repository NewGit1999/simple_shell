#include "shell.h"
#include <stdio.h>

static void handlerc(int);
void mv_cmd(cmdnode **, int);
int exec_cmd(char **, int, alias **);

/**
 * main - entry point for simple shell
 * @argc: argument counter
 * @argv: argument vector
 * @argp: env variables
 *
 * Return: always 0
 */

int main(int argc, char **argv, char **argp)
{
	char *cmd = NULL, **cmds = NULL;
	size_t cmdlen = 0;
	int mode = !isatty(0), i = 0, cmdnum = 1, inputs = 0, ret;
	alias *head = NULL;

	print_error(argv[0], &inputs, NULL);
	environ = _arrdup(argp);
	if (argc > 1)
	{
		ret = runscript(argv[1]);
		free_pp(environ);
		exit(ret);
	}
	signal(SIGINT, handlerc);
	while (1)
	{
		cmd = NULL, cmds = NULL, get_input(&cmd, &cmdlen, &cmds, 0);
		cmdnum = _arlen(cmds), i = 0;
		free(cmd);
		inputs++;
		while (i < cmdnum)
			ret = exec_cmd(cmds, i, &head), i += 1;
		if (cmdnum > 0)
			free_pp(cmds);
		if (mode)
		{
			free_pp(environ), freealias(head);
			return (ret);
		}
	}
	free_pp(environ), freealias(head);
	return (ret);
}

/**
 * handlerc - handlce SIGNUM
 * @signum: sig ID
 */

static void handlerc(int signum)
{
	write(1, "\n$ ", 3);
	(void)signum;
}

/**
 * mv_cmd - move to next command in list
 * @head: first node
 * @childstat: status of command executed
 *
 * Return: none
 */

void mv_cmd(cmdnode **head, int childstat)
{
	cmdnode *tmp = NULL;

	if (!_strcmp((*head)->op, "||"))
	{
		if (!childstat)
		{
			free((*head)->op);
			(*head)->op = (*head)->next->op;

			tmp = (*head)->next->next;

			free((*head)->next->cmd);
			free((*head)->next);
			(*head)->next = tmp;
			(*head)->estat = 1;
		}
		else
			(*head) = (*head)->next;

	}
	else if (!_strcmp((*head)->op, "&&"))
	{
		if (!childstat)
			(*head)->estat = 1, (*head) = (*head)->next;
		else
		{
			while ((*head))
			{
				if (!((*head)->next))
				{
					*head = (*head)->next;
					break;
				}
				if (!_strcmp((*head)->next->op, "||"))
				{
					(*head) = (*head)->next;
					break;
				}
				*head = (*head)->next;
			}
		}
	}
	else
		(*head) = (*head)->next;
}

/**
 * exec_cmd - execute command
 * @cmd_l: commands
 * @index: current command index
 * @aliashead: head of the laias list
 *
 * Return: 0 or exit status
 */

int exec_cmd(char **cmd_l, int index, alias **aliashead)
{
	char **tmp = NULL, *cmds = cmd_l[index];
	int childid, *binstat;
	static int childstat, exitstat;
	cmdnode *head = NULL, *_head = NULL, *tmp_n = NULL;

	write_history(cmds);
	_head = build_list(cmds), head = _head;
	while (head)
	{
		xpnd_str(&(head->cmd), exitstat);
		xpnd_alias(&(head->cmd), *aliashead);
		parse_args(head->cmd, " ", &tmp, 0);
		binstat = handle_bin(tmp, aliashead);
		if (!binstat[0])
		{
			if (binstat[1] != 266)
			{
				exitstat = binstat[1];
				free_pp(environ), free(binstat), free_pp(tmp);
				free_pp(cmd_l), free_list(_head), freealias(*aliashead);
				exit(exitstat);
			}
			mv_cmd(&head, 0), free(binstat);
			continue;
		}
		free(binstat);
		if (head->estat == 0)
		{
			childid = fork();
			if (childid < 0)
			{
				print_error(NULL, NULL, "Coudn't create a child proccess");
				exit(127);
			}
			if (childid == 0)
			{
				childstat = execute(tmp);
				free_pp(environ), freealias(*aliashead);
				free_pp(tmp), free_pp(cmd_l), free_list(_head);
				exit(childstat);
			}
			else
			{
				wait(&childstat);
				if (WIFEXITED(childstat))
					exitstat = WEXITSTATUS(childstat);
				mv_cmd(&head, exitstat);
			}
		}
		else if (head->estat == 1)
		{
			if (!_strcmp(head->op, "||"))
			{
				free(head->op);
				head->op = head->next->op;
				tmp_n = head->next->next;
				free(head->next->cmd);
				free(head->next);
				head->next = tmp_n;
			}
			else
				head = head->next;
		}
		free_pp(tmp);
	}
	free_list(_head);
	return (exitstat);
}
