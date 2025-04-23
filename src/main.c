/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:36:20 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 15:36:11 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//convert 220,100,0

void	extract_texture_for_map(t_map *map)
{
	int i;
	int map_size_x;
	int map_size_y;

	i = 0;
	map_size_x = 0;
	map_size_y = 0;
	get_map_path_to_texture(map, 0);
	display_map(map);
	get_size_map(map->fd, &map_size_x, &map_size_y);
	map->x = map_size_x;
	map->y = map_size_y;
}

//peut etre mis dans le fichier image.c

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
	mlx_loop_hook(c->ptr, render_frame, c); //todo render frame
	mlx_loop(c->ptr);
}


int	main(int argc, char **argv)
{
	t_cube	c;

	(void)argv;
	if (argc != 2)
		return (ft_error(0), 1);
	c.name = "Cube 3D";
	if (check_map_file_is_valid(argv[1], &c) == 1)
		return (1);  //todo
	map_init(&c.map);
	cube3d_init(&c);
//	cube3d_render(&c); //TODO
	close_handler(&c); //TODO
	// free_map(&c.map);
	exit(EXIT_SUCCESS);
}
