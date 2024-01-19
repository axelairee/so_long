/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:38:56 by abolea            #+#    #+#             */
/*   Updated: 2023/11/27 18:47:21 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		if (ft_putstr_fd("(null)", 1) < 0)
			return (-1);
		return (6);
	}
	if (write(fd, s, ft_strlen(s)) < 0)
		return (-1);
	return (ft_strlen(s));
}
