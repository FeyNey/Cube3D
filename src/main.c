/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:36:20 by acoste            #+#    #+#             */
/*   Updated: 2025/01/04 18:04:37 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


void	get_size_map(int fd, int *map_size_x, int *map_size_y)
{
	int i;
	char *str;

	i = 0;
	str = "r";
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		if (ft_strlen(str) > (*map_size_x))
			*map_size_x = strlen(str);
		i++;
		free(str);
	}
	*map_size_y = i;
	printf("map_size_x = %i\n", *map_size_x);
	printf("map_size_y = %i\n", *map_size_y);
}

void	free_map(t_map *map)
{
	if (map->northpath)
		free(map->northpath);
	if (map->southpath)
		free(map->southpath);
	if (map->ouestpath)
		free(map->ouestpath);
	if (map->estpath)
		free(map->estpath);
}

void	assign_texture_to_struct(t_map *map, char *str)
{

}

void	get_map_path_to_texture(t_map *map)
{
	char *str;
	int i;

	i = 0;
	while (i < 3)
	{
		str = get_next_line(map->fd);
		if (!str)
			break;
		if (assign_texture_to_stuct(map, str) == 1) // TO continue
			i++;
		if (str)
			free(str);
	}
	if (i < 4)
		return (free(map), ft_error(6))
}

void	extract_texture_for_map(t_map *map)
{
	int i;
	int map_size_x;
	int map_size_y;

	i = 0;
	map_size_x = 0;
	map_size_y = 0;
	get_map_path_to_texture(map);
	get_size_map(map->fd, &map_size_x, &map_size_y);
	map->x = map_size_x;
	map->y = map_size_y;
}

int	main(int argc, char **argv)
{
	t_cube	c;

	(void)argv;
	if (argc != 2)
		return (ft_error(0), 1);
	c.name = "Cube 3D";
	if (check_map_is_valid(argv[1], &c) == 1)
		return (ft_error(3), 1);
	map_init(&c);
	cube3d_init(&c);
//	cube3d_render(&c); //TODO
	close_handler(&c); //TODO
	exit(EXIT_SUCCESS);
}