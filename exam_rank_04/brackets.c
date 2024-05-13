int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int 	i = 0;
	char	*str = argv[1];

	if (argc != 2)
		return (1);
	char *stack[ft_strlen(str) + 1];
	stack[ft_strlen(str)] = '';
	while (stack[i])
	while (str[i])
	{
		if (str[i] == '<')
			stack[i] = '<';
		i++;
	}
}