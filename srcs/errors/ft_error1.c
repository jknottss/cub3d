/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:49:27 by                   #+#    #+#             */
/*   Updated: 2022/10/29 12:07:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_error_extension(char *file)
{
	printf("Error\nInvalid file extension [%s].\n", file);
	return (RETURN_ERROR);
}

int	ft_error_char(char c, int row)
{
	printf("Error\nInvalid char [%c] in row %i .cub file by"
		" function ft_check_input_exit_on_error\n", c, row);
	return (RETURN_ERROR);
}

int	ft_error_border(char c, int row, int column, t_map *map)
{
	printf("Error\nMap border open at char [%c] in row %i column %i .cub"
		" file by function ft_check_input_exit_on_error\n", c, row, column);
	ft_free_map(map);
	return (RETURN_ERROR);
}

int	ft_error_player(char c, int row, int column, t_map *map)
{
	printf("Error\nMore than one player on Map char [%c] in row %i column"
		" %i .cub file by function ft_check_input_exit_on_error\n",
		c, row, column);
	ft_free_map(map);
	return (RETURN_ERROR);
}

int	ft_error_no_player(t_map *map)
{
	printf("Error\nNo player on Map .cub file by"
		" function ft_check_input_exit_on_error\n");
	ft_free_map(map);
	return (RETURN_ERROR);
}
