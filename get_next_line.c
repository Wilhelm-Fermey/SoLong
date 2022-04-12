/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:21:22 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/04/08 13:13:44 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	res;
	static char	buff[2];
	char		*str;

	str = NULL;
	if (res == 0)
	{
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	if (res > 0 && buff[0] != '\0')
		str = ft_read(fd, buff, str, res);
	else
		return (NULL);
	return (str);
}

char	*ft_read(int fd, char *buff, char *str, int res)
{
	while (res > 0 && ft_strchr(str, '\n'))
	{
		str = ft_strjoin(str, buff);
		res = read(fd, buff, 1);
		buff[res] = '\0';
	}
	return (str);
}
