/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:35:18 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 15:37:59 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	initialised_map(t_map *map)
{
	// map = malloc(sizeof(t_map)); // a rajouter si prblm de fd enregistrement + free sortie d erreur
	map->ceilingcolor = -1;
	map->floorcolor = -1;
	map->northpath = NULL;
	map->southpath = NULL;
	map->estpath = NULL;
	map->westpath = NULL;
}

void	map_init(t_map *map)
{
	initialised_map(map);
	extract_texture_for_map(map);
	//is_valid_map(map); //todo
}
