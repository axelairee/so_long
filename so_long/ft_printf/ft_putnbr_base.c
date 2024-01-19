/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:30:20 by abolea            #+#    #+#             */
/*   Updated: 2023/11/27 19:15:17 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_recursive(unsigned long long n, \
char *base, int fd, int i)
{
	int	temp;

	if (n >= ft_strlen(base))
		i = ft_putnbr_base_recursive(n / ft_strlen(base), base, fd, i);
	temp = ft_putchar_fd(base[n % ft_strlen(base)], fd);
	if (temp == -1)
		return (-1);
	i++;
	return (i);
}

int	ft_putnbr_base(unsigned long long n, char *base, int fd)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		if (ft_putchar_fd(base[0], fd) < 0)
			return (-1);
		return (1);
	}
	return (ft_putnbr_base_recursive(n, base, fd, i));
}
