/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:36:20 by acoste            #+#    #+#             */
/*   Updated: 2024/12/29 21:39:29 by acoste           ###   ########.fr       */
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

	i = 150;
	y = 150;
	c->sprite.wizard.img_ptr = mlx_xpm_file_to_image(c->ptr,
			"textures/wizard.xpm", &i, &y);
}

void	show_img(t_cube *c)
{
	int i;
	int y;

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
}

void	cube3d_init(t_cube *c)
{
	int i;

	i = 0;
	c->ptr = mlx_init();
	if (c->ptr == NULL)
		ft_error(0);
	c->win = mlx_new_window(c->ptr, WIDTH, HEIGHT, c->name);
	if (c->win == NULL)
	{
		mlx_destroy_display(c->ptr);
		free(c->ptr);
		ft_error(0);
	}
	/*
	c->img.img_ptr = mlx_new_image(c->ptr, WIDTH, HEIGHT);
	if (c->img.img_ptr == NULL)
	{
		mlx_destroy_window(c->win, c->ptr);
		mlx_destroy_display(c->ptr);
		free (c->ptr);
		ft_error(0);
	}
	*/
	init_img(c);
	show_img(c);
	event_init(c);   //todo for moving the characters
	mlx_loop_hook(c->ptr, render_frame, c);
	mlx_loop(c->ptr);
}

/*
void	cube3d_render(t_cube *c)
{

}
*/

int	main(void)
{
	t_cube	c;

	c.name = "Cube 3D";

	cube3d_init(&c);
//	cube3d_render(&c); //TODO
	close_handler(&c); //TODO
	exit(EXIT_SUCCESS);
}