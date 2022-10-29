/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:41:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_check_map_moveable(t_map *screen, t_line *line, int *free_x);
static void	ft_calculate_xy(t_line *line, t_player player, char calc);

void	ft_check_player_area(t_engine *engine)
{
	double		sx;
	double		sy;
	t_player	*player;
	t_line		line;

	player = &engine->screen->player;
	line.start.x = player->x;
	line.start.y = player->y;
	ft_set_line_color(&line, 0x00FFFF00);
	ft_calculate_xy(&line, *player, '+');
	ft_check_map_moveable(engine->screen, &line, &player->free_w);
	ft_calculate_xy(&line, *player, '-');
	ft_check_map_moveable(engine->screen, &line, &player->free_s);
	sx = cos(ft_deg_to_rad(player->angle - 90)) * MOV_MULTI;
	sy = sin(ft_deg_to_rad(player->angle - 90)) * MOV_MULTI;
	line.end.x = player->x + sx * ROT_MULTI;
	line.end.y = player->y + sy * ROT_MULTI;
	ft_check_map_moveable(engine->screen, &line, &player->free_a);
	line.end.x = player->x - sx * ROT_MULTI;
	line.end.y = player->y - sy * ROT_MULTI;
	ft_check_map_moveable(engine->screen, &line, &player->free_d);
}

static void	ft_calculate_xy(t_line *line, t_player player, char calc)
{
	if (calc == '+')
	{
		line->end.x = player.x + player.dx * ROT_MULTI;
		line->end.y = player.y + player.dy * ROT_MULTI;
	}
	else if (calc == '-')
	{
		line->end.x = player.x - player.dx * ROT_MULTI;
		line->end.y = player.y - player.dy * ROT_MULTI;
	}
}

static void	ft_check_map_moveable(t_map *screen, t_line *line, int *free_x)
{
	int	mx;
	int	my;

	mx = (int) line->end.x / (screen->tile_size);
	my = (int) line->end.y / (screen->tile_size);
	if (screen->map[my][mx] != '1')
		*free_x = 0;
	else
		*free_x = 1;
}
