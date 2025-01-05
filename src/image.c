/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:22:43 by acoste            #+#    #+#             */
/*   Updated: 2025/01/05 18:26:35 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	cube3d_init(t_cube *c)
{
	c->ptr = mlx_init();
	if (c->ptr == NULL)
		ft_error(1);
	c->win = mlx_new_window(c->ptr, WIDTH, HEIGHT, c->name);
	if (c->win == NULL)
	{
		mlx_destroy_display(c->ptr);
		free(c->ptr);
		ft_error(1);
	}
	c->img.img_ptr = mlx_new_image(c->ptr, WIDTH, HEIGHT);
	if (c->img.img_ptr == NULL)
	{
		mlx_destroy_window(c->win, c->ptr);
		mlx_destroy_display(c->ptr);
		free (c->ptr);
		ft_error(1);
	}
	init_img(c);
	show_img(c);
	event_init(c);   //todo for moving the characters
	mlx_loop_hook(c->ptr, render_frame, c);
	mlx_loop(c->ptr);
}
