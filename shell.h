#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* this is for the buffer mode sampling */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM        0
#define CMD_OR                1
#define CMD_AND                2
#define CMD_CHAIN        3

/* for convert_number() */
#define CONVERT_LOWERCASE        1
#define CONVERT_UNSIGNED        2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE        ".simple_shell_history"
#define HIST_MAX        4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
        int num;
        char *str;
        struct liststr *next;
} state;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *                allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
        char *arg;
        char **argv;
        char *path;
        int argc;
        unsigned int line_count;
        int err_num;
        int linecount_flag;
        char *fname;
        list_t *env;
        list_t *history;
        list_t *alias;
        char **environ;
        int env_changed;
        int status;

        char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
        int cmd_buf_type; /* CMD_type ||, &&, ; */
        int readfd;
        int histcount;
} intro;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
        0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
        char *type;
        int (*func)(info_t *);
} sketch;


/* for our shell_loop.c */
int hash(info_t *, char **);
int builtfind(info_t *);
void commandfind(info_t *);
void commandfork(info_t *);

/* this is our parser.c file */
int command(info_t *, char *);
char *duplicate(char *, int, int);
char *pathfinder(info_t *, char *, char *);


/* loophsh.c */
int loophsh(char **);

/* for our errors.c file */
void lorry(char *);
int cluster(char);
int master(char lap, int fall);
int fellow(char *stranger, int fall);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* our string1.c file */
char *stringCopy(char *, char *);
char *stringDupe(const char *);
void putString(char *);
int putCharacter(char);

/* for our exit.c file */
char *stringToCopy(char *, char *, int);
char *stringConcat(char *, char *, int);
char *capum(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int isInteractive(info_t *);
int isDelimeter(char, char *);
int isAlphabetic(int);
int stringToInteger(char *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* our builtin file */
int exeat(info_t *);
int compact(info_t *);
int assist(info_t *);

/* our builtin1 file */
int history(info_t *);
int alliance(info_t *);
int seller(info_t *, char *);
int buyer(info_t *, char *);
int printer(list_t *);

/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* for our getenv.c file */
char **environmental(info_t *);
int seventy(info_t *, char *);
int unseventy(info_t *, char *, char *);

/* for our history.c file */
char *part(info_t *vine);
int writer(info_t *vine);
int reader(info_t *vine);
int builder(info_t *vine, char *bale, int counter);
int number(info_t *vine);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* for our lists1.c file */
size_t lucky(const list_t *);
char **stringList(list_t *);
size_t pointToList(const list_t *);
list_t *nodeStart(list_t *, char *, char);
ssize_t nodeIndex(list_t *, list_t *);

/* this is for our vars.c file */
int chain(info_t *, char *, size_t *);
void check(info_t *, char *, size_t *, size_t, size_t);
int alliancerep(info_t *);
int variancerep(info_t *);
int stringrep(char **, char *);

#endif
