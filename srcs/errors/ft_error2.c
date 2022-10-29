/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:49:27 by                   #+#    #+#             */
/*   Updated: 2022/10/29 12:07:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_error_map_file(char *s, int row, t_map *map)
{
	printf("Error\nInvalid identifier [%s] in map %i .cub file by"
		" function ft_check_input_exit_on_error\n", s, row);
	ft_free_map(map);
	return (RETURN_ERROR);
}
