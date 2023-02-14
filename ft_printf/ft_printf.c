/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:07:32 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:02:59 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_format(va_list i, char form)
{
	int	j;

	j = 0;
	if (form == 'c')
		j += ft_putchar(va_arg(i, int));
	if (form == 's')
		j += ft_putstr(va_arg(i, char *));
	if (form == 'p')
		j += ft_pntr(va_arg(i, unsigned long int));
	if ((form == 'd' || form == 'i'))
		j += ft_putnbr(va_arg(i, int));
	if (form == 'u')
		j += ft_unsigned(va_arg(i, unsigned int));
	if (form == 'x')
		j += ft_lower_hex(va_arg(i, unsigned int));
	if (form == 'X')
		j += ft_upper_hex(va_arg(i, unsigned int));
	if (form == '%')
		j += ft_putchar('%');
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	v;
	int		i;
	int		k;

	i = 0;
	k = 0;
	va_start(v, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			k += ft_format(v, str[i + 1]);
			i++;
		}
		else
			k += ft_putchar(str[i]);
		i++;
	}
	va_end(v);
	return (k);
}
