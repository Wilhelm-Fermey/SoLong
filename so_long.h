/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfermey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:15:46 by wfermey           #+#    #+#             */
/*   Updated: 2022/04/12 15:26:45 by wfermey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_image
{
	int	x;
	int	y;
}				t_image;

typedef struct s_image_pos
{
	int	x;
	int	y;
}				t_p_pos;

typedef struct s_program
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*wall_ptr;
	void				*chicken_ptr;
	void				*empty_ptr;
	void				*item_ptr;
	void				*exit_ptr;
	char				**map;
	int					length;
	int					width;
	t_image				image;
	t_p_pos				p_pos;
}				t_program;

/////  MAIN  /////
void		ft_read2(t_program *prog);
int			ft_check2(char *res, t_program *prog);
int			ft_check(char *str, t_program *prog);

/////  FT_CHECK  /////
int			ft_ber(char *str);
int			ft_lentab2(char **tab);
int			ft_same(int *str);
int			ft_rect(char **tab);

/////  FT_CHECK2  /////
int			ft_line(char *str);
int			ft_colon(char **tab);
int			ft_fulltab(char **tab, char c);
int			ft_1(char **tab);

////  FT_SPLIT  /////
char		**ft_split(char *s, char c);

/////  PRINT  /////
void		print_e(t_program *prog, int i, int x, int y);
void		print_p(t_program *prog, int i, int x, int y);
void		print_c(t_program *prog, int i, int x, int y);
void		print_wall(t_program *prog, int i, int x, int y);
void		ft_tab_print(t_program *prog);

/////  HOOK  /////
void		ft_move_up(t_program *prog, int *count);
void		ft_move_down(t_program *prog, int *count);
void		ft_move_left(t_program *prog, int *count);
void		ft_move_right(t_program *prog, int *count);
int			deal_key(int key, t_program *prog);

/////  ELSE  /////
void		ft_putchar(char c);
void		ft_putnbr(int nbr);
int			len_tab2(t_program *prog);
int			len_str(t_program *prog);
int			count_tab(t_program *prog, char c);

/////  FREE  /////
void		ft_close_free(t_program *prog);
int			ft_checktab(char **tab);

#endif
