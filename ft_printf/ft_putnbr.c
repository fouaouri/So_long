/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:43:01 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:03:07 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_numlen(long d)
{
	int	i;

	i = 0;
	if (d == 0)
		return (1);
	if (d < 0)
	{
		i++;
		d = d * (-1);
	}
	while (d > 0)
	{
		i++;
		d = d / 10;
	}
	return (i);
}

char	*ft_itoa(long int n)
{
	char	*str;
	long	len;

	len = ft_numlen (n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
		len--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	return (str);
}

int	ft_putnbr( int n)
{
	char	*s;
	int		len;

	len = 0;
	s = ft_itoa(n);
	len += ft_putstr(s);
	free (s);
	return (len);
}
