/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:29:37 by acoste            #+#    #+#             */
/*   Updated: 2025/04/20 23:19:00 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

int	check_map_file_is_valid(char *argv, t_cube *c)
{
	//int	map_fd;

	if (is_cub_file(argv) == 1)
		return (1);
	c->map.fd = open(argv, O_RDONLY);
	//printf("TEST == %d", map_fd);
	if (c->map.fd == -1)
		return (ft_error(5), 1);
	// printf("Map fd : %i", map_fd);
	return (0);
}

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
			*map_size_x = ft_strlen(str);
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
	if (map->westpath)
		free(map->westpath);
	if (map->estpath)
		free(map->estpath);
}
