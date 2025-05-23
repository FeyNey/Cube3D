/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:46:31 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 16:07:29 by acoste           ###   ########.fr       */
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
		printf("Map not a valid path to an oriation texture North South West \
or East or a Floor / Ceilling color\n");
	}
	//liste des erreurs avec un code (a completer)
	exit(EXIT_FAILURE);
}

//dupplique une chaine de caractere en supprimant les white space avant et
//apres, et la renvoie


int	ft_atoi(const char *nptr)
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
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
