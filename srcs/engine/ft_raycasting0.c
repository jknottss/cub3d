/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:41:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_cast_3d_ray(t_engine *engine)
{
	t_3d_data		data;

	data.ray.angle = engine->screen->player.angle - FOV / 2.0;
	data.i = 0;
	while (data.i < engine->max_rays)
	{
		ft_prepare_ray(engine, &data.ray);
		ft_cast_horizontal_ray(engine, &data.ray);
		ft_cast_vertical_ray(engine, &data.ray);
		ft_select_shortest_ray(&data);
		ft_prepare_cam(engine, &data);
		ft_select_texture(engine, &data);
		ft_draw_texture(engine, &data);
		data.i++;
		data.ray.angle += STEP_ANGLE;
	}
}

void	ft_invalid_angle(t_ray *ray, t_player *player)
{
	ray->x = player->x;
	ray->y = player->y;
	ray->step_dist = DISTANCE + 1;
}

t_ray_hit	ft_ray_hit(t_ray *ray, t_player *player, t_map *screen)
{
	while (ray->step_dist < DISTANCE)
	{
		ray->map_x = (int) ray->x / (screen->tile_size);
		ray->map_y = (int) ray->y / (screen->tile_size);
		if (ray->map_y >= 0 && ray->map_y < screen->rows
			&& ray->map_x >= 0 && ray->map_x < screen->columns
			&& screen->map[ray->map_y][ray->map_x] == '1')
			return (ft_ray_hit_area(ray, player));
		else
		{
			ray->x += ray->step_x;
			ray->y += ray->step_y;
			ray->step_dist++;
		}
	}
	return (ft_ray_hit_area(ray, player));
}

t_ray_hit	ft_ray_hit_area(t_ray *ray, t_player *player)
{
	t_ray_hit	ray_hit;

	ray_hit.x = ray->x;
	ray_hit.y = ray->y;
	ray_hit.dist = ft_dist(player, ray->x, ray->y);
	return (ray_hit);
}
