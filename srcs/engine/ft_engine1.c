/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:35:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_error_engine_init(char *function, char *variable,
	t_engine *engine, int error)
{
	printf("Error\nCould not initalize %s by function: %s\n",
		variable, function);
	if (error >= 10)
		mlx_destroy_image(engine->mlx, engine->so_tex.img);
	if (error >= 9)
		mlx_destroy_image(engine->mlx, engine->ea_tex.img);
	if (error >= 8)
		mlx_destroy_image(engine->mlx, engine->we_tex.img);
	if (error >= 7)
		mlx_destroy_image(engine->mlx, engine->no_tex.img);
	if (error >= 5)
		mlx_destroy_image(engine->mlx, engine->img1.img);
	if (error >= 3)
		mlx_destroy_image(engine->mlx, engine->img0.img);
	if (error >= 2)
		mlx_destroy_window(engine->mlx, engine->window);
	ft_free_map(engine->screen);
	free(engine->file);
	exit(RETURN_ERROR);
}

int	ft_engine_destroy(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->img0.img);
	mlx_destroy_image(engine->mlx, engine->img1.img);
	mlx_destroy_image(engine->mlx, engine->no_tex.img);
	mlx_destroy_image(engine->mlx, engine->we_tex.img);
	mlx_destroy_image(engine->mlx, engine->so_tex.img);
	mlx_destroy_image(engine->mlx, engine->ea_tex.img);
	mlx_destroy_window(engine->mlx, engine->window);
	ft_free_map(engine->screen);
	free(engine->file);
	exit(1);
}
