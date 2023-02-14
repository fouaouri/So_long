/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:50:31 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:02:49 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_lower_hex(unsigned long int n)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (n >= 16)
		ft_lower_hex(n / 16);
	ft_putchar(tab[n % 16]);
	return (ft_num_hex(n));
}
