/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:36:20 by acoste            #+#    #+#             */
/*   Updated: 2025/01/05 20:40:52 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
/*
//255, 00, 00
char *hexadecimal;

char *str;

str -> 255 until ',' i++, str[i] = '\0';

ft_convert_to_hexa(str);
*/

int	compose_color(char *str)
{
	// str = 255,0,0 ex
	char *temp;
	int i;
	int color;
	int color2;
	int color3;

	i = 0;
	temp = str;
	while(str[i] >= '0' && str[i] <= '9')
		i++;
	temp[i] == '\0';
	color = ft_atoi(str);
	if (color < 0 || color > 255)
		return(-1);
	return(color);
}

int	get_color_value(t_map *map, char *str)
{
	int color;

	if (str[0] == 'F')
	{
		while (*str < '0' && *str > '9' && *str)
			str++;
		if (!str)
			return (2);
		color = compose_color(str);
		if (color == -1)
			return (2);
		map->floorcolor = color;
		return (1);
	}



	if (str[0] == 'C')
	{
		while (*str < '0' && *str > '9' && *str)
			str++;
		if (!str)
			return (2);
		color = compose_color(str);
		map->ceilingcolor = color;
		return (1);
	}
	if (str[0] == '\n')
		return (0);
	return (1);
}

void	extract_color_from_map(t_map *map, int verif)
{
	char *str;
	int i;

	i = 0;
	while (i < 2)
	{
		str = get_next_line(map->fd);
		if (!str)
			break;
		verif = get_color_value(map, str);
		if (verif = 1)
			i++;
		else if (verif = 2)
			break;
		if (str)
			free(str);
	}
	if (i < 2)
	{
		if (str)
			free(str);
		read_file_till_end(map->fd);
		return (free_map(map), ft_error(7));
	}
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