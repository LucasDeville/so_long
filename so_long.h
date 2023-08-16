/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:16:15 by ldeville          #+#    #+#             */
/*   Updated: 2023/05/31 15:22:41 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>

typedef struct s_sprite
{
	void	*ptr;
	char	*pixels;
	int		bpp;
	int		size;
	int		endian;
	int		x;
	int		y;
}	t_sprite;

typedef struct s_monster
{
	int	x;
	int	y;
}	t_monster;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	int			winx;
	int			winy;
	t_sprite	*img;
	t_monster	*monster;
	char		**map;
	int			step;
	int			display;
	int			side;
	int			speed;
	int			collect;
	int			end;
}	t_mlx;

typedef struct s_pos
{
	char		c;
	int			x;
	int			y;
}	t_pos;

void		ft_steps(t_mlx *mlx, int color, char *steps);
char		*ft_strjoin_sl(char *s1, char *s2);
char		**ft_getmap(char *nfile);
int			ft_countline(char *buff);
int			ft_checkmap(char **map);
void		ft_destroy(t_mlx *mlx);
int			ft_mapisplayable(char **map);
t_pos		ft_pos(char **map, char c);
char		**ft_testmap(char **map);
int			ft_check_ber(char *file);
int			ft_ylen(char **map);
t_sprite	*ft_init_sprite(t_mlx mlx);
void		ft_launch(t_mlx mlx, char **map);
int			ft_update(t_mlx *mlx);
void		ft_move(t_mlx *mlx, int mx, int my);
int			ft_check_collect(char **map);
void		ft_create_monster(t_mlx *mlx);
int			ft_check_cara(char **map);
void		ft_monster_awake(t_mlx *mlx);
void		ft_monster_anim(t_mlx *mlx);
int			ft_can_block(char **map, int x, int y, int awake);
void		ft_display_defeat(t_mlx mlx, char **map);
void		ft_display_win(t_mlx mlx, char **map);
void		ft_anim_perso(t_mlx *mlx);

#endif
