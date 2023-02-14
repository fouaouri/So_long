/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:51:47 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:03:27 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_num_hex(unsigned long d)
{
	int	i;

	i = 0;
	if (d == 0)
		return (1);
	while (d > 0)
	{
		i++;
		d = d / 16;
	}
	return (i);
}

int	ft_upper_hex(unsigned long int n)
{
	char	*tab;

	tab = "0123456789ABCDEF";
	if (n >= 16)
		ft_upper_hex(n / 16);
	ft_putchar(tab[n % 16]);
	return (ft_num_hex(n));
}
