/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:49:27 by                   #+#    #+#             */
/*   Updated: 2022/10/29 12:10:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_error_arguments(void)
{
	printf("Error\nProgram needs 2 arguments.\n./cub3D <file_to_open>.cub\n");
	return (RETURN_ERROR);
}

int	ft_error_malloc(char *function, char *variable, size_t size)
{
	printf("Error\nNot enough memory for allocating space for [%s] [%zu]"
		"bytes by function: %s\n", variable, size, function);
	return (RETURN_ERROR);
}

int	ft_error_file(char *function, char *file)
{
	printf("Error\nCan not open file [%s] by function: %s.\n", file,
		function);
	return (RETURN_ERROR);
}

int	ft_error_file_result(char *function, char *file, int fd)
{
	printf("Error\nEmpty file or read failed [%s] by function: %s\n",
		file, function);
	close(fd);
	return (RETURN_ERROR);
}

void	ft_error_split(t_map *screen, char *input)
{
	ft_error_malloc("ft_split", "string_array", 0);
	free(input);
	free(screen);
	exit(RETURN_ERROR);
}
