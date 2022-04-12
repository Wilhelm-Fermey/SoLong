/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:46:43 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 14:22:27 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_lentab(char *str, char c)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && count == 0)
		{
			count = 1;
			j++;
		}
		else if (str[i] == c)
			count = 0;
		i++;
	}
	return (j);
}

static char	*ft_str(char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((len - start + 1) * sizeof(char));
	while (start < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**str;

	str = malloc((ft_lentab(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			str[j] = ft_str(s, start, i);
			j++;
			start = -1;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
