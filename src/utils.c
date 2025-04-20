/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:46:31 by acoste            #+#    #+#             */
/*   Updated: 2025/04/20 22:20:59 by acoste           ###   ########.fr       */
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
	//liste des erreurs avec un code (a completer)
	exit(EXIT_FAILURE);
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

char	*cut_string(char *str, char scaract)
{
	char *dupp;

	if (str[0] != scaract && str[0] != ' ')
		return (NULL);
	if (str[0] == scaract)
		str++;
	while (*str && is_white_space(*str))
			str++;
	if (!str)
		return (NULL);
	dupp = ft_strdup_till(str, '\n');
	return (dupp);
}

int	is_white_space(int c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (1);
	return (0);
}

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

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
