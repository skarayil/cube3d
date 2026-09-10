/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:42:40 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/10 15:42:41 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_rgb_to_hex(t_rgb color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_get_pixel(t_img *img, int x, int y)
{
	char	*src;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	src = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(unsigned int *)src);
}
