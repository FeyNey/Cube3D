/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:11:44 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 15:57:42 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	assign_texture_and_color_to_struct(t_map *map, char *str)
{
	char *dupp;

	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
	{
		dupp = cut_string(&str[1]);
		if (!dupp)
			return (2);
		if (!map->northpath)
			map->northpath = dupp;
		else
			return (printf("Texture Already Set\n"), free(dupp), 3);
		return (1);
	}
	if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
	{
		dupp = cut_string(&str[1]);
		if (!dupp)
			return (2);
		if (!map->southpath)
			map->southpath = dupp;
		else
			return (printf("Texture Already Set\n"), free(dupp), 3);
		return (1);
	}
	return (assign_texture_to_struct(map, str));
}

int	assign_texture_to_struct(t_map *map, char *str)
{
	char *dupp;

	if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
	{
		dupp = cut_string(&str[1]);
		if (!dupp)
			return (2);
		if (!map->westpath)
			map->westpath = dupp;
		else
			return (printf("Texture Already Set\n"), free(dupp), 3);
		return (1);
	}
	if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
	{
		dupp = cut_string(&str[1]);
		if (!dupp)
			return (2);
		if (!map->estpath)
			map->estpath = dupp;
		else
			return (printf("Texture Already Set\n"), free(dupp), 3);
		return (1);
	}
	return (assign_color_to_struct(map, str));
}

int	assign_color_to_struct(t_map *map, char *str)
{
	if (str[0] == 'F' && str[1] == ' ')
	{
		str++;
		if (check_color_map(str) != 1)
		{
			printf("Error assign color\n");
			return (5);//verifie que l on est bien 3 couleurs comprise entre 0 et 255
		}
		map->floorcolor = convert_colors_to_int(str);
		return (1);
	}
	if (str[0] == 'C' && str[1] == ' ')
	{
		str++;
		if (check_color_map(str++) != 1)
		{
			printf("Error assign color\n");
			return (5);
		}
		map->ceilingcolor = convert_colors_to_int(str);
		return (1);
	}
	return (0);
}

char	*cut_string(char *str)
{
	char *dupp;

	str++;
	while (*str && is_white_space(*str))
			str++;
	if (!str)
		return (NULL);
	dupp = ft_strdup_till(str, '\n');
	return (dupp);
}

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
			printf("Error gnl,  map->fd = %i\n", map->fd);
			break;
		}
		verif = assign_texture_and_color_to_struct(map, str);
		if ((verif != 1 && verif != 3) && *str != '\n')
			break;
		else if (verif == 1)
			i++;
		if (str)
			free(str);
	}
	// if (verif != 1 && verif != 3)
		// others_error_handling(verif, str);
	if (i <= 4)
	{
		if (str)
			free(str);
		read_file_till_end(map);
		return (free_map(map), ft_error(6));
	}
	// return (orthers_error_handling(verif)); //todo ? en vrai osef
}