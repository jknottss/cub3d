/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jknotts           #+#    #+#             */
/*   Updated: 2022/10/29 14:06:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tools.h"

int	ft_string_to_hex(char *input)
{
	int	i;
	int	output;
	int	byte;

	i = 0;
	output = 0x0;
	while (input[i] && input[i] != 'x')
		i++;
	i++;
	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
			byte = input[i] - '0';
		else if (input[i] >= 'a' && input[i] <= 'f')
			byte = input[i] - 87;
		else if (input[i] >= 'A' && input[i] <= 'F')
			byte = input[i] - 55;
		else
			byte = 0;
		output = (output << 4) | byte;
		i++;
	}
	return (output);
}
