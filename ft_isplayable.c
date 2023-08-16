/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isplayable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:22:05 by ldeville          #+#    #+#             */
/*   Updated: 2023/06/05 14:54:26 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_check_collect(char **map)
{
	int	y;
	int	x;
	int	collect;

	y = 0;
	x = 0;
	collect = 0;
	while (map[y][0])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collect++;
			x++;
		}
		x = 0;
		y++;
	}
	return (collect);
}

void	ft_recurpath(int x, int y, t_pos end, char **tmap)
{
	tmap[y][x] = '%';
	if (tmap[y - 1][x] && tmap[y - 1][x] != '1'
		&& tmap[y - 1][x] != 'X' && tmap[y - 1][x] != '%')
		ft_recurpath(x, (y - 1), end, tmap);
	if (tmap[y][x + 1] && tmap[y][x + 1] != '1'
		&& tmap[y][x + 1] != 'X' && tmap[y][x + 1] != '%')
		ft_recurpath((x + 1), y, end, tmap);
	if (tmap[y + 1][x] && tmap[y + 1][x] != '1'
		&& tmap[y + 1][x] != 'X' && tmap[y + 1][x] != '%')
		ft_recurpath(x, (y + 1), end, tmap);
	if (tmap[y][x - 1] && tmap[y][x - 1] != '1'
		&& tmap[y][x - 1] != 'X' && tmap[y][x - 1] != '%')
		ft_recurpath((x - 1), y, end, tmap);
}

int	ft_collect(char **map, char **tmap)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][0])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C' && tmap[y][x] != '%')
				return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_startend(t_pos start, t_pos end, char **map)
{
	int		x;
	int		y;
	char	**tmap;

	tmap = ft_testmap(map);
	ft_recurpath(start.x, start.y, end, tmap);
	if (tmap[end.y][end.x] != '%')
	{
		ft_printf("Error\n");
		ft_printf("This map is not playable, you can't reach the end.\n");
		return (-1);
	}
	if (ft_collect(map, tmap) != 0)
	{
		ft_printf("Few items are not collectables.\n");
		return (-1);
	}
	x = 0;
	while (tmap[x][0])
		free(tmap[x++]);
	free(tmap[x]);
	free(tmap);
	return (0);
}

int	ft_mapisplayable(char **map)
{
	if (ft_startend(ft_pos(map, 'P'), ft_pos(map, 'E'), map) != 0)
		return (-1);
	return (0);
}
