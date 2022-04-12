/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:46:21 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 13:03:59 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int	len_tab2(t_program *prog)
{
	int	i;

	i = 0;
	while (prog->map[i])
		i++;
	return (i);
}

int	len_str(t_program *prog)
{
	int	i;

	i = 0;
	while (prog->map[0][i])
		i++;
	return (i);
}

int	count_tab(t_program *prog, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < len_tab2(prog))
	{
		j = 0;
		while (j < len_str(prog))
		{
			if (prog->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
