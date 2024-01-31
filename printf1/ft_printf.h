/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:05 by bemelend          #+#    #+#             */
/*   Updated: 2024/01/31 17:07:48 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

void	ft_print_percentage(int *byte);
int		ft_putchar(char c, int *byte);
void	ft_putnbr(int n, int *byte);
int		ft_print_decimal_and_int(long long n, int *byte);
char	ft_decimaltohexdigit(int digit);
int		ft_hex_len(uintptr_t numhex);
int		ft_decimaltohexreverse(uintptr_t decimal, char hex[]);
int		ft_print_pointer(uintptr_t pointeraddress, int *byte);
int		ft_print_string(char *s, int *byte);
void	ft_print_unsigned(unsigned long n, int *byte);
void	ft_free_ptr(char **ptr);
char	decimal_to_hex_digit(int digit, char type);
void	ft_decimal_to_hex_reverse(unsigned int decimal, char hex[], char type);
int		ft_print_x(unsigned int n, char type, int *byte);
void	ft_select_format(va_list variables_inf, const char str, int *byte);
int		ft_printf(const char *str, ...);

#endif