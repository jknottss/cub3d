/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:49:27 by                   #+#    #+#             */
/*   Updated: 2022/10/29 12:07:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_error_input(t_map *screen, char **string_array)
{
	printf("Error\nEmpty lines or different nr. of columns in rows in "
		"map file by function: ft_create_map_array.\n");
	ft_free_char_array(string_array);
	free(screen);
	exit(RETURN_ERROR);
}

void	ft_error_map(t_map *screen, char **string_array)
{
	ft_error_malloc("ft_create_map_array", "screen->map",
		sizeof(t_3d_point *) * screen->rows);
	ft_free_char_array(string_array);
	free(screen);
	exit(RETURN_ERROR);
}

void	ft_error_map_row(t_map *screen, char **string_array, int i_row)
{
	ft_error_malloc("ft_create_map_array", "screen->map[i_row]",
		sizeof(t_3d_point *) * screen->columns);
	ft_free_char_array(string_array);
	while (i_row > 0)
	{
		i_row--;
		free(screen->map[i_row]);
	}
	free(screen->map);
	free(screen);
	exit(RETURN_ERROR);
}
