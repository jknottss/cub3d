/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 15:18:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static void	ft_exit_malloc_error(char *s);

t_map	*ft_read_input_map(char *file)
{
	t_map	*output;
	int		fd;
	char	*read_file_result;

	if (!ft_strcmp(&file[ft_strlen(file) - 4], ".cub"))
		exit(ft_error_extension(file));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(ft_error_file("ft_read_input_map", file));
	read_file_result = ft_read_file(fd);
	if (!read_file_result)
		exit(ft_error_file_result("ft_read_file", file, fd));
	close(fd);
	output = (t_map *) ft_calloc(sizeof(t_map));
	ft_init_struct_t_map(output);
	if (!output)
		ft_exit_malloc_error(read_file_result);
	ft_create_map_array(read_file_result, output);
	return (output);
}

static void	ft_exit_malloc_error(char *s)
{
	free(s);
	exit(ft_error_malloc("ft_read_input_map", "output", sizeof(t_map)));
}
