/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:36:20 by acoste            #+#    #+#             */
/*   Updated: 2024/12/28 18:39:00 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	close_handler(t_cube *c)
{
	mlx_destroy_image(c->ptr, c->img.img_ptr);
	mlx_destroy_window(c->ptr, c->win);
	mlx_destroy_display(c->ptr);
	free(c->ptr);
	exit(EXIT_SUCCESS);
}

void	cube3d_init(t_cube *c)
{
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
	c->img.img_ptr = mlx_new_image(c->ptr, WIDTH, HEIGHT);
	if (c->img.img_ptr == NULL)
	{
		mlx_destroy_window(c->win, c->ptr);
		mlx_destroy_display(c->ptr);
		free (c->ptr);
		ft_error(0);
	}
//	event_init(c);     //todo for moving the characters
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
	mlx_loop(c.ptr);
	usleep (900);
	close_handler(&c);
	//
	printf("aa\n");
	return (0);
}