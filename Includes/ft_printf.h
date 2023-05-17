/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:44:39 by mmarie            #+#    #+#             */
/*   Updated: 2023/03/21 13:57:14 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *str, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbrhexa(unsigned int n, char c);
int	ft_putptr(unsigned long n);
int	ft_putnbrhexlo(unsigned long n);
int	ft_un_putnbr(unsigned int n);
int	check(const char c, va_list args);
int	ft_printf(const char *str, ...);

#endif
