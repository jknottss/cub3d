/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:06:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

char	*ft_read_file(int fd)
{
	char		*input;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		read_result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	input = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!input)
		return (NULL);
	input[0] = '\0';
	while (1)
	{
		if (buffer[0])
			input = ft_realloc(input, buffer, 1, 0);
		read_result = read(fd, (void *) buffer, BUFFER_SIZE);
		if (read_result == -1 || (read_result == 0 && input[0] == '\0'))
		{
			free(input);
			return (NULL);
		}
		buffer[read_result] = '\0';
		if (read_result == 0)
			return (input);
	}
}
