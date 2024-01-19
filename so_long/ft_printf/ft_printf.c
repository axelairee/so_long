/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:52:52 by abolea            #+#    #+#             */
/*   Updated: 2023/11/28 16:47:25 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_findformat(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i = ft_putchar_fd(va_arg(args, int), 1);
	if (*format == 'i' || *format == 'd')
		i = ft_putnbr_fd(va_arg(args, int), 1, &i);
	if (*format == 's')
		i = ft_putstr_fd(va_arg(args, char *), 1);
	if (*format == 'u')
		i = ft_putnbr_u(va_arg(args, unsigned int), 1, &i);
	if (*format == 'x')
		i = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 1);
	if (*format == 'X')
		i = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
	if (*format == 'p')
		i = ft_print_p(va_arg(args, unsigned long));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format) != NULL)
				i += ft_findformat(format, args);
			if (*format == '%')
				i += ft_putchar_fd('%', 1);
		}
		else
			i += ft_putchar_fd(*format, 1);
		if (i < 0)
			return (-1);
		format++;
	}
	va_end (args);
	return (i);
}
