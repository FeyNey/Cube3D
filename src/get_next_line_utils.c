/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:02:04 by acoste            #+#    #+#             */
/*   Updated: 2025/04/20 17:12:47 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*ft_malloc_char(int height)
{
	char	*new;

	new = malloc(sizeof(char) * (height + 1));
	if (!new)
		return (NULL);
	new[height] = '\0';
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_search(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
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
