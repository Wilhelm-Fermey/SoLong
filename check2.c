/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:35:00 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 15:19:18 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_colon(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(tab[0]) - 1;
	while (i < ft_lentab2(tab))
	{
		if (tab[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < ft_lentab2(tab))
	{
		if (tab[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_fulltab(char	**tab, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < ft_lentab2(tab))
	{
		j = 0;
		while (j < ft_strlen(tab[i]))
		{
			if (tab[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (c == 'C' && count)
		return (1);
	if (count == 1)
		return (1);
	else
		return (0);
}

int	ft_1(char **tab)
{
	if (!ft_line(tab[0]) || !ft_line(tab[ft_lentab2(tab) -1]))
		return (0);
	if (!ft_colon(tab))
		return (0);
	if (!ft_fulltab(tab, 'P'))
		return (0);
	if (!ft_fulltab(tab, 'E'))
		return (0);
	if (!ft_fulltab(tab, 'C'))
		return (0);
	if (!ft_checktab(tab))
		return (0);
	return (1);
}
