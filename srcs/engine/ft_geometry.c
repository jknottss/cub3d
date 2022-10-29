/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:35:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_draw_rectangle(t_engine *engine, t_line rectangle)
{
	t_line	line;

	line.start.color = rectangle.start.color;
	line.end.color = rectangle.end.color;
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.start.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.end.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.end.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.start.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
}

void	ft_draw_rectangle_full(t_engine *engine, t_line rectangle)
{
	t_line	line;

	line.start.color = rectangle.start.color;
	line.end.color = rectangle.end.color;
	line.start.x = rectangle.start.x;
	line.end.x = rectangle.end.x;
	while (rectangle.start.y <= rectangle.end.y)
	{
		line.start.y = rectangle.start.y;
		line.end.y = rectangle.start.y;
		ft_draw_line(engine, line);
		rectangle.start.y++;
	}
}
