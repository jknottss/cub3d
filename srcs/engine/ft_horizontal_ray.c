/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horyzontal_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:41:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_ray_upward(t_ray *ray, t_player *player, int tile_size);
static void	ft_ray_downward(t_ray *ray, t_player *player, int tile_size);

void	ft_cast_horizontal_ray(t_engine *engine, t_ray *ray)
{
	t_player	*player;

	player = &engine->screen->player;
	ray->step_dist = 0;
	if (ray->angle > 180.0)
		ft_ray_upward(ray, player, engine->screen->tile_size);
	else if (ray->angle < 180.0)
		ft_ray_downward(ray, player, engine->screen->tile_size);
	if (ray->angle == 0.0 || ray->angle == 180.0 || ray->angle == 360.0)
		ft_invalid_angle(ray, player);
	ray->hori = ft_ray_hit(ray, player, engine->screen);
}

static void	ft_ray_upward(t_ray *ray, t_player *player, int tile_size)
{
	double		atan;

	atan = -1 / tan(ft_deg_to_rad(ray->angle));
	ray->y = (((int) player->y / (tile_size)) * (tile_size)) - 0.0001;
	ray->x = (player->y - ray->y) * atan + player->x;
	ray->step_y = - (tile_size);
	ray->step_x = (tile_size) * atan;
}

static void	ft_ray_downward(t_ray *ray, t_player *player, int tile_size)
{
	double		atan;

	atan = -1 / tan(ft_deg_to_rad(ray->angle));
	ray->y = (((int) player->y / (tile_size)) * (tile_size)) + tile_size;
	ray->x = (player->y - ray->y) * atan + player->x;
	ray->step_y = tile_size;
	ray->step_x = - (tile_size) * atan;
}
