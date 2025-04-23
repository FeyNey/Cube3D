/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:22:43 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 15:34:46 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	render_frame(t_cube *c)
{
	(void)c;
	return (0);
}

void	init_img(t_cube *c)
{
	int i;
	int y;

	(void)c;
	i = 150;
	y = 150;
	c->sprite.wizard.img_ptr = mlx_xpm_file_to_image(c->ptr,
			"textures/wizard.xpm", &i, &y);
}

void	show_img(t_cube *c)
{
	int i;
	int y;

	(void)c;
	i = 0;
	while (i < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			y++;
		}
		i++;
	}
	mlx_put_image_to_window(c->ptr, c->win, c->sprite.wizard.img_ptr, 5 * 64, 5 * 64);
}
