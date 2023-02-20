#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdlib.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_t 1024

/**
 * struct cmdnode - a node for one command in a command list
 * @cmd: command string
 * @op: operation between current command and next command
 * @estat: exit status (shows if the command has been excuted or not)
 * @next: a pointer to the next operand
 */

typedef struct cmdnode
{
	char *cmd;
	char *op;
	int estat;
	struct cmdnode *next;
} cmdnode;

/**
 * struct alias - a node for one alias
 * @key: the alais
 * @value: value of the alias
 * @next: a pointer to the next alias
 */

typedef struct alias
{
	char *key;
	char *value;
	struct alias *next;
} alias;


void mv_cmd(cmdnode **, int);
int exec_cmd(char **, int, alias **);


char *get_file_path(char *);
void parse_args(char *, const char *, char ***, int);
int get_input(char **, size_t *, char ***, int);
void trim_spaces(char **, char *);

int *handle_bin(char **, alias **);

void free_pp(char **);
int _arlen(char **);
void *_malloc(unsigned int);
void *_realloc(void *, unsigned int);

char **_arrdup(char **);
void printdp(char **);

int _getline(char **, size_t *, int);
int _strcmpd(char *, const char *);
char *_strtok(char *, const char *, int);
int _strcmps(char *, const char *);

int find_tok_occ(char *, char *);
int find_n_rep(char **, char *, char *);

int _strlen(const char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);
char *_strcpy(char *, char *);

int _putenv(char *);
int _setenv(const char *, const char *, int);
int _unsetenv(const char *);
char *_getenv(const char *);
void _printenv(void);

int _chdir(char *);
int runscript(char *);
int execute(char **);

int xpnd_str(char **, int);

int add_alias(alias **, char *, char *);
int print_lalias(alias *);
int print_alias(alias *, char *);
int handle_alias(char **, alias **);
int freealias(alias *);

void xpnd_alias(char **, alias *);

int remove_alias(alias **, char *);

int add_node(cmdnode **, char *, char *);
cmdnode *build_list(char *);
int print_nodes(cmdnode *);
void free_list(cmdnode *);
cmdnode *add_node_index(cmdnode **, char *, char *, int);

int pow_b(unsigned int base, int power);
int num_len(unsigned int num);
char *itoa(int);
int _atoi(char *);

void print_help(char *arg);

int print_history(void);
int write_history(char *);

int _write(int, char *, int);

void print_error(char *, int *, char *);

extern char **environ;

#endif
