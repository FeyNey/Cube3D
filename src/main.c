/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:36:20 by acoste            #+#    #+#             */
/*   Updated: 2025/01/05 17:36:21 by acoste           ###   ########.fr       */
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
	if (map->westpath)
		free(map->westpath);
	if (map->estpath)
		free(map->estpath);
}

char	*ft_strdup_till(char *str, char c)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

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

void	read_file_till_end(t_map *map)
{
	char *str;

	str = "a";
	while (str != NULL)
	{
		str = get_next_line(map->fd);
		if (str)
			free(str);
	}
}

// changer les retour en fonction de 0 // 2 et 1
//leak

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
		if (assign_texture_to_struct(map, str) != 1 && *str != '\n')
			break;
		else
			i++;
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

void	display_map(t_map *map)
{
	printf("\n");
	printf("map fd = %i\n", map->fd);

	printf("Map North Texture = %s\n", map->northpath);
	printf("Map South Texture = %s\n", map->southpath);
	printf("Map West Texture  = %s\n", map->westpath);
	printf("Map East Texture  = %s\n", map->estpath);

	return ;
	printf("");
	printf("");

	printf("");
	printf("");
}

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
	exit (1);
	//get_map_floor_ceiling_color(map); //TODO
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
	map_init(&c.map);
	cube3d_init(&c);
//	cube3d_render(&c); //TODO
	close_handler(&c); //TODO
	exit(EXIT_SUCCESS);
}