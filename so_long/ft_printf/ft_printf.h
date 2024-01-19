/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:21:50 by abolea            #+#    #+#             */
/*   Updated: 2023/11/28 10:52:15 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
unsigned int	ft_putnbr_u(unsigned int n, int fd, int *i);
unsigned long	ft_print_p(unsigned long args);
int				ft_putnbr_base(unsigned long long n, char *base, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				ft_putstr_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd, int *i);
int				ft_putchar_fd(char c, int fd);

#endif