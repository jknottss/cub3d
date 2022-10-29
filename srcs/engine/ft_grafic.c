/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grafic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:39:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_render_frame(t_engine *engine)
{
	ft_check_player_area(engine);
	ft_draw_background(engine);
	ft_cast_3d_ray(engine);
	mlx_put_image_to_window(engine->mlx, engine->window,
		engine->img->img, 0, 0);
	if (engine->img == &engine->img0)
		engine->img = &engine->img1;
	else
		engine->img = &engine->img0;
	ft_clear_image(engine);
	return (0);
}

void	ft_clear_image(t_engine *engine)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(engine->img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}
