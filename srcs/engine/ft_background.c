/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:06:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_background(t_engine *engine)
{
	t_line	line;

	line.start.x = engine->offset.x;
	line.start.y = engine->offset.y;
	line.end.x = engine->max_line_w;
	line.end.y = (int) engine->offset.y + engine->max_line_h / 2.0;
	ft_set_line_color(&line, engine->screen->ceiling_color);
	ft_draw_rectangle_full(engine, line);
	line.start.y = line.end.y + 1;
	line.end.x = engine->max_line_w;
	line.end.y = engine->offset.y + engine->max_line_h;
	ft_set_line_color(&line, engine->screen->floor_color);
	ft_draw_rectangle_full(engine, line);
}
