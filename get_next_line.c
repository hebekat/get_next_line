/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 19:26:32 by tohebeka      #+#    #+#                 */
/*   Updated: 2022/02/14 18:22:26 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>

char	*shift_pointer(char **str)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	i = 0;
	j = 0;
	k = 0;
	i = ft_strlen(*str);
	while (str[0][j] != '\n')
		j++;
	j++;
	ret = malloc(i - j + 1);
	while (k < i - j)
	{
		ret[k] = str[0][k + j];
		k++;
	}
	ret[k] = 0;
	free(*str);
	return (ret);
}

void	shift_array(char str[])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	i = ft_strlen(str);
	while (str[j] != '\n')
		j++;
	j++;
	while (k < i - j)
	{
		str[k] = str[k + j];
		k++;
	}
	str[k] = 0;
}

char	*output(char *next_line, int readRet)
{
	if (readRet || next_line[0])
		return (next_line);
	else
	{
		free(next_line);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*next_line;
	int				readRet;

	next_line = strdup(buf);
	while (!(contains_new_line(buf)))
	{
		readRet = read(fd, buf, BUFFER_SIZE);
		buf[readRet] = 0;
		if (readRet == -1)
			return (NULL);
		next_line = ft_strjoin(next_line, buf, readRet);
		if (readRet != BUFFER_SIZE)
			break ;
	}
	next_line = ret_good_line(next_line);
	shift_array(buf);
	return (output(next_line, readRet));
}

#include <stdio.h>
int main()
{
	int fd = open("prestige.txt", O_RDWR);
	char *next_line = (void *)1;
	int c = 0;
	char *buf;
	int more = 0;
	int arrcoord[2][2][500];
	int map[1000][1000];
	int i = 0;
	int j = 0;
	char *bufword = malloc(3);

	while((bufword = get_next_line(fd)))
	{
		printf("%s", bufword);
		i++;
	}
	
	

	//system("leaks a.out");
}