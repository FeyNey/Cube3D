/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:41:30 by alexis            #+#    #+#             */
/*   Updated: 2025/01/05 18:50:50 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	assign_texture_to_struct(t_map *map, char *str)
{
	char *dupp;

	if (str[0] == 'N')
	{
		while (*str != '.' && *str)
			str++;
		if (!(*str))
			return (2);
		dupp = ft_strdup_till(str, '\n');
		map->northpath = dupp;
		return (1);
	}
	if (str[0] == 'S')
	{
		while (*str != '.' && *str)
			str++;
		if (!(*str))
			return (2);
		dupp = ft_strdup_till(str, '\n');
		map->southpath = dupp;
		return (1);
	}
	return (assign_texture_to_struct2(map, str));
}

int	assign_texture_to_struct2(t_map *map, char *str)
{
	char *dupp;

	if (str[0] == 'W')
	{
		while (*str != '.' && *str)
			str++;
		if (!(*str))
			return (2);
		dupp = ft_strdup_till(str, '\n');
		map->westpath = dupp;
		return (1);
	}
	if (str[0] == 'E')
	{
		while (*str != '.' && *str)
			str++;
		if (!(*str))
			return (2);
		dupp = ft_strdup_till(str, '\n');
		map->estpath = dupp;
		return (1);
	}
	return (0);
}

void	get_map_path_to_texture(t_map *map, int verif)
{
	char *str;
	int i;

	i = 0;
	while (i <= 3)
	{
		str = get_next_line(map->fd);
		if (!str)
			break;
		verif = assign_texture_to_struct(map, str);
		if (verif == 1)
			i++;
		else if (verif == 2)
			break;
		if (str)
			free(str);
	}
	if (i <= 3)
	{
		if (str)
			free(str);
		read_file_till_end(map);
		return (free_map(map), ft_error(6));
	}
}
/*
void	extract_size for map(t_map *map)
{
	// int i;
	int map_size_x;
	int map_size_y;

	// i = 0;
	map_size_x = 0;
	map_size_y = 0;
	get_size_map(map->fd, &map_size_x, &map_size_y);
	map->x = map_size_x;
	map->y = map_size_y;
}
*/

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
