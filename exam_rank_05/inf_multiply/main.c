#include "stdlib.h"
#include "stdio.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char *reverse_string(char *string)
{
	int len = ft_strlen(string);
	for (int i = 0; i < len / 2; i++)
	{
		char temp = string[i];
		string[i] = string[len - 1 - i];
		string[len - 1 - i] = temp;
	}
	return string;
}

char	*multiply(char *num1, char *num2)
{
	int	num1len = ft_strlen(num1);
	int	num2len = ft_strlen(num2);
	int	resultlen = num1len + num2len;
	int	*result = malloc(sizeof(int) * resultlen);

	//initialize result array to 0
	for (int i = 0; i != resultlen; i++)
		result[i] = 0;

	num1 = reverse_string(num1);
	num2 = reverse_string(num2);

	
	for (int i = 0; i < num1len; i++)
	{
		for (int j = 0; j < num2len; j++)
		{
			result[i + j] += (num1[i] - '0') * (num2[j] - '0');
			if (result[i + j] >= 10)
			{
				result[i + j + 1] += result[i + j] / 10;
				result[i + j] %= 10;
			}
		}
	}
	for (int i = resultlen; i >= 0; i--)
		printf("%d", result[i]);
	// int i = resultlen - 1;
	// while (i >= 0 && )
	return NULL;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return 1;
	char	*num1 = argv[1];
	char	*num2 = argv[2];
	char	sign1 = num1[0];
	char	sign2 = num2[0];
	multiply(num1, num2);
}