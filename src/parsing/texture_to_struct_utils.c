/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_stuct_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:16:49 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 15:59:50 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

// check 3 arguments max
//tous compris entre 255 et 0;

int check_color_map(char *str)
{
	char **tab;
	int i;
	int j;

	i = 0;
	j = 0;
	tab = ft_split(str, ',');
	while (i < 3)
	{
		if (!tab[i])
			return (0);
		i++;
	}
	if (tab[3])
		return(ft_free_split(tab), 0);
	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (ft_free_split(tab), 3);
		i++;
	}
	ft_free_split(tab);
	return (1);
}

//convert 220,100,0 to int value

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

char	*ft_strdup_till(char *str, char c)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = ft_strlen(str);
	j--;
	while (is_white_space(str[j]))
		j--;
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
		if (i > j)
			break;
	}
	dup[i] = '\0';
	return (dup);
}

int	is_white_space(int c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (1);
	return (0);
}
