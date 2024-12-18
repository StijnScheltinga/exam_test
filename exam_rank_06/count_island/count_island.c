#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX_BUF 999999

int count_lines(char *buf)
{
    int n_lines = 1;
    while(*buf)
    {
        if (*buf == '\n')
            n_lines++;
        buf++;
    }
    return n_lines;
}

char **read_file(int fd, int *max_lines)
{
	//read into buf with high predetermined value
    char buf[MAX_BUF + 1];
    int bytes_read = read(fd, buf, MAX_BUF);

	//if nothing is read from the file
    if (bytes_read == 0)
        return NULL;

    buf[bytes_read] = '\0';

    //num of lines
    *max_lines = count_lines(buf);
    printf("num of lines: %d", *max_lines);
    char **map = malloc(sizeof(char *) * *max_lines);

	//allocate lines with arbitrarily large size
	for (int y = 0; y != *max_lines; y++)
		map[y] = malloc(sizeof(char) * MAX_BUF);

    //fill in the lines of the map
    int y = 0;
    int i = 0;
    int x = 0;
    while(buf[i])
    {
        if (buf[i] == '\n')
        {
            map[y][x] = '\0';
			y++;
			x = 0;
        }
		else
		{
			map[y][x] = buf[i];
			x++;
		}
		i++;
    }
    return map;
}

void printmap(char **map, int max_lines)
{
	for (int y = 0; y < max_lines; y++)
	{
		for (int x = 0; map[y][x]; x++)
			write(1, &map[y][x], 1);
		write(1, "\n", 1);
	}
}

int	my_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void floodfill(char **map, int max_lines, int y, int x, int num)
{
	//check out of bounds or no X
	if (y < 0 || y >= max_lines || x < 0 || x >= my_strlen(map[y]))
		return ;

	//only set if has not been set yet
	if (map[y][x] == 'X')
		map[y][x] = num + '0';
	else
		return ;

	floodfill(map, max_lines, y - 1, x, num);
	floodfill(map, max_lines, y, x + 1, num);
	floodfill(map, max_lines, y, x - 1, num);
	floodfill(map, max_lines, y + 1, x, num);
}

void find_islands(char **map, int max_lines)
{
	int num = 0;
	//loop through whole map, start floodfill when X is found
	for (int y = 0; y != max_lines; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (map[y][x] == 'X')
			{
				floodfill(map, max_lines, y, x, num);
				num++;
			}
		}
	}
}

int main(int argc, char **argv)
{
    //simple input validation
    if (argc != 2)
    {
        write(1, "\n", 1);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(1, "\n", 1);
        return 1;
    }
	int max_lines = 0;

    //parse txt file into 2d char array
    char **map = read_file(fd, &max_lines);

    if (!map)
    {
        write(1, "\n", 1);
        return 1;
    }

	// printmap(map, max_lines);
	find_islands(map, max_lines);
	printmap(map, max_lines);
}