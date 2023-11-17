#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

/* read/write  buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* command chaining */
#define CMD_NORM   0
#define CMD_OR     1
#define CMD_AND    2
#define CMD_CHAIN  3

/* convert_numbers */
#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2

/* 1 using system getline() */
#define USE_GETLINE  0
#define USE_STRTOK   0

#define HIST_FILE     ".simple_shell_history"
#define HIST_MAX      4096

extern char  **environ;

/**
 * struct liststr - linked singly list
 * @str: string
 * @num:field number
 * @next: next node pointed
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - pseudo arguments to pass into
 *                function
 * @environ: modifiedcopy of environ from LL
 * @alias: alias node
 * @history: history node
 * @cmd_buf: pointer address to cmd_buf, on chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @status: status return of last exec'd command
 * @env_changed: if environ was changed on
 * @env: local copy of linked list
 * @histcount: number count of history line
 * @readfd: line input from which fd is read from
 * @path: current command string path
 * @line_count: error count
 * @argc: count argument
 * @argv:string array generated arg
 * @arg: getline containing arguments generates string
 * @fname: filename program
 * @err_num: exit error code
 * @linecount_flag: countthis line of input if on
 */
typedef struct passinfo
{
	char **environ;
	list_t *alias;
	list_t *history;
	char **cmd_buf; /* pointer to cmd; chain buffer, for memory management */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int status;
	int env_changed;
	list_t *env;
	int histcount;
	int readfd;
	char *path;
	unsigned int line_count;
	int argc;
	char **argv;
	char *arg;
	char *fname;
	int err_num;
	int linecount_flag;
} info_t;

#define INFO_INIT \
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	

/**
 * struct builtin - builtin string and related function contained
 * @func: fuction
 * @type: builtin command flag
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* my_shell_loop.c */
void find_cmd(info_t *);
int find_buitin(info_t *);
int hsh(info_t *, char **);
void fork_cmd(info_t *);

/* my_tokernizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* my_string1.c */
int _putchar(char);
char *_strcpy(char *, char *);
char *_strmap(const char *);
void _puts(char *);

/*my string.c */
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
int _strlen(char *);
int _strcmp(char *, char *);

/* my_exit.c */
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);

/* my_errors.c */
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);
int _eputchar(char);
void _eputs(char *);

/* my_parser.c */
char *map_char(char *, int, int);
char *find_path(info_t *, char *, char *);
int is_cmd(info_t *, char *);

/* my_loophsh.c */
int loophsh(char **);

/* my_errors1.c */
int print_d(int, int);
int _erratoi(char *);
void remove_comments(char *);
void print_error(info_t *, char *);
char *convert_number(long int, int, int);

/* my_realloc.c */
char *_memset(char *, char,  unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* my_builtin.c */
int _mycd(info_t *);
int _myhelp(info_t *);
int _myexit(info_t *);

/* my_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* my_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* my_getline.c */
int _getline(info_t *, char **, size_t *);
ssize_t get_input(info_t *);
void sigintHandler(int);

/* my_getenv.c */
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);
char **get_environ(info_t *);

/* my_getinfo.c */
void clear_info(info_t *);
void free_info(info_t *, int);
void set_info(info_t *, char **);

/* my_environ.c */
int _myenv(info_t *);
int _myunsetenv(info_t *);
int _mysetenv(info_t *);
int populate_env_list(info_t *);
char *_getenv(info_t *, const char *);

/* my_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
size_t print_list_str(const list_t *);
void free_list(list_t **);

/* my_lists1.c */
ssize_t get_node_index(list_t *, list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char );
size_t list_len(const list_t *);
char **list_to_strings(list_t *);

/* my_vars.c */
int replace_alias(info_t *);
int replace_string(char **, char *);
int replace_vars(info_t *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);

/* my_history.c */
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int write_history(info_t *info);
char *get_history_file(info_t *info);
int renumber_history(info_t *info);

/* my_memory.c */
int bfree(void **);

#endif
