/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:37:52 by obibby            #+#    #+#             */
/*   Updated: 2022/04/06 12:50:20 by obibby           ###   ########.fr       */
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

int	ft_ptr_count(uintptr_t p)
/*int	width_write_ptr(int width, char *flags, int charno, uintptr_t addr)
{
	int	count;

	count = 0;
	while (addr != 0)
	{
		addr = addr / 16;
		count++;
	}
	width -= count;
	if (flags[7] == 0 && flags[6] == 0)
	{
		while (count++ < 16)
			charno += write(1, "0", 1);
	}
	while (width-- > 0)
		charno += write(1, " ", 1);
	return (charno);
}*/

int	ft_ptr_write(va_list vl, char *flags, int width)
{
	uintptr_t	addr;
	int			charno;

	addr = va_arg(vl, uintptr_t);
	if (!addr)
		addr = 0;
	charno = 0;
	width -= ft_strlen(addr);
	while (flags[6] == 0 && width-- > 0)
		charno += write(1, " ", 1);
	charno += write(1, "0x", 2);
	charno += ft_putptr(addr);
	while (flags[6] == 1 && width > 0)
		charno += write(1, " ", 1);
	return (charno);
}
