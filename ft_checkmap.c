/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:20:57 by ldeville          #+#    #+#             */
/*   Updated: 2023/05/17 12:15:26 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_error(int error)
{
	ft_printf("Error\n");
	if (error == 1)
		printf("Map need to be surrounded by walls.\n");
	else if (error == 2)
		printf("Map should be a rectangle.\n");
	else if (error == 3)
		printf("Map should have and entry and an exit.\n");
	else if (error == 4)
		printf("Map need to contain atleast 1 item.\n");
	else if (error == 5)
		printf("Map should contain only : 0, 1, C, E or P.\n");
	return (-1);
}

int	ft_checkinout(char **map, char c)
{
	int	y;
	int	x;
	int	e;

	y = 0;
	x = 0;
	e = 0;
	while (map[y][0])
	{
		while (map[y][x])
		{
			if (map[y][x] == c)
				e++;
			x++;
		}
		x = 0;
		y++;
	}
	if ((c == 'P' || c == 'E') && e != 1)
		return (-1);
	if (c == 'C' && e < 1)
		return (-1);
	return (0);
}

int	ft_checkmore(char **map, int lenx, int leny)
{
	int	i;

	i = 0;
	while (i < leny && map[i][0] == '1' && map[i][lenx - 1] == '1')
		i++;
	if (i != leny)
		return (ft_error(1));
	if (ft_checkinout(map, 'E') != 0 || ft_checkinout(map, 'P') != 0)
		return (ft_error(3));
	if (ft_checkinout(map, 'C') != 0)
		return (ft_error(4));
	if (ft_check_cara(map) == 0)
		return (ft_error(5));
	return (0);
}

int	ft_samelen(char **map)
{
	int	len;
	int	y;

	len = 0;
	y = 0;
	while (map[y][len])
		len++;
	while (map[y][0])
	{
		if (map[y][len])
			return (-1);
		y++;
	}
	return (0);
}

int	ft_checkmap(char **map)
{
	int	lenx;
	int	leny;
	int	i;

	lenx = ft_strlen(map[0]);
	leny = 0;
	i = 0;
	if (ft_samelen(map) != 0)
		return (ft_error(2));
	while (map[leny][0])
		leny++;
	if (lenx == leny)
		return (ft_error(2));
	while (map[0][i] == '1')
		i++;
	if (i < lenx)
		return (ft_error(1));
	i = 0;
	while (map[leny - 1][i] == '1')
		i++;
	if (i != lenx)
		return (ft_error(1));
	if (ft_checkmore(map, lenx, leny) != 0)
		return (-1);
	return (0);
}
