/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 17:15:13 by tohebeka      #+#    #+#                 */
/*   Updated: 2021/11/26 14:11:50 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	contains_new_line(char *buf)
{
	int	i;

	i = 0;
	while (i < ft_strlen(buf))
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ret_good_line(char *remainder)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (remainder[i] != '\n' && remainder[i])
		i++;
	i++;
	ret = malloc (i + 1);
	while (j < i)
	{
		ret[j] = remainder[j];
		j++;
	}
	ret[j] = 0;
	free (remainder);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2, int readRet)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
		i++;
	ret = malloc(i + readRet + 1);
	while (j < i)
	{
		ret[j] = s1[j];
		j++;
	}
	while (k < readRet && s2[k])
	{
		ret[j] = s2[k];
		j++;
		k++;
	}
	ret[j] = 0;
	free(s1);
	return (ret);
}
