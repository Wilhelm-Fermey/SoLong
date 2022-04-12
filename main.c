/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:54 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 13:14:10 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close(void)
{
	exit(0);
}

void	ft_read2(t_program *prog)
{
	prog->mlx_ptr = mlx_init();
	prog->win_ptr = mlx_new_window(prog->mlx_ptr, (prog->length * 100),
			(prog->width * 100), "Hello World");
	prog->wall_ptr = mlx_xpm_file_to_image(prog->mlx_ptr, "img/wall.xpm",
			&prog->image.x, &prog->image.y);
	prog->empty_ptr = mlx_xpm_file_to_image(prog->mlx_ptr, "img/empty.xpm",
			&prog->image.x, &prog->image.y);
	prog->chicken_ptr = mlx_xpm_file_to_image(prog->mlx_ptr, "img/chicken.xpm",
			&prog->image.x, &prog->image.y);
	prog->item_ptr = mlx_xpm_file_to_image(prog->mlx_ptr, "img/item.xpm",
			&prog->image.x, &prog->image.y);
	prog->exit_ptr = mlx_xpm_file_to_image(prog->mlx_ptr, "img/exit.xpm",
			&prog->image.x, &prog->image.y);
	ft_tab_print(prog);
	mlx_key_hook(prog->win_ptr, deal_key, prog);
	mlx_hook(prog->win_ptr, 17, 0, ft_close, 0);
	mlx_loop(prog->mlx_ptr);
}

int	ft_check2(char *res, t_program *prog)
{
	char	**tab;
	int		i;

	tab = ft_split(res, '\n');
	prog->map = tab;
	if (!ft_rect(tab))
		return (0);
	if (!ft_1(tab))
		return (0);
	i = 0;
	return (1);
}

int	ft_check(char *str, t_program *prog)
{
	char	*tmp;
	char	*res;
	int		fd;

	res = NULL;
	if (ft_strlen(str) < 4)
		return (0);
	if (!ft_ber(str))
		return (0);
	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		res = ft_strjoin(res, tmp);
		tmp = get_next_line(fd);
	}
	if (!ft_check2(res, prog))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc == 2)
	{
		if (!ft_check(argv[1], &prog))
		{
			write(1, "Error\n", 6);
			return (0);
		}	
		prog.length = ft_strlen(prog.map[0]);
		prog.width = ft_lentab2(prog.map);
		ft_read2(&prog);
	}
	else
		write(1, "Error\n", 6);
}
