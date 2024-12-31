/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:36:20 by acoste            #+#    #+#             */
/*   Updated: 2024/12/31 16:59:38 by acoste           ###   ########.fr       */
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
	int i;

	i = 0;
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

/*
void	cube3d_render(t_cube *c)
{

}
*/

void	extract_texture_for_map(t_map *map)
{
	int i;

	(void)map;
	i = 0;
	// open()
}

void	map_init(t_map *map)
{
	initialised_map(map);
	extract_texture_for_map(map);
}

int	is_cub_file(char *argv)
{
	int i;
	int false;

	false = 0;
	i = ft_strlen(argv);
	if (i <= 4)
		return (ft_error(4), 1);
	if (argv[i - 4] != '.')
		false = 1;
	if (argv[i - 3] != 'c')
		false = 1;
	if (argv[i - 2] != 'u')
		false = 1;
	if (argv[i - 1] != 'b')
		false = 1;
	if (false == 1)
		return (ft_error(4), 1);
	return (0);
}

int	check_map_is_valid(char *argv)
{
	int map_fd;

	if (is_cub_file(argv) == 1)
		return (1);
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		return (ft_error(5), 0);
/*

		To Be continued


*/
	return (0);
}

int	main(int argc, char **argv)
{
	t_cube	c;

	(void)argv;
	if (argc != 2)
		return (ft_error(0), 1);
	if (check_map_is_valid(argv[1]) == 1)
		return (ft_error(3), 1);

	c.name = "Cube 3D";

	map_init(&(c.map));
	cube3d_init(&c);
//	cube3d_render(&c); //TODO
	close_handler(&c); //TODO
	exit(EXIT_SUCCESS);
}