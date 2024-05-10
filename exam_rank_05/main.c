#include "inf_add.h"

void	add(char *s1, char *s2)
{
	int s1len = ft_strlen(s1);
	int s2len = ft_strlen(s2);
	int maxLen = s1len > s2len ? s1len : s2len;
	printf("max len: %d\n", maxLen);
	
}

int main()
{
	add("91578", "123897");
}