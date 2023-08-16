/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:10 by ldeville          #+#    #+#             */
/*   Updated: 2023/05/31 16:14:43 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_monster_anim(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->monster[i].x)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->img[(7 + mlx->display - (mlx->side * 12))].ptr,
			((mlx->monster[i].x) * 64), ((mlx->monster[i].y) * 64));
		i++;
	}
}

void	ft_move_monster(t_mlx *mlx, int i, int x, int y)
{
	if (mlx->map[mlx->monster[i].y + y][mlx->monster[i].x + x] &&
		mlx->map[mlx->monster[i].y + y][mlx->monster[i].x + x] != '1' &&
		mlx->map[mlx->monster[i].y + y][mlx->monster[i].x + x] != 'C' &&
		mlx->map[mlx->monster[i].y + y][mlx->monster[i].x + x] != 'M' &&
		mlx->map[mlx->monster[i].y + y][mlx->monster[i].x + x] != 'P')
	{
		mlx->map[mlx->monster[i].y][mlx->monster[i].x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[1].ptr,
			(mlx->monster[i].x * 64), (mlx->monster[i].y * 64));
		mlx->map[mlx->monster[i].y + y][mlx->monster[i].x + x] = 'M';
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img[11].ptr,
			((mlx->monster[i].x + x) * 64), ((mlx->monster[i].y + y) * 64));
		mlx->monster[i].x = mlx->monster[i].x + x;
		mlx->monster[i].y = mlx->monster[i].y + y;
	}
}

void	ft_monster_awake(t_mlx *mlx)
{
	int			i;
	int			rd;
	t_monster	tmp;

	i = 0;
	srand(time(NULL));
	while (mlx->monster[i].x)
	{
		rd = rand() % 101;
		tmp = mlx->monster[i];
		if (rd >= 90 && mlx->map[tmp.y - 1][tmp.x]
			&& ft_can_block(mlx->map, tmp.x - 1, tmp.y, 0))
			ft_move_monster(mlx, i, -1, 0);
		else if (rd < 90 && rd >= 80 && mlx->map[tmp.y + 1][tmp.x]
			&& ft_can_block(mlx->map, tmp.x + 1, tmp.y, 0))
			ft_move_monster(mlx, i, 1, 0);
		else if (rd < 80 && rd >= 70 && mlx->map[tmp.y][tmp.x - 1]
			&& ft_can_block(mlx->map, tmp.x, tmp.y - 1, 0))
			ft_move_monster(mlx, i, 0, -1);
		else if (rd < 70 && rd >= 60 && mlx->map[tmp.y][tmp.x + 1]
			&& ft_can_block(mlx->map, tmp.x, tmp.y + 1, 0))
			ft_move_monster(mlx, i, 0, 1);
		i++;
	}
}

t_monster	*ft_add_monster(t_mlx *mlx, int nbmonster)
{
	t_monster	*monster;
	int			y;
	int			x;

	y = 0;
	x = 0;
	monster = malloc(sizeof(t_monster) * (nbmonster + 1));
	monster[nbmonster].x = 0;
	monster[nbmonster].y = 0;
	while (mlx->map[y][0])
	{
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'M')
			{
				monster[--nbmonster].x = x;
				monster[nbmonster].y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}	
	return (monster);
}

void	ft_create_monster(t_mlx *mlx)
{
	int	nbmonster;
	int	y;
	int	x;

	y = 0;
	x = 0;
	nbmonster = 0;
	srand(time(NULL));
	while (mlx->map[y][0] != 0)
	{
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == '0' && ft_can_block(mlx->map, x, y, 1)
				&& ((rand() % 101) >= 85 || nbmonster == 0))
			{
				mlx->map[y][x] = 'M';
				nbmonster++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	mlx->monster = ft_add_monster(mlx, nbmonster);
}
