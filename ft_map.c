/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:57:06 by ldeville          #+#    #+#             */
/*   Updated: 2023/06/19 11:50:07 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_getline(int file)
{
	char	*buff;
	int		i;
	int		line;

	i = 1;
	line = 0;
	buff = malloc(sizeof(char) * 1001);
	while (i != 0)
	{
		i = read(file, buff, 1000);
		buff[i] = 0;
		line += ft_countline(buff);
	}
	free(buff);
	return (line);
}

void	ft_bufftomap(char *buff, char **map, int len, int x)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			map[y][x] = 0;
			x = 0;
			y++;
			if (!buff[i + 1])
				map[y] = malloc(sizeof(char) * (1));
			else
				map[y] = malloc(sizeof(char) * (len + 1));
			if (!map[y])
				exit(EXIT_FAILURE);
			i++;
		}
		else
			map[y][x++] = buff[i++];
	}
	map[y][x] = 0;
}

void	ft_addbuff(char **map, char *buff)
{
	int	len;
	int	x;

	x = 0;
	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	map[0] = malloc(sizeof(char) * (len + 1));
	ft_bzero(map[0], len + 1);
	if (!map[0])
		exit(EXIT_FAILURE);
	ft_bufftomap(buff, map, len, x);
	free(buff);
}

void	ft_addmap(char **map, int file)
{
	char	*buff;
	char	*tmp;
	int		i;

	i = -1;
	buff = malloc(sizeof(char) * 1001);
	tmp = malloc(sizeof(char) * 1);
	tmp[0] = 0;
	while (i != 0)
	{
		i = read(file, buff, 1000);
		buff[i] = 0;
		if (i != 0)
			tmp = ft_strjoin_sl(tmp, buff);
	}
	ft_addbuff(map, tmp);
	free(buff);
}

char	**ft_getmap(char *nfile)
{
	int		file;
	char	**map;

	file = open(nfile, O_RDONLY);
	if (file == -1)
	{
		ft_printf("Error\nThe file (%s) does not exist.\n", nfile);
		return (NULL);
	}
	if (ft_check_ber(nfile) == 0)
	{
		ft_printf("Error\nThe file (%s) is not a .ber.\n", nfile);
		return (NULL);
	}
	map = malloc(sizeof(char *) * (ft_getline(file) + 1));
	if (!map)
		exit(EXIT_FAILURE);
	close(file);
	file = open(nfile, O_RDONLY);
	ft_addmap(map, file);
	close(file);
	return (map);
}
