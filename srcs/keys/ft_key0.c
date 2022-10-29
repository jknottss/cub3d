/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:41:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_calc_xy(t_player *player, double sx, double sy, char c);

int	ft_key(int keycode, t_engine *engine)
{
	if (keycode == XK_ESC)
		ft_engine_destroy(engine);
	else if (keycode == XK_A || keycode == XK_S
		|| keycode == XK_D || keycode == XK_W)
		ft_key_player_movement(keycode, engine);
	else if (keycode == XK_LEFT || keycode == XK_RIGHT)
		ft_key_player_rotation(keycode, engine);
	return (0);
}

void	ft_key_player_movement(int keycode, t_engine *engine)
{
	t_player	*player;
	double		sx;
	double		sy;

	player = &engine->screen->player;
	sx = cos(ft_deg_to_rad(player->angle - 90)) * MOV_MULTI;
	sy = sin(ft_deg_to_rad(player->angle - 90)) * MOV_MULTI;
	if (keycode == XK_A && player->free_a == 0)
		ft_calc_xy(player, sx, sy, '+');
	else if (keycode == XK_D && player->free_d == 0)
		ft_calc_xy(player, sx, sy, '-');
	else if (keycode == XK_W && player->free_w == 0)
	{
		player->x += player->dx;
		player->y += player->dy;
	}
	else if (keycode == XK_S && player->free_s == 0)
	{
		player->x -= player->dx;
		player->y -= player->dy;
	}
}

static void	ft_calc_xy(t_player *player, double sx, double sy, char c)
{
	if (c == '+')
	{
		player->x += sx;
		player->y += sy;
	}
	else if (c == '-')
	{
		player->x -= sx;
		player->y -= sy;
	}
}

void	ft_key_player_rotation(int keycode, t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	if (keycode == XK_LEFT)
		player->angle -= ROT_STEP;
	else if (keycode == XK_RIGHT)
		player->angle += ROT_STEP;
	player->angle = ft_fix_angle(player->angle);
	player->dx = cos(ft_deg_to_rad(player->angle)) * MOV_MULTI;
	player->dy = sin(ft_deg_to_rad(player->angle)) * MOV_MULTI;
}
