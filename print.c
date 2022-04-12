/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:45:44 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 13:24:14 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_e(t_program *prog, int i, int x, int y)
{
	int	j;

	i = 0;
	y = 0;
	while (i < prog->width)
	{
		j = 0;
		x = 0;
		while (j < prog->length)
		{
			if (prog->map[i][j] == 'E')
			{
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
					prog->exit_ptr, x, y);
			}
			x = x + prog->image.x;
			j++;
		}
		y = y + prog->image.y;
		i++;
	}
}

void	print_p(t_program *prog, int i, int x, int y)
{
	int	j;

	i = 0;
	y = 0;
	while (i < prog->width)
	{
		j = 0;
		x = 0;
		while (j < prog->length)
		{
			if (prog->map[i][j] == 'P')
			{
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
					prog->chicken_ptr, x, y);
				prog->p_pos.x = j;
				prog->p_pos.y = i;
			}
			x = x + prog->image.x;
			j++;
		}
		y = y + prog->image.y;
		i++;
	}
}

void	print_c(t_program *prog, int i, int x, int y)
{
	int	j;

	i = 0;
	y = 0;
	while (i < prog->width)
	{
		j = 0;
		x = 0;
		while (j < prog->length)
		{
			if (prog->map[i][j] == 'C')
			{
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
					prog->item_ptr, x, y);
			}
			x = x + prog->image.x;
			j++;
		}
		y = y + prog->image.y;
		i++;
	}
}

void	print_wall(t_program *prog, int i, int x, int y)
{
	int	j;

	i = 0;
	y = 0;
	while (i < prog->width)
	{
		j = 0;
		x = 0;
		while (j < prog->length)
		{
			if (prog->map[i][j] == '1')
			{
				mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
					prog->wall_ptr, x, y);
			}
			x = x + prog->image.x;
			j++;
		}
		y = y + prog->image.y;
		i++;
	}
}

void	ft_tab_print(t_program *prog)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	y = 0;
	while (i < prog->width)
	{
		j = 0;
		x = 0;
		while (j < prog->length)
		{
			mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
				prog->empty_ptr, x, y);
			x = x + prog->image.x;
			j++;
		}
		y = y + prog->image.y;
		i++;
	}
	print_wall(prog, i, x, y);
	print_p(prog, i, x, y);
	print_c(prog, i, x, y);
	print_e(prog, i, x, y);
}
