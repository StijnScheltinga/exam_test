#include "inf_add.h"

int ft_strlen(char *string)
{
	int i = 0;
	while (string[i])
		i++;
	return i;
}

int max_length(char *s1, char *s2)
{
	//calulate the longest string
	int s1len = ft_strlen(s1);
	int s2len = ft_strlen(s2);
	int maxLen = s1len > s2len ? s1len : s2len;
	// printf("max len: %d\n", maxLen);
	return maxLen;
}

int	check_neg(char *str)
{
	if (str[0] == '-')
	{
		str[0] = '0';
		return -1;
	}
	return 1;
}

//returns 1 if s2 is bigger else if s1 is bigger or equal to s2 it returns 0
int	s2IsBigger(char *s1, char *s2)
{
	int s1len = ft_strlen(s1);
	int s2len = ft_strlen(s2);

	if (s2len > s1len)
		return 1;
	else if (s1len == s2len)
	{
		int s1index = s1len -1;
		int s2index = s2len -1;
		while (s1index >= 0 && s2index >= 0)
		{
			if (s2[s2index] - '0' > s1[s1index] - '0')
				return 1;
			s1index--;
			s2index--;
		}
		return 0;
	}
	else
		return 0;
}

char *trimZeros(char *result)
{
	int zero_n = 0;
	for (int i = 0; result[i] && result[i] == '0'; i++)
		zero_n++;
	int trim_size = ft_strlen(result) - zero_n;
	// printf("trim size: %d, zero_n: %d\n", trim_size, zero_n);
	char *trim = malloc(sizeof(char) * (trim_size + 1));
	if (!trim)
	{
		printf("memory allocation failed\n");
		return NULL;
	}
	trim[trim_size] = '\0';
	for (int j = 0; j < trim_size; j++)
	{
		// printf("trim[j]: %c, result[j + zero_n]: %c\n", trim[j], result[j + zero_n]);
		trim[j] = result[j + zero_n];
	}
	free(result);
	// printf("trim: |%s|\n", trim);
	return trim;
}

// char *determine_big_number(char *s1, char *s2)
// {
// 	int s1len = ft_strlen(s1);
// 	int s2len = ft_strlen(s2);

// 	if (s1len == s2len)
// 	{
// 		for (int i = 0; i < s1len; i++)
// 		{
// 			if (s1[i] > s2[i])
// 				return s1;
// 			else if (s2[i] > s1[i])
// 				return s2;	
// 		}
// 		return NULL;
// 	}
// 	else if (s1len > s2len)
// 		return s1;
// 	else
		
// }