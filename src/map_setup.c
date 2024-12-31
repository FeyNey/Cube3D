/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:35:18 by acoste            #+#    #+#             */
/*   Updated: 2024/12/31 15:35:38 by acoste           ###   ########.fr       */
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
	map->ouestpath = NULL;
}
