/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:36:20 by acoste            #+#    #+#             */
/*   Updated: 2025/04/20 23:18:49 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	assign_texture_to_struct(t_map *map, char *str)
{
	char *dupp;

	if (str[0] == 'N')
	{
		dupp = cut_string(&str[1], 'O');
		if (!dupp)
			return (2);
		if (!map->northpath)
			map->northpath = dupp;
		else
			return (printf("Texture Already Set\n"), free(dupp), 3);
		return (1);
	}
	if (str[0] == 'S')
	{
		dupp = cut_string(&str[1], 'O');
		if (!dupp)
			return (2);
		if (!map->southpath)
			map->southpath = dupp;
		else
			return (printf("Texture Already Set\n"), free(dupp), 3);
		return (1);
	}
	return (assign_texture_to_struct2(map, str));
}

int	assign_texture_to_struct2(t_map *map, char *str)
{
	char *dupp;

	if (str[0] == 'W')
	{
		dupp = cut_string(&str[1], 'E');
		if (!dupp)
			return (2);
		if (!map->westpath)
			map->westpath = dupp;
		else
			return (printf("Texture Already Set\n"), free(dupp), 3);
		return (1);
	}
	if (str[0] == 'E')
	{
		dupp = cut_string(&str[1], 'A');
		if (!dupp)
			return (2);
		if (!map->estpath)
			map->estpath = dupp;
		else
			return (printf("Texture Already Set\n"), free(dupp), 3);
		return (1);
	}
	return (assign_texture_to_struct3(map, str));
}

// check 3 arguments max
//tous compris entre 255 et 0;

int check_color_map(char *str)
{
	char **tab;
	int i;
	int j;

	i = 0;
	j = 0;
	printf("str[0]  ==' %c '  if (F it s bad) check_color map \n", str[0]);
	tab = ft_split(str, ',');
	while (i < 3)
	{
		if (!tab[i])
			return (0);
		i++;
	}
	if (tab[3])
		return(0);
	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (3);
		i++;
	}
	ft_free_split(tab);
	return (1);
}

//convert 220,100,0

int	convert_colors_to_int(char *str)
{
	char	**tab;
	int		red;
	int		green;
	int		blue;
	int		color;

	tab = ft_split(str, ',');
	red = ft_atoi(tab[0]);
	green = ft_atoi(tab[1]);
	blue = ft_atoi(tab[2]);
	ft_free_split(tab);
	color = (red << 16 | (green << 8) | blue);
	return (color);
}

int	assign_texture_to_struct3(t_map *map, char *str)
{
	if (str[0] == 'F')
	{
		str++;
		if (check_color_map(str) != 1)
		{
			printf("Error assign texture\n");
			return (5);//verifie que l on est bien 3 couleurs comprise entre 0 et 255
		}
		map->floorcolor = convert_colors_to_int(str);
		return (1);
	}
	if (str[0] == 'C')
	{
		str++;
		if (check_color_map(str++) != 1)
			return (5);
		map->ceilingcolor = convert_colors_to_int(str);
		return (1);
	}
	return (0);
}



/*
void	get_map_floor_ceiling_color(t_map *map, int verif)
{
	char	*str;
	int		i;

	i = 0;
	while (i < 2)
	{
		str = get_next_line(map->fd);
		if (!str)
			break;
		verif = assign_floor_ceiling_color(map, str);
		if (verif != 1 && str != '\n')
			break;
		else if (verif == 1)
			i++;
		if (str)
			free(str);
	}
	if (i < 1)
	{

	}
}

int	assign_floor_ceiling_color(t_map *map, char *str)
{
	char *dupp;

		if (str[0] == 'F')
		{
			while ((*str <= '0' || *str >= '9') && *str)
				str++;
			if (!*str)
				return (2);
			dupp = ft_strdup_till(str, ',');



			free(dupp)
		}
}*/
/*
void	others_error_handling(int verif)
{

}
*/
void	get_map_path_to_texture(t_map *map, int verif)
{
	char *str;
	int i;

	i = 0;
	while (i <= 5)
	{
		str = get_next_line(map->fd);
		if (!str)
		{
			printf("R == %i\n", map->fd);
			break;
		}
		verif = assign_texture_to_struct(map, str);
		if ((verif != 1 && verif != 3) && *str != '\n')
		{
			printf("\tBREAK\n");
			break;
		}
		else if (verif == 1)
			i++;
		if (str)
			free(str);
		printf("i == %i\n", i);
	}
	if (i <= 4)
	{
		printf("N == %i\n", i);
		if (str)
			free(str);
		read_file_till_end(map);
		printf ("BAD SORTI i = %i\n", i);
		return (free_map(map), ft_error(6));
	}
	// return (orthers_error_handling(verif));
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
	// get_map_floor_ceiling_color(map); //TODO
	display_map(map);
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
	if (check_map_file_is_valid(argv[1], &c) == 1)
		return (1);  //todo
	map_init(&c.map);
	cube3d_init(&c);
//	cube3d_render(&c); //TODO
	close_handler(&c); //TODO
	// free_map(&c.map);
	exit(EXIT_SUCCESS);
}

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
