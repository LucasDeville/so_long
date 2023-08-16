/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:08:46 by ldeville          #+#    #+#             */
/*   Updated: 2023/06/05 14:29:54 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	ft_add_img(t_mlx mlx, char *path)
{
	t_sprite	img;

	if (!path[0])
	{
		img.ptr = NULL;
		img.pixels = NULL;
		img.x = 0;
		img.y = 0;
		img.bpp = 0;
		img.size = 0;
		img.endian = 0;
	}
	else
	{
		img.ptr = mlx_xpm_file_to_image(mlx.mlx,
				path, &img.x, &img.y);
		img.pixels = mlx_get_data_addr(img.ptr, &img.bpp,
				&img.size, &img.endian);
	}
	return (img);
}

void	ft_more_sprites(t_sprite *img, t_mlx mlx)
{
	img[16] = ft_add_img(mlx, "./sprites/1santa00.xpm");
	img[17] = ft_add_img(mlx, "./sprites/1santa01.xpm");
	img[18] = ft_add_img(mlx, "./sprites/1santa02.xpm");
	img[19] = ft_add_img(mlx, "./sprites/1santa03.xpm");
	img[20] = ft_add_img(mlx, "./sprites/1santa04.xpm");
}

t_sprite	*ft_init_sprite(t_mlx mlx)
{
	t_sprite	*img;

	img = malloc(sizeof(t_img) * (21 + 1));
	img[0] = ft_add_img(mlx, "./sprites/tree.xpm");
	img[1] = ft_add_img(mlx, "./sprites/sol.xpm");
	img[2] = ft_add_img(mlx, "./sprites/collecte.xpm");
	img[3] = ft_add_img(mlx, "./sprites/doors00.xpm");
	img[4] = ft_add_img(mlx, "./sprites/santa00.xpm");
	img[5] = ft_add_img(mlx, "./sprites/santa01.xpm");
	img[6] = ft_add_img(mlx, "./sprites/santa02.xpm");
	img[7] = ft_add_img(mlx, "./sprites/santa03.xpm");
	img[8] = ft_add_img(mlx, "./sprites/santa04.xpm");
	img[9] = ft_add_img(mlx, "./sprites/doors01.xpm");
	img[10] = ft_add_img(mlx, "./sprites/doors00.xpm");
	img[11] = ft_add_img(mlx, "./sprites/enemy00.xpm");
	img[12] = ft_add_img(mlx, "./sprites/enemy01.xpm");
	img[13] = ft_add_img(mlx, "./sprites/enemy02.xpm");
	img[14] = ft_add_img(mlx, "./sprites/enemy03.xpm");
	img[15] = ft_add_img(mlx, "./sprites/enemy04.xpm");
	ft_more_sprites(img, mlx);
	img[21] = ft_add_img(mlx, "");
	return (img);
}
