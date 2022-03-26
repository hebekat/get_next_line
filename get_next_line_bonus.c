/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 19:26:32 by tohebeka      #+#    #+#                 */
/*   Updated: 2021/12/16 16:35:47 by tohebeka      ########   odam.nl         */
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
	next_line = NULL;
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

int main(int argc, char **argv)
{
	// int fd = open("porco.txt", O_RDWR);
	// int fd2 = open("porco1.txt", O_RDWR);
	// int fd3 = open("porco2.txt", O_RDWR);
	//char *next_line = (void *)1;
	char *next_line = malloc(1000);
	int c = 0;
	next_line = get_next_line(-3);
	printf("----> %s", next_line);
	//printf("nextline ---> %s\n",next_line);
		
		free (next_line);
	system("leaks a.out");

}