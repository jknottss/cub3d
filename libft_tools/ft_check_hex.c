/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:06:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

int	ft_check_hex(const char *input)
{
	int	i;

	if (ft_strcmp(",0x", input) != 0)
		return (0);
	i = 3;
	while (input[i])
	{
		if ((input[i] < '0' && input[i] > '9')
			&& (input[i] < 'a' && input[i] > 'f')
			&& (input[i] < 'A' && input[i] > 'F'))
			return (0);
		i++;
	}
	return (1);
}
