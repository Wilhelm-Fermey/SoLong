/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:06:20 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 13:08:22 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_program *prog, int *count)
{
	if (prog->map[prog->p_pos.y -1][prog->p_pos.x] == '0'
		|| prog->map[prog->p_pos.y -1][prog->p_pos.x] == 'C'
		|| prog->map[prog->p_pos.y -1][prog->p_pos.x] == 'E')
	{
		if (prog->map[prog->p_pos.y -1][prog->p_pos.x] != 'E')
		{
			prog->map[prog->p_pos.y][prog->p_pos.x] = '0';
			prog->map[prog->p_pos.y -1][prog->p_pos.x] = 'P';
			*count = *count +1;
		}
		else
		{
			if (! count_tab(prog, 'C'))
			{
				prog->map[prog->p_pos.y][prog->p_pos.x] = '0';
				prog->map[prog->p_pos.y -1][prog->p_pos.x] = 'P';
				*count = *count +1;
				ft_close_free(prog);
			}
		}
	}
}

void	ft_move_down(t_program *prog, int *count)
{
	if (prog->map[prog->p_pos.y +1][prog->p_pos.x] == '0'
		|| prog->map[prog->p_pos.y +1][prog->p_pos.x] == 'C'
		|| prog->map[prog->p_pos.y +1][prog->p_pos.x] == 'E')
	{
		if (prog->map[prog->p_pos.y +1][prog->p_pos.x] != 'E')
		{
			prog->map[prog->p_pos.y][prog->p_pos.x] = '0';
			prog->map[prog->p_pos.y +1][prog->p_pos.x] = 'P';
			*count = *count +1;
		}
		else
		{
			if (! count_tab(prog, 'C'))
			{
				prog->map[prog->p_pos.y][prog->p_pos.x] = '0';
				prog->map[prog->p_pos.y +1][prog->p_pos.x] = 'P';
				*count = *count +1;
				ft_close_free(prog);
			}
		}
	}
}

void	ft_move_left(t_program *prog, int *count)
{
	if (prog->map[prog->p_pos.y][prog->p_pos.x -1] == '0'
		|| prog->map[prog->p_pos.y][prog->p_pos.x -1] == 'C'
		|| prog->map[prog->p_pos.y][prog->p_pos.x -1] == 'E')
	{
		if (prog->map[prog->p_pos.y][prog->p_pos.x -1] != 'E')
		{
			prog->map[prog->p_pos.y][prog->p_pos.x] = '0';
			prog->map[prog->p_pos.y][prog->p_pos.x -1] = 'P';
			*count = *count +1;
		}
		else
		{
			if (! count_tab(prog, 'C'))
			{
				prog->map[prog->p_pos.y][prog->p_pos.x] = '0';
				prog->map[prog->p_pos.y][prog->p_pos.x -1] = 'P';
				*count = *count +1;
				ft_close_free(prog);
			}
		}
	}
}

void	ft_move_right(t_program *prog, int *count)
{
	if (prog->map[prog->p_pos.y][prog->p_pos.x +1] == '0'
		|| prog->map[prog->p_pos.y][prog->p_pos.x +1] == 'C'
		|| prog->map[prog->p_pos.y][prog->p_pos.x +1] == 'E')
	{
		if (prog->map[prog->p_pos.y][prog->p_pos.x +1] != 'E')
		{
			prog->map[prog->p_pos.y][prog->p_pos.x] = '0';
			prog->map[prog->p_pos.y][prog->p_pos.x +1] = 'P';
			*count = *count +1;
		}
		else
		{
			if (! count_tab(prog, 'C'))
			{
				prog->map[prog->p_pos.y][prog->p_pos.x] = '0';
				prog->map[prog->p_pos.y][prog->p_pos.x +1] = 'P';
				*count = *count +1;
				ft_close_free(prog);
			}
		}
	}
}

int	deal_key(int key, t_program *prog)
{
	static int	count;

	mlx_clear_window(prog->mlx_ptr, prog->win_ptr);
	if (key == 13)
		ft_move_up(prog, &count);
	else if (key == 1)
		ft_move_down(prog, &count);
	else if (key == 0)
		ft_move_left(prog, &count);
	else if (key == 2)
		ft_move_right(prog, &count);
	ft_tab_print(prog);
	ft_putnbr(count);
	write(1, "\n", 1);
	if (key == 53)
		ft_close_free(prog);
	return (0);
}
