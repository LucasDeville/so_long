/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:28:06 by ldeville          #+#    #+#             */
/*   Updated: 2023/06/05 14:51:57 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_move_situation(t_mlx *mlx, int mx, int my, t_pos chr)
{
	if (mlx->map[chr.y + my][chr.x + mx] == 'E' && mlx->collect <= 0)
	{
		mlx->end = 1;
		mlx->map[chr.y][chr.x] = '0';
		ft_display_win(*mlx, mlx->map);
		return (-1);
	}
	if (mlx->map[chr.y + my][chr.x + mx] == 'E')
		return (-1);
	if (mlx->map[chr.y + my][chr.x + mx] == 'C')
		mlx->collect--;
	mlx->map[chr.y][chr.x] = '0';
	mlx->map[chr.y + my][chr.x + mx] = 'P';
	mlx_put_image_to_window(mlx->mlx, mlx->window,
		mlx->img[4 + (mlx->side * 12)].ptr,
		(chr.x * 64 - (mx * 32)), (chr.y * 64 - (my * 32)));
	ft_steps(mlx, 0, "Steps : ");
	mlx->step++;
	ft_launch(*mlx, mlx->map);
	ft_steps(mlx, 11001101, "Steps : ");
	return (0);
}

void	ft_move(t_mlx *mlx, int mx, int my)
{
	t_pos	chr;

	if (mlx->end != 0)
		return ;
	chr = ft_pos(mlx->map, 'P');
	if (chr.c == 'P')
	{
		if (mlx->map[chr.y + my][chr.x + mx] == '1')
			return ;
		if (mlx->map[chr.y + my][chr.x + mx] == 'M')
		{
			mlx->end = 2;
			mlx->map[chr.y][chr.x] = '0';
			ft_display_defeat(*mlx, mlx->map);
			return ;
		}
		if (ft_move_situation(mlx, mx, my, chr) != 0)
			return ;
	}
}

int	ft_update(t_mlx *mlx)
{
	t_pos		chr;
	static int	nbr = 0;

	if (mlx->end != 0)
		return (0);
	nbr++;
	if (nbr == mlx->speed)
	{
		chr = ft_pos(mlx->map, 'P');
		if (chr.c == 'P')
		{
			ft_anim_perso(mlx);
			mlx_put_image_to_window(mlx->mlx, mlx->window,
				mlx->img[mlx->display].ptr, (chr.x * 64), (chr.y * 64));
		}
		ft_monster_anim(mlx);
		ft_monster_awake(mlx);
		nbr = 0;
	}
	return (0);
}

void	ft_put_image(t_mlx mlx, int x, int y, char **map)
{
	if (map[y][x] == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.window,
			mlx.img[2].ptr, (x * 64), (y * 64));
	else if (map[y][x] == 'M')
		mlx_put_image_to_window(mlx.mlx, mlx.window,
			mlx.img[11].ptr, (x * 64), (y * 64));
	else if (map[y][x] == 'E')
	{
		if (mlx.end == 1)
			mlx_put_image_to_window(mlx.mlx, mlx.window,
				mlx.img[3].ptr, (x * 64), (y * 64));
		else
		{
			if (mlx.collect == 0)
				mlx_put_image_to_window(mlx.mlx, mlx.window,
					mlx.img[9].ptr, (x * 64), (y * 64));
			else
				mlx_put_image_to_window(mlx.mlx, mlx.window,
					mlx.img[10].ptr, (x * 64), (y * 64));
		}
	}
}

void	ft_launch(t_mlx mlx, char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y][0])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx.mlx, mlx.window,
					mlx.img[4 + (mlx.side * 12)].ptr, (x * 64), (y * 64));
			else if (map[y][x] == '1')
				mlx_put_image_to_window(mlx.mlx, mlx.window,
					mlx.img[0].ptr, (x * 64), (y * 64));
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx.mlx, mlx.window,
					mlx.img[1].ptr, (x * 64), (y * 64));
			ft_put_image(mlx, x, y, map);
			x++;
		}
		x = 0;
		y++;
	}
}
