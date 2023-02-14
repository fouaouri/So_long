/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:35:56 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/14 23:26:47 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	error(t_builders *param)
{
	(void)param;
	ft_printf("Error!!!\n");
	exit(1);
}

void	error_fd(char *av, t_builders *param)
{
	int	fd;

	(void)param;
	fd = (open(av, O_RDONLY));
	if (fd < 0)
	{
		ft_printf("Error\nmap not found");
		exit(1);
	}
}
