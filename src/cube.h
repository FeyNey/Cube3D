/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:27:54 by acoste            #+#    #+#             */
/*   Updated: 2024/12/28 18:39:04 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define WIDTH 1000
# define HEIGHT 1000

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			line_lenght;
	int			endian;
}				t_img;


//fenetre
typedef struct s_cube
{
	void	*ptr;
	void	*win;
	t_img	img;
	char	*name;
}	t_cube;

//main.c
void	cube3d_init(t_cube *c);

//utils.c
void	ft_error(int nb);

#endif