/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:31:51 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/09 13:54:56 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sumatorio(int x, ...)
{
	va_list	vargs;
	int		sum;
	int		sig;
	int		i;

	i = 0;
	sum = 0;
	va_start(vargs, x);
	printf("iniciamoa argumentos : %d\n", x);
	while(i++ < x)
	{
		sig = va_arg(vargs, int);
		printf("el siguiente argumento va a ser : %d\n", sig);
		sum = sum + sig;
	}
	printf("terminamos argumentos : %d\n", sum);
	va_end(vargs);
	return (sum);
}

int main()
{
	int total = ft_sumatorio(7, 8, 9, 3);
	printf("%d\n", total);
	return (0);
}
