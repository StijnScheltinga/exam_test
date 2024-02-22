#include <stdlib.h>
#include <stdio.h>

/* This program takes the integers it is given 
and puts it in a binary search tree */

typedef struct treenode
{
	int				value;
	struct treenode	*left;
	struct treenode	*right;
} treenode;

int	int_check(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	res = 0;
	int	neg = 1;
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

treenode	*create_treenode(int value)
{
	treenode	*node = malloc(sizeof(treenode));
	if (node != NULL)
	{
		node->left = NULL;
		node->right = NULL;
		node->value = value;
	}
	return (node);
}

void	insert_node(treenode **rootptr, int value)
{
	if (*rootptr == NULL)
		*rootptr = create_treenode(value);
	else if (value < (*rootptr)->value)
		insert_node(&((*rootptr)->left), value);
	else if (value > (*rootptr)->value)
		insert_node(&((*rootptr)->right), value);	
}

void	create_tree(treenode **root, int argc, char **argv)
{
	treenode	*node;
	int			value;
	for (int i = 1; i < argc; i++)
	{
		value = ft_atoi(argv[i]);
		printf("value %d\n", value);
		insert_node(root, value);
	}
}

int	search_value(treenode *root, int value)
{
	if (root == NULL)
		return (0);
	if (root->value == value)
		return (1);
	if (value < root->value)
		return (search_value(root->left, value));
	else
		return (search_value(root->right, value));
}

int count_nodes(treenode *root)
{
	if (root == NULL)
		return (0);
	else
		return (1 + count_nodes(root->left) + count_nodes(root->right));
}

int	height(treenode *root)
{
	if (root == NULL)
		return (0);
	else
	{
		int heightright = height(root->right);
		int heightleft = height(root->left);
		if (heightright > heightleft)
			return (1 + heightright);
		else
			return (1 + heightleft);
	}
}

void	print_tree(treenode *root)
{
	if (root == NULL)
		printf("empty\n");
	else
	{
		printf("%d\n", root->value);
		print_tree(root->left);
		print_tree(root->right);
	}
}

int main(int argc, char **argv)
{
	treenode	*root = NULL;
	if (int_check(argc, argv))
		return (1);
	create_tree(&root, argc, argv);
	printf("N nodes: %d\n", count_nodes(root));
	printf("max height: %d\n", height(root));
	// if (search_value(root, 12))
	// 	printf("number found\n");
	// print_tree(root);
	return (0);
}