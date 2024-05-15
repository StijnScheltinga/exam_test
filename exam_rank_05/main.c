#include "inf_add.h"

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
	while (!(i < 0))
	{

		
		i--;
		s1index--;
		s2index--;
	}

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

	

	// char *result;

	// result = add("99999", "99999");
	// printf("result: %s\n", result);

	// result = subtract("9999234", "-99999");
	// printf("result: %s\n", result);
}