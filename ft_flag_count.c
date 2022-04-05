/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:25:01 by obibby            #+#    #+#             */
/*   Updated: 2022/03/27 00:25:01 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_count_dec(long x)
{
	int	count;

	count = 0;
	while (x != 0)
	{
		x = x / 10;
		count++;
	}
	return (count);
}

void	ft_flag_count(char *flags, int width, int prec)
{
	int	i;

	i = 0;
	flags[17] = 0;
	while (i < 17)
	{
		if (flags[i] != '\0')
			flags[17] += 1;
		i++;
	}
	if (flags[7] != '\0')
		flags[17] += char_count_dec(width) - 1;
	if (flags[0] == 1)
		flags[17] += 1;
	if (flags[1] != '\0')
		flags[17] += char_count_dec(prec);
	return ;
}
