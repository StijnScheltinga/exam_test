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

char **read_file(int fd)
{
    char buf[MAX_BUF + 1];
    int bytes_read = read(fd, buf, MAX_BUF);

    if (bytes_read == 0)
        return NULL;
    buf[bytes_read] == '\0';

    //num of lines
    int n_lines = count_lines(buf);
    printf("num of lines: %d", n_lines);
    char **map = malloc(sizeof(char *) * n_lines);

    //fill in the lines of the map
    int y = 0;
    int i = 0;
    int x = 0;
    while(buf[i])
    {
        if (buf[i] == '\n')
        {
            map[y] = malloc(sizeof(char) * MAX_BUF);
            
        }
    }


    return map;
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

    //parse txt file into 2d char array
    char **map = read_file(fd);

    if (!map)
    {
        write(1, "\n", 1);
        return 1;
    }
}