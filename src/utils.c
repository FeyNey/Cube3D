/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:46:31 by acoste            #+#    #+#             */
/*   Updated: 2024/12/28 18:38:56 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_error(int nb)
{
	printf("Error\n");
	if (nb == 0)
		printf("Malloc Error\n");
	if (nb == 1)
		printf("Map Problem encounter\n");
	//liste des erreurs avec un code (a completer)
}