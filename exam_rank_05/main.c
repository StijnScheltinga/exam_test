#include "inf_add.h"

char *truncate_zero(char *result)
{
	char *trim = malloc((ft_strlen(result) - 1) * sizeof(char));
	int trimindex = 0;
	for (int i = 1; result[i]; i++)
		trim[trimindex++] = result[i];
	free(result);
	return trim;
}

/*
how to subtract numbers:
num1 = 148292 num2 = -6630982

*/


char *add(char *s1, char *s2)
{
	int maxLen = max_length(s1, s2);

	//allocate result string two more bytes then longest string, '\0' and carry over
	char *result = malloc(sizeof(char) * (maxLen + 2));
	int i = maxLen + 1;
	result[i] = '\0';
	i--;

	//create index for both strings
	int s1index = ft_strlen(s1) - 1;
	int s2index = ft_strlen(s2) - 1;

	int carry = 0;
	int sum = 0;
	//start at back of both strings and calculate their sum
	while (i >= 0)
	{
		//calulate sum of the two characters
		int digit1 = s1index >= 0 ? s1[s1index] - '0' : 0;
		int digit2 = s2index >= 0 ? s2[s2index] - '0' : 0;
		sum = digit1 + digit2 + carry; // sum = digit1 - digit2 - carry
		carry = sum / 10;
		sum = sum % 10;
		result[i] = sum + '0';
		i--;
		s1index--;
		s2index--;
	}
	if (carry != 0)
		result[0] = carry + '0';
	else
		return truncate_zero(result);
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("program requires 2 numbers\n");
		return 1;
	}
	char *string1 = argv[1];
	char *string2 = argv[2];

	char *result;

	result = add(string1, string2);
	printf("result: %s\n", result);

	free(result);
	// result = subtract("9999234", "-99999");
	// printf("result: %s\n", result);
}