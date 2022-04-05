/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:54:10 by obibby            #+#    #+#             */
/*   Updated: 2022/03/26 14:54:10 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_write_hex(int width, char *flags)
{
	int	charno;

	charno = 0;
	while (width > 0)
	{
		if (flags[5] == 1 && flags[6] == '\0' && flags[4] == '\0')
			charno += write(1, "0", 1);
		else if (flags[4] == '\0')
			charno += write(1, " ", 1);
		width--;
	}
	if (flags[4] == 1 && flags[14] == 1)
		charno += write(1, "0x", 2);
	if (flags[4] == 1 && flags[15] == 1)
		charno += write(1, "0X", 2);
	return (charno);
}

int	hexa_conv(long x, char *flags)
{
	char	hexastr[100];
	long	rem;
	int		i;
	int		charno;

	rem = 0;
	i = 0;
	charno = 0;
	while (x != 0)
	{
		rem = x % 16;
		if (rem < 10)
			hexastr[i++] = rem + '0';
		else if (flags[15] == 1)
			hexastr[i++] = rem + '7';
		else
			hexastr[i++] = rem + 'W';
		x = x / 16;
	}
	i -= 1;
	while (i >= 0)
		charno += write(1, &hexastr[i--], 1);
	return (charno);
}

int	char_count_hex(long x)
{
	int	count;

	count = 0;
	while (x != 0)
	{
		x = x / 16;
		count++;
	}
	return (count);
}

int	ft_hexa_write(va_list vl, char *flags, int width, int prec)
{
	long	x;
	int		count;
	int		charno;

	x = va_arg(vl, int);
	count = char_count_hex(x);
	charno = 0;
	if (flags[1] == 1 && prec > count)
		width -= prec;
	else
		width -= count;
	if ((width > 0 && flags[6] == '\0') || flags[4] == 1)
		charno += width_write_hex(width, flags);
	while (count < prec)
	{
		charno += write(1, "0", 1);
		prec--;
	}
	charno += hexa_conv(x, flags);
	if (width > 0 && flags[6] == 1)
		charno += width_write_hex(width, flags);
	return (charno);
}
