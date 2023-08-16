/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:14:05 by ldeville          #+#    #+#             */
/*   Updated: 2023/05/22 12:07:28 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_free_img(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->img[i].ptr)
	{
		mlx_destroy_image(mlx->mlx, mlx->img[i].ptr);
		i++;
	}
	free(mlx->img);
}

void	ft_destroy(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i][0])
		free(mlx->map[i++]);
	free(mlx->map[i]);
	free(mlx->map);
	ft_free_img(mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->monster);
	free(mlx->mlx);
}
