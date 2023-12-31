/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemelend <bemelend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:35:28 by bemelend          #+#    #+#             */
/*   Updated: 2023/11/22 14:33:12 by bemelend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ('\0');
	while (s[i++])
	{
		write (1, &s[i], 1);
	}
	return (i);
}
