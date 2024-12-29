/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:27:54 by acoste            #+#    #+#             */
/*   Updated: 2024/12/29 21:33:21 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define WIDTH 2000
# define HEIGHT 1000

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>

//image
typedef struct s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			line_lenght;
	int			endian;
}				t_img;

typedef struct	s_sprite
{
	t_img	wizard;
}				t_sprite;

//fenetre
typedef struct s_cube
{
	void		*ptr;
	void		*win;
	t_img		img;
	t_sprite	sprite;
	char		*name;
}				t_cube;

//main.c
void	cube3d_init(t_cube *c);

//utils.c
void	ft_error(int nb);

//hook / handler
void	event_init(t_cube *c);
int		key_handler(int keysim, t_cube *c);
int		mouse_handler(int button, int x, int y, t_cube *c);
int		close_handler(t_cube *c);

#endif