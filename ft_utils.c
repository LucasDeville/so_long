/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:14:26 by ldeville          #+#    #+#             */
/*   Updated: 2023/05/22 14:04:41 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_check_ber(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.')
		i++;
	if (file[++i] == 'b' && file[++i] == 'e' && file[++i] == 'r' && !file[++i])
		return (1);
	return (0);
}

int	ft_ylen(char **map)
{
	int	i;

	i = 0;
	while (map[i][0])
		i++;
	return (i);
}

char	**ft_testmap(char **map)
{
	int		y;
	int		x;
	char	**tmap;

	tmap = malloc(sizeof(char *) * (ft_ylen(map) + 1));
	if (!tmap)
		exit(EXIT_FAILURE);
	y = 0;
	x = 0;
	while (map[y][0])
	{
		tmap[y] = malloc(sizeof(char) * (ft_strlen(map[y]) + 1));
		while (map[y][x])
		{
			tmap[y][x] = map[y][x];
			x++;
		}
		tmap[y][x] = 0;
		y++;
		x = 0;
	}
	tmap[y] = malloc(sizeof(char) * 1);
	tmap[y][0] = 0;
	return (tmap);
}

t_pos	ft_pos(char **map, char c)
{
	t_pos	pos;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map[y][0])
	{
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				pos.c = c;
				pos.y = y;
				pos.x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}

int	ft_countline(char *buff)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			count++;
		i++;
	}
	return (count);
}
