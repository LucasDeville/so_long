/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:31:55 by ldeville          #+#    #+#             */
/*   Updated: 2023/05/31 15:22:09 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "minilibx/mlx.h"
#include "minilibx/mlx_int.h"

int	ft_close(t_mlx *mlx)
{
	ft_destroy(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_keypress(int key, t_mlx *mlx)
{
	if (key == 65362 || key == 119)
		ft_move(mlx, 0, -1);
	else if (key == 65364 || key == 115)
		ft_move(mlx, 0, 1);
	else if (key == 65361 || key == 97)
	{
		mlx->side = 1;
		ft_move(mlx, -1, 0);
	}
	else if (key == 65363 || key == 100)
	{
		mlx->side = 0;
		ft_move(mlx, 1, 0);
	}
	else if (key == 65307)
	{
		ft_destroy(mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_init(t_mlx *mlx, char *file)
{
	mlx->display = 4;
	mlx->side = 0;
	mlx->speed = 10000;
	mlx->end = 0;
	mlx->step = 0;
	mlx->map = ft_getmap(file);
	if (!mlx->map)
		return (-1);
	if (ft_checkmap(mlx->map) != 0)
		return (-1);
	if (ft_mapisplayable(mlx->map) != 0)
		return (-1);
	mlx->collect = ft_check_collect(mlx->map);
	mlx->winx = ft_strlen(mlx->map[0]) * 64;
	mlx->winy = (ft_ylen(mlx->map) * 64) + 25;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (0);
	if (ft_init(&mlx, argv[1]) != 0)
		return (-1);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		exit(EXIT_FAILURE);
	mlx.window = mlx_new_window(mlx.mlx, mlx.winx,
			mlx.winy, "Sooooooooooooooooooo long");
	if (mlx.window == NULL)
		exit(EXIT_FAILURE);
	mlx.img = ft_init_sprite(mlx);
	mlx_set_font(mlx.mlx, mlx.window,
		"-misc-fixed-bold-r-normal--20-0-100-100-c-0-iso10646-1");
	ft_create_monster(&mlx);
	ft_launch(mlx, mlx.map);
	mlx_do_key_autorepeaton(mlx.mlx);
	mlx_key_hook(mlx.window, &ft_keypress, &mlx);
	mlx_hook(mlx.window, 17, 0, &ft_close, &mlx);
	mlx_loop_hook(mlx.mlx, &ft_update, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
