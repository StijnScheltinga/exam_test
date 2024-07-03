#include "stdlib.h"
#include "unistd.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}

int	s2_is_bigger(char *num1, char *num2)
{
	if (ft_strlen(num2) > ft_strlen(num1))
		return 1;
	else if (ft_strlen(num2) == ft_strlen(num1))
	{
		for (int i = 0; num1[i]; i++)
		{
			if (num2[i] - '0' > num1[i] - '0')
				return 1;
			else if (num2[i] - '0' < num1[i] - '0')
				return 0;
		}
	}
	return 0;
}

char	*truncate_zeros(char *untrimmed)
{
	if (untrimmed[0] != '0')
		return untrimmed;

	char	*trimmed = malloc(sizeof(char) * ft_strlen(untrimmed));
	trimmed[ft_strlen(untrimmed) - 1] = '\0';
	for (int i = 0; i < ft_strlen(untrimmed); i++)
		trimmed[i] = untrimmed[i + 1];
	free(untrimmed);
	return (trimmed);
}

char	*add(char *num1, char *num2)
{
	int	num1len = ft_strlen(num1);
	int	num2len = ft_strlen(num2);
	int maxlen = num1len > num2len ? num1len : num2len;

	char *result = malloc(sizeof(char) * (maxlen + 2));
	int	index = maxlen + 1;
	result[index] = '\0';
	index--;
	
	int num1index = ft_strlen(num1) - 1;
	int num2index = ft_strlen(num2) - 1;

	int digit1 = 0;
	int digit2 = 0;

	int carry = 0;
	int sum = 0;

	while (index >= 0)
	{
		digit1 = num1index >= 0 ? num1[num1index] - '0' : 0;
		digit2 = num2index >= 0 ? num2[num2index] - '0' : 0;
		sum = digit1 + digit2 + carry;
		carry = sum / 10;
		sum = sum % 10;
		result[index] = sum + '0';
		index--;
		num1index--;
		num2index--;
	}
	result = truncate_zeros(result);
	return result;
}

char	*subtract(char *num1, char *num2)
{
	int sign = 1;
	if (s2_is_bigger(num1, num2))
	{
		write(1, "s2 is bigger\n", 13);
		char *temp = num2;
		num2 = num1;
		num1 = temp;
		sign = -1;
	}

	int	num1len = ft_strlen(num1);
	int	num2len = ft_strlen(num2);
	int maxlen = num1len > num2len ? num1len : num2len;

	char	*result = malloc(sizeof(char) * maxlen + 2);
	int	index = maxlen + 1;
	result[index] = '\0';
	index--;

	int num1index = ft_strlen(num1) - 1;
	int num2index = ft_strlen(num2) - 1;

	int digit1 = 0;
	int digit2 = 0;

	int carry = 0;
	int sum = 0;


	while (index >= 0)
	{
		digit1 = num1index >= 0 ? num1[num1index] - '0' : 0;
		digit2 = num2index >= 0 ? num2[num2index] - '0' : 0;
		sum = digit1 - digit2 - carry;
		if (sum < 0)
		{
			carry = 1;
			sum += 10;
		}
		else
			carry = 0;
		result[index] = sum + '0';
		index--;
		num1index--;
		num2index--;
	}
	if (sign == -1)
		write (1, "-", 1);
	result = truncate_zeros(result);
	return result;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return 1;

	char	*number1 = argv[1];
	char	*number2 = argv[2];
	char	sign1 = number1[0];
	char	sign2 = number2[0];
	char	*result;

	if (sign1 == '-' && sign2 == '-')
	{
		result = add(&number1[1], &number2[1]);
		write(1, "-", 1);
	}
	else if (sign1 == '-' && sign2 != '-')
		result = subtract(number2, &number1[1]);
	else if (sign1 != '-' && sign2 == '-')
		result = subtract(number1, &number2[1]);
	else
		result = add(number1, number2);
	write(1, result, ft_strlen(result));
	free(result);
}