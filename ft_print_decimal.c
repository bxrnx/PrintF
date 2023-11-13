/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:58:12 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/09 17:59:53 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_decimal_len(int n)
{
    int len;

    len = 0;
	if(n == 0)
		len++;
	if (n < 0)
		len = 1;
    while (n)
        {
          n = n/10;
          len++;
        }
    return(len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, 1);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}

int	ft_print_decimal_and_int(float n)
{
	ft_putnbr(n);
	return(decimal_len);
}