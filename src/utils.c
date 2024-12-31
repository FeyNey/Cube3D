/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:46:31 by acoste            #+#    #+#             */
/*   Updated: 2024/12/31 16:54:33 by acoste           ###   ########.fr       */
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
	//liste des erreurs avec un code (a completer)
	exit(EXIT_FAILURE);
}