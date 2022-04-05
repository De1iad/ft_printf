/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:24:43 by obibby            #+#    #+#             */
/*   Updated: 2022/04/05 21:24:43 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_flag_count(char *flags, int width, int prec);
int		ft_char_write(va_list vl, char *flags, int width);
int		ft_hexa_write(va_list vl, char *flags, int width, int prec);
int		ft_int_write(va_list vl, char *flags, int width, int prec);
int		ft_ptr_write(va_list vl, char *flags, int width);
int		ft_str_write(va_list vl, char *flags, int width, int prec);

#endif