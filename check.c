/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:38:27 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 12:09:01 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len -1] != 'r')
		return (0);
	if (str[len -2] != 'e')
		return (0);
	if (str[len -3] != 'b')
		return (0);
	if (str[len -4] != '.')
		return (0);
	return (1);
}

int	ft_lentab2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_same(int *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[0] != str[j])
			return (0);
		j++;
	}
	return (1);
}

int	ft_rect(char **tab)
{
	int	*str;
	int	i;
	int	j;

	str = malloc(sizeof(int) * ft_lentab2(tab) + 1);
	i = 0;
	j = 0;
	while (tab[i])
	{
		str[j] = ft_strlen(tab[i]);
		i++;
		j++;
	}
	str[j] = '\0';
	if (!ft_same(str))
	{
		free (str);
		return (0);
	}
	return (1);
}
