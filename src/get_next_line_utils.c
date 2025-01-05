/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:02:04 by acoste            #+#    #+#             */
/*   Updated: 2025/01/05 18:38:18 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
