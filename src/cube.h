/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:27:54 by acoste            #+#    #+#             */
/*   Updated: 2025/01/05 19:14:00 by alexis           ###   ########.fr       */
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

//main.c
void	cube3d_init(t_cube *c);

//utils.c
void	ft_error(int nb);
char	*ft_strdup_till(char *str, char c);
int		ft_atoi(char *nptr);

//map_setup
void	initialised_map(t_map *map);
void	map_init(t_map *map);
void	display_map(t_map *map);
void	free_map(t_map *map);

//hook / handler
void	event_init(t_cube *c);
int		key_handler(int keysim, t_cube *c);
int		mouse_handler(int button, int x, int y, t_cube *c);
int		close_handler(t_cube *c);

//get_next_line
int		ft_strlen(char *str);
char	*ft_line(char *stash);
int		ft_search(char *str, char c);
char	*ft_malloc_char(int height);
char	*ft_strjoin(char *stash, char *buffer);
char	*read_file(int fd, char *stash);
char	*ft_next_line(char *stash);
char	*get_next_line(int fd);
void	read_file_till_end(t_map *map);

//verif_map
int	check_map_is_valid(char *argv, t_cube *c);
int	is_cub_file(char *argv);
void	get_size_map(int fd, int *map_size_x, int *map_size_y); //none use fn

//texture_map
void	get_map_path_to_texture(t_map *map, int verif);
int	assign_texture_to_struct(t_map *map, char *str);
int	assign_texture_to_struct2(t_map *map, char *str);

//color_map
void	extract_color_from_map(t_map *map);

#endif