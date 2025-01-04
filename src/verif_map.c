/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:29:37 by acoste            #+#    #+#             */
/*   Updated: 2025/01/04 17:34:57 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


int	is_cub_file(char *argv)
{
	int i;
	int false;

	false = 0;
	i = ft_strlen(argv);
	if (i <= 4)
		return (ft_error(4), 1);
	if (argv[i - 4] != '.')
		false = 1;
	if (argv[i - 3] != 'c')
		false = 1;
	if (argv[i - 2] != 'u')
		false = 1;
	if (argv[i - 1] != 'b')
		false = 1;
	if (false == 1)
		return (ft_error(4), 1);
	return (0);
}

int	check_map_is_valid(char *argv, t_cube *c)
{
	int	map_fd;

	if (is_cub_file(argv) == 1)
		return (1);
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		return (ft_error(5), 0);
	c->map.fd = map_fd;
	return (0);
}
