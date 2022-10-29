/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:41:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_key_player_rotate_pressed(int keycode, t_engine *engine)
{
	if (keycode == XK_LEFT)
		engine->key.left = 1;
	else if (keycode == XK_RIGHT)
		engine->key.right = 1;
}

void	ft_key_player_rotate_released(int keycode, t_engine *engine)
{
	if (keycode == XK_LEFT)
		engine->key.left = 0;
	else if (keycode == XK_RIGHT)
		engine->key.right = 0;
}

void	ft_key_player_rotate(t_engine *engine)
{
	t_player	*player;

	player = &engine->screen->player;
	if (engine->key.left == 1)
		player->angle -= ROT_STEP;
	else if (engine->key.right == 1)
		player->angle += ROT_STEP;
	if (player->angle < 0)
		player->angle += 360.0;
	else if (player->angle > 360.0)
		player->angle -= 360.0;
	player->dx = cos(ft_deg_to_rad(player->angle)) * ROT_MULTI;
	player->dy = sin(ft_deg_to_rad(player->angle)) * ROT_MULTI;
}
