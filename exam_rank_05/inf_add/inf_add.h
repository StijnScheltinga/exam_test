#ifndef INF_ADD_H
# define INF_ADD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *add(char *string1, char *string2);
int		ft_strlen(char *string);
int 	max_length(char *s1, char *s2);
int		check_neg(char *string);
int		s2IsBigger(char *s1, char *s2);
char 	*trimZeros(char *result);

#endif