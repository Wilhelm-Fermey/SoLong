/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:03:46 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 15:23:53 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checktab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_lentab2(tab))
	{
		j = 0;
		while (j < ft_strlen(tab[i]))
		{
			if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != 'C'
					&& tab[i][j] != 'P' && tab[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_close_free(t_program *prog)
{
	int	i;

	i = 0;
	while (i < len_tab2(prog))
	{
		free (prog->map[i]);
		i++;
	}
	mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	exit (0);
}
