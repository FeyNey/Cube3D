/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:47:49 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 15:31:50 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	key_handler(int keysim, t_cube *c)
{
	(void)c;
	printf("%d\n", keysim);
	if (keysim == 65307)
		close_handler(c);
	return (0);
}

//echap = 65307

int	close_handler(t_cube *c)
{
	free_map(&(c->map)); // normalement fait dans le return de l'erreur avant.
	mlx_destroy_image(c->ptr, c->sprite.wizard.img_ptr);
	mlx_destroy_image(c->ptr, c->img.img_ptr);
	mlx_destroy_window(c->ptr, c->win);
	mlx_destroy_display(c->ptr);
	free(c->ptr);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x, int y, t_cube *c)
{
	(void)c;
	(void)x;
	(void)y;
	printf("%d\n", button);
	return (0);
}

void	event_init(t_cube *c)
{
	mlx_hook(c->win, 2, KeyPressMask, key_handler, c);
	mlx_hook(c->win, ButtonPress, ButtonPressMask, mouse_handler, c);
	mlx_hook(c->win, DestroyNotify, StructureNotifyMask, close_handler, c);
}
