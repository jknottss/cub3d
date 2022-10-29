/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2021/10/04 21:45:05 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

void	*ft_calloc(size_t size)
{
	void	*output;
	char	*tmp;
	size_t	i;

	output = malloc(size);
	if (!output)
		return (NULL);
	i = 0;
	tmp = (char *) output;
	while (i < size)
	{
		*tmp = '\0';
		tmp++;
		i++;
	}
	return (output);
}

void	*ft_calloc_char(size_t size, char c)
{
	void	*output;
	char	*tmp;
	size_t	i;

	output = malloc(size);
	if (!output)
		return (NULL);
	i = 0;
	tmp = (char *) output;
	while (i < size)
	{
		*tmp = c;
		tmp++;
		i++;
	}
	return (output);
}
