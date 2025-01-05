/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:35:18 by acoste            #+#    #+#             */
/*   Updated: 2025/01/05 18:54:38 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	initialised_map(t_map *map)
{
	map->ceilingcolor = -1;
	map->floorcolor = -1;
	map->northpath = NULL;
	map->southpath = NULL;
	map->estpath = NULL;
	map->westpath = NULL;
}

void	display_map(t_map *map)
{
	printf("\n");
	printf("map fd = %i\n", map->fd);

	printf("Map North Texture = %s\n", map->northpath);
	printf("Map South Texture = %s\n", map->southpath);
	printf("Map West Texture  = %s\n", map->westpath);
	printf("Map East Texture  = %s\n", map->estpath);

	return ;
	printf("Floor Color = %d\n", map->floorcolor);
	printf("Ceiling Color = %d\n", map->ceilingcolor);

	printf("test");
	printf("test");
}

void	free_map(t_map *map)
{
	if (map->northpath)
		free(map->northpath);
	if (map->southpath)
		free(map->southpath);
	if (map->westpath)
		free(map->westpath);
	if (map->estpath)
		free(map->estpath);
}

void	map_init(t_map *map)
{
	initialised_map(map);
	get_map_path_to_texture(map, 0);
	display_map(map);
	extract_color_from_map(map);
}
