/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 17:14:58 by tohebeka      #+#    #+#                 */
/*   Updated: 2022/02/11 20:09:49 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 2147483646

// typedef struct reader{
//   	static char		*buf;
// 	static char		*remainder;
// 	char			*next_line;
// 	static int		readRet;
// } reader;

int		contains_new_line(char *buf);
char	*ft_strlcpy(const char *src, int size);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, int readRet);
char	*ret_good_line(char *remainder);
char	*get_next_line(int fd);

#endif