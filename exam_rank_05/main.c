#include "inf_add.h"

char *truncate_zero(char *result)
{
	char *trim = malloc((ft_strlen(result) - 1) * sizeof(char));
	int trimindex = 0;
	int i = 0;
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

//negative number always comes second
char *subtract(char *s1, char *s2)
{
	int s1len = ft_strlen(s1);
	int s2len = ft_strlen(s2);
	int maxLen = max_length(s1, s2);

	//allocate result string two more bytes then longest string, '\0' and carry over
	char *result = malloc(sizeof(char) * (maxLen + 2));
	if (!result)
		return NULL;
	else
		printf("malloced!\n");
	int i = maxLen + 1;
	result[i] = '\0';
	i--;


	//if number to be subtracted is bigger we should rearrenge the numbers and print a '-' sign at the end
	int sign = 1;

	printf("before swap, s1: %s, s2: %s\n", s1, s2);

	if (s2IsBigger(s1, s2))
	{
		write(1, "string 2 is bigger\n", 19);
		char *temp = s1;
		s1 = s2;
		s2 = temp;
		int tempi = s1len;
		s1len = s2len;
		s2len = tempi;
		sign = -1;
	}

	printf("after swap, s1: %s, s2: %s\n", s1, s2);
	//create index for both strings
	int s1index = s1len - 1;
	int s2index = s2len - 1;

	int carry = 0;
	int sum = 0;
	//start at back of both strings and calculate their sum
	while (i >= 0)
	{
		//calulate sum of the two characters
		int digit1 = s1index >= 0 ? s1[s1index] - '0' : 0;
		int digit2 = s2index >= 0 ? s2[s2index] - '0' : 0;
		sum = digit1 - digit2 - carry; // sum = digit1 - digit2 - carry
		if (sum < 0)
		{
			carry = 1;
			sum += 10;
		}
		else
			carry = 0;
		result[i] = sum + '0';
		i--;
		s1index--;
		s2index--;
	}
	// return truncate_zero(result);
	if (sign == -1)
		write(1, "-", 1);
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

	char sign1 = string1[0];
	char sign2 = string2[0];

	char *result;

	if (sign1 == '-' && sign2 == '-')
	{
		result = add(&string1[1], &string2[1]);
		printf("result: -%s\n", result);	
	}
	else if (sign1 == '-' && sign2 != '-')
	{
		printf("first number is negative\n");
		result = subtract(string2, &string1[1]);
		printf("%s\n", result);
	}
	else if (sign1 != '-' && sign2 == '-')
	{
		printf("second number is negative\n");
		result = subtract(string1, &string2[1]);
		printf("%s\n", result);
	}
	else
	{
		result = add(string1, string2);
		printf("result: %s\n", result);
	}

	free(result);
	// result = subtract("9999234", "-99999");
	// printf("result: %s\n", result);
}