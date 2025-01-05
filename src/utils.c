/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:46:31 by acoste            #+#    #+#             */
/*   Updated: 2025/01/05 19:21:35 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_error(int nb)
{
	printf("Error\n");
	if (nb == 0)
		printf("Wrong Number Argument\n\ttry ./cub3D map/map_name.cub\n");
	if (nb == 1)
		printf("Malloc Error\n");
	if (nb == 2)
		printf("Map Problem encounter\n");
	if (nb == 4)
		printf ("Map isn't a '.cub'\n\tTry ./cub3d map/map_name.cub\n");
	if (nb == 5)
		printf ("Map does not exist\n\tPlease verify the Path you entered");
	if (nb == 6)
	{
		printf("Map not valid, no path to an oriation texture North South West \
		or East\n");
	}
	if (nb == 7)
		printf("Map not valid, no path to a ceiling/floor color texture found");
	exit(EXIT_FAILURE);
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

int	ft_atoi(char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = (sign * (-1));
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}