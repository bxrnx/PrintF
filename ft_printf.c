/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:31:51 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/07 18:45:21 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_sumatorio(int x, ...)
{
	va_list	vargs;
	int		sum;
	int		sig;
	int		i;

	i = 0;
	sum = 0;
	va_start(vargs, x); //Siendo x el número de argumentos del int?
	printf("iniciamoa argumentos : %d\n")
	while(i < x)
	{	
		sig = va_arg(vargs, int);
		printf("el siguiente argumento va a ser : %d/n", sig);
		sum = sum + sig;
	}
	printf("terminamos argumentoos : %d\n");
	va_end(vargs);
	return (sum);
}

int main()
{
	int total = ft_sumatorio(7, 8, 9, 3)
	printf("%d/n", total);
	return 0:
}
