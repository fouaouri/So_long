/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:44:29 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:03:24 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_num(unsigned long d)
{
	int	i;

	i = 0;
	if (d == 0)
		return (1);
	while (d > 0)
	{
		i++;
		d = d / 10;
	}
	return (i);
}

char	*ft_unsigned_itoa(unsigned long int n)
{
	char	*str;
	long	len;

	len = ft_num(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
		len--;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	return (str);
}

int	ft_unsigned(unsigned int n)
{
	char	*s;
	int		len;

	s = ft_unsigned_itoa(n);
	len = ft_putstr(s);
	free (s);
	return (len);
}
