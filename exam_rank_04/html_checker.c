#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct html_tag
{
	char				*name;
	struct html_tag		*next;
} html_tag;

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
//if name == "img" return 1 else return 0
int	img_check(char *name)
{
	int	i = 0;

	if (ft_strlen(name) == 3 && name[0] == 'i' && name[1] == 'm' && name[2] == 'g')
		return (1);
	return (0);
}

html_tag	*create_tag(char *name)
{
	html_tag *tag = malloc(sizeof(html_tag));
	tag->name = name;
	tag->next = NULL;
	return (tag);
}

//if name == NULL, return. Name was img
void	add_tag(html_tag **head, char *name)
{
	html_tag	*tag;

	if (!name)
		return ;
	tag = create_tag(name);
	tag->next = *head;
	*head = tag;
}

//returns allocated for input starting <, NULL if name is img
char	*get_name(char *line)
{
	int 	i = 0;
	char	*ret;

	line++;
	if (*line == '/')
		line++;
	while (line[i] && line[i] != '>' && line[i] != ' ')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (line[i] && line[i] != '>')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	if (img_check(ret))
		return (NULL);
	if (ft_strlen(ret) == 0)
		return (NULL);
	return (ret);
}

void	remove_tag(html_tag **head)
{
	html_tag	*temp;

	temp = *head;
	*head = (*head)->next;
	free(temp->name);
	free(temp);
}

void	print_list(html_tag **head)
{
	html_tag	*iterate = *head;
	while (iterate != NULL)
	{
		printf("%s\n", iterate->name);
		iterate = iterate->next;
	}
}

int main(int argc, char **argv)
{
	html_tag	*head = NULL;
	char 		*line = argv[1];
	char		*name;

	if (argc != 2)
		return (1);
	while (*line)
	{
		if (line[0] == '<' && line[1] != '/')
			add_tag(&head, get_name(line));
		else if (line[0] == '<' && line[1] == '/')
		{
			if (!head)
			{
				printf("HTML is not formatted properly\n");
				return (1);
			}
			name = get_name(line);
			if (name && !(strncmp(name, head->name, ft_strlen(name))))
				remove_tag(&head);	
		}
		line++;
	}
	// print_list(&head);
	if (head)
		printf("HTML is not formatted properly\n");
	else
		printf("HTML is correct\n");
}