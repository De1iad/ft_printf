/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:37:52 by obibby            #+#    #+#             */
/*   Updated: 2022/04/05 12:37:52 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t addr)
{
	char	hexastr[100];
	long	rem;
	int		i;
	int		charno;

	rem = 0;
	i = 0;
	charno = 0;
	while (addr != 0)
	{
		rem = addr % 16;
		if (rem < 10)
			hexastr[i++] = rem + '0';
		else
			hexastr[i++] = rem + 'W';
		addr = addr / 16;
	}
	i -= 1;
	while (i >= 0)
		charno += write(1, &hexastr[i--], 1);
	return (charno);
}

int	width_write_ptr(int width, char *flags, int charno, uintptr_t addr)
{
	int	count;

	count = 0;
	while (addr != 0)
	{
		addr = addr / 16;
		count++;
	}
	width -= count;
	if (flags[7] == '\0' && flags[6] == '\0')
	{
		while (count++ < 16)
			charno += write(1, "0", 1);
	}
	while (width-- > 0)
		charno += write(1, " ", 1);
	return (charno);
}

int	ft_ptr_write(va_list vl, char *flags, int width)
{
	uintptr_t	addr;
	int			charno;

	addr = va_arg(vl, uintptr_t);
	charno = 0;
	if (flags[6] == '\0')
		charno += width_write_ptr(width, flags, charno, addr);
	charno += ft_putptr(addr);
	if (width > 0 && flags[6] == 1)
		charno += width_write_ptr(width, flags, charno, addr);
	return (charno);
}
