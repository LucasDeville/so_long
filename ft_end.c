/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:31:49 by ldeville          #+#    #+#             */
/*   Updated: 2023/05/24 15:54:43 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_defeat(t_mlx mlx, char **map)
{
	ft_launch(mlx, map);
	mlx_string_put(mlx.mlx, mlx.window, (mlx.winx / 2) - 200,
		(mlx.winy - 10), 11111111, "You died !");
}

void	ft_display_win(t_mlx mlx, char **map)
{
	ft_launch(mlx, map);
	mlx_string_put(mlx.mlx, mlx.window, (mlx.winx / 2) - 200,
		(mlx.winy - 10), 11001101, "You win !");
}
