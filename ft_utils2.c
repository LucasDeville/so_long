/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:28:51 by ldeville          #+#    #+#             */
/*   Updated: 2023/06/05 14:17:56 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_anim_perso(t_mlx *mlx)
{
	if (mlx->side == 1)
	{
		if (mlx->display < 16)
			mlx->display = 16;
		if (mlx->display != 20)
			mlx->display++;
		else
			mlx->display = 16;
	}
	else
	{
		if (mlx->display > 8)
			mlx->display = 4;
		if (mlx->display != 8)
			mlx->display++;
		else
			mlx->display = 4;
	}
}

void	ft_steps(t_mlx *mlx, int color, char *steps)
{
	char	*step;
	char	*str;

	step = ft_itoa(mlx->step);
	str = ft_strjoin(steps, step);
	mlx_string_put(mlx->mlx, mlx->window, (mlx->winx / 2),
		(mlx->winy - 10), color, str);
	free(str);
	free(step);
}

char	*ft_strjoin_sl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	free(s1);
	return (str);
}

int	ft_can_block(char **map, int x, int y, int awake)
{
	int	block;
	int	yp;
	int	xp;

	yp = -1;
	xp = -1;
	block = 0;
	if (x == 0 || y == 0 || x == ft_strlen(map[0]) - 1 || y == ft_ylen(map) - 1)
		return (1);
	while (yp != 2)
	{
		while (xp != 2 && map[y + yp][x + xp])
		{
			if ((map[y + yp][x + xp] == '1' || map[y + yp][x + xp] == 'P'))
				block++;
			if (map[y + yp][x + xp] == 'M' && awake)
				return (0);
			xp++;
		}
		xp = -1;
		yp++;
	}
	if (block > 3)
		return (0);
	return (1);
}

int	ft_check_cara(char **map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 0;
	while (map[y][0])
	{
		while (map[y][x])
		{
			c = map[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
