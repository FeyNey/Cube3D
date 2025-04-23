/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:27:54 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 16:06:09 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define WIDTH 2000
# define HEIGHT 1000

//get_next_line ~ map reader ~
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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
	//sprite to add;
}				t_sprite;

typedef struct s_map
{
	char	*northpath;
	char	*southpath;
	char	*estpath;
	char	*westpath;
	int		floorcolor;
	int		ceilingcolor;
	int		fd;
	int		x;
	int		y;
}				t_map;

//fenetre
typedef struct s_cube
{
	void		*ptr;
	void		*win;
	char		*name;
	t_img		img;
	t_sprite	sprite;
	t_map		map;
}				t_cube;

///parsing///

//ft_split.c
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);

//get_next_line_utils.c
char	*ft_malloc_char(int height);
int		ft_strlen(char *str);
int		ft_search(char *str, char c);
void	read_file_till_end(t_map *map);

//get_next_line.c
char	*ft_strjoin(char *stash, char *buffer);
char	*get_next_line(int fd);

//texture_to_struct.c
void	get_map_path_to_texture(t_map *map, int verif);
int		assign_texture_and_color_to_struct(t_map *map, char *str);
int		assign_texture_to_struct(t_map *map, char *str);
int		assign_color_to_struct(t_map *map, char *str);
char	*cut_string(char *str);

//texture_to_struct_utils.c
int		check_color_map(char *str);
int		convert_colors_to_int(char *str);
char	*ft_strdup_till(char *str, char c);
int		is_white_space(int c);

//verif_map
int		is_cub_file(char *argv);
int		check_map_file_is_valid(char *argv, t_cube *c);
void	get_size_map(int fd, int *map_size_x, int *map_size_y);
void	free_map(t_map *map);


///display///

//event.c
int		key_handler(int keysim, t_cube *c);
int		close_handler(t_cube *c);
int		mouse_handler(int button, int x, int y, t_cube *c);
void	event_init(t_cube *c);

//image.c
int		render_frame(t_cube *c);
void	init_img(t_cube *c);
void	show_img(t_cube *c);

//map_setup
void	initialised_map(t_map *map);
void	map_init(t_map *map);


////src////

//debug.c
void	display_map(t_map *map);

//main.c
void	extract_texture_for_map(t_map *map);
void	cube3d_init(t_cube *c);

//utils.c
void	ft_error(int nb);
int		ft_atoi(const char *nptr);

#endif