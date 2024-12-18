#include <stdio.h>
#include <stdlib.h>

int	my_atoi(char *str)
{
	int sum = 0;
	unsigned int i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return sum;
}

int	get_max(char *str)
{
	int a = -1;
	int max = -1;
	
	while (*str)
	{
		//if a delimeter move to number
		if (*str == '-' || *str == ' ')
			str++;

		//set new max value
		a = my_atoi(str);
		if (a > max)
			max = a;

		//moving to next next delimiter
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return max;
}

void	populate_matrix(int **adjacency_matrix, int max, char *s)
{
	int a = -1;
	int b = -1;

	while (*s)
	{
		if (a == -1)
			a = my_atoi(s);
		else if (b == -1)
			b = my_atoi(s);

		while (*s >= '0' && *s <= '9')
			s++;
		if (*s == '-' || *s == ' ')
			s++;

		if (a != -1 && b != -1)
		{
			adjacency_matrix[a][b] = 1;
			adjacency_matrix[b][a] = 1;
			a = -1;
			b = -1;
		}
	}
}

void	print_matrix(int **adjacency_matrix, int max)
{
	for (int y = 0; y < max; y++)
	{
		for (int x = 0; x < max; x++)
			printf("%d ", adjacency_matrix[y][x]);
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	printf("digit: %d\n", my_atoi("501249"));
	printf("max: %d\n", get_max(argv[1]));

	int max = get_max(argv[1]) + 1;

	int a = -1;
	int b = -1;
	int adjacency_matrix[max][max];

	for (int y = 0; y < max; y++)
	{
		for (int x = 0; x < max; x++)
			adjacency_matrix[y][x] = 0;
	}

	char *s = argv[1];

	while (*s)
	{
		if (a == -1)
			a = my_atoi(s);
		else if (b == -1)
			b = my_atoi(s);

		//loop over numbers and delimiters if possible
		while (*s >= '0' && *s <= '9')
			s++;
		if (*s == '-' || *s == ' ')
			s++;

		//if both items are parsed set them in the matrix
		if (a != -1 && b != -1)
		{
			adjacency_matrix[a][b] = 1;
			adjacency_matrix[b][a] = 1;
			a = -1;
			b = -1;
		}
	}

	print_matrix(adjacency_matrix, max);
}