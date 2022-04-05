/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:14:09 by obibby            #+#    #+#             */
/*   Updated: 2022/04/05 18:14:09 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);

int	print_int(char *str, char *flags, int width, int prec)
{
	int	charno;
	int	i;

	charno = 0;
	i = 0;
	while (flags[6] != 1 && flags[5] != 1 && width-- > 0)
		charno += write(1, " ", 1);
	while (flags[6] != 1 && flags[5] == 1 && width-- > 0)
		charno += write(1, "0", 1);
	if (flags[3] == 1 && str[0] != '-')
		charno += write(1, "+", 1);
	if (flags[2] == 1 && str[0] == '-')
		i++;
	while (prec-- > (int)ft_strlen(str))
		charno += write(1, "0", 1);
	while (str[i])
		charno += write(1, &str[i++], 1);
	while (width-- > 0 && flags[6] == 1)
		charno += write(1, " ", 1);
	return (charno);
}

int	ft_int_write(va_list vl, char *flags, int width, int prec)
{
	long long	n;
	char		*str;
	int			charno;

	n = va_arg(vl, long long);
	str = ft_itoa(n);
	charno = 0;
	if (flags[7] == '*')
		width = va_arg(vl, int);
	if (flags[0] == '*')
		prec = va_arg(vl, int);
	if (flags[0] != '\0' || flags[1] != '\0')
		width -= prec;
	if (flags[0] == '\0' && flags[1] == '\0')
		width -= ft_strlen(str);
	charno += print_int(str, flags, width, prec);
	free(str);
	return (charno);
}
