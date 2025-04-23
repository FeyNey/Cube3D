/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:17 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 15:07:39 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//affiche le contenu de la structure map

void	display_map(t_map *map)
{
	printf("\n");
	printf("map fd = %i\n", map->fd);

	printf("Map North Texture = %s\n", map->northpath);
	printf("Map South Texture = %s\n", map->southpath);
	printf("Map West Texture  = %s\n", map->westpath);
	printf("Map East Texture  = %s\n", map->estpath);

	printf("Floor Color Value = %i\n", map->floorcolor);
	printf("Ceiling Color Value = %i\n", map->ceilingcolor);
	return ;

	printf("");
	printf("");
}