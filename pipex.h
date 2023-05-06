#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *s, char c);

#endif