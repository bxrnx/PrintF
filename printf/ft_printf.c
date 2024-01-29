/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:41:17 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/09 18:11:38 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void ft_select_format(va_list variables_inf, const char *str, int *byte)
{
	int i;

	i = 0;
	if (str[i] == '%')
		ft_printf_percentaje(byte); //listo
	if (str[i] == 'c')
		ft_putchar(va_arg(variables_inf, int), byte); //listo
	if (str[i] == 'd' || str[i] == 'i')
		ft_print_decimal_and_int(va_arg(variables_inf, int), byte); //listo
	if (str[i] == 'p')
		ft_print_pointer(va_arg(variables_inf, unsigned long long), byte); //listo
	if(str[i] == 's')
		ft_print_string(va_arg(variables_inf, char*), byte);
	if(str[i] == 'u')
		ft_print_unsigned(va_arg(variables_inf, unsigned int), "0123456789", byte);
	if(str[i] == 'x' || str[i] == 'X')
		ft_print_x(va_arg(variables_inf, unsigned int), "0123456789abcdefABCDEF", byte);
}

int ft_printf(const char *str, ...)
{
	va_list variables_inf;
	int i;
	int bytedev;

	bytedev;
	va_start(variables_inf, str); // en arg se almacenan todos los argumentos dsp de str; es decir todos los variables estan en arg.
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
			select_format(str[++i], variables_inf, &bytedev);
		else
			i++;
	}
	va_end(variables_inf);
	return(bytedev);
}

int main()
{
	
}
