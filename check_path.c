/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:54:48 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:02:18 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_builders *p, int x, int y)
{
	p->check[y][x] = 'F';
	if ((p->check[y - 1][x] == '0' || p->check[y - 1][x] == 'C'))
		flood_fill(p, x, y - 1);
	if ((p->check[y + 1][x] == '0' || p->check[y + 1][x] == 'C'))
		flood_fill(p, x, y + 1);
	if ((p->check[y][x + 1] == '0' || p->check[y][x + 1] == 'C'))
		flood_fill(p, x + 1, y);
	if ((p->check[y][x - 1] == '0' || p->check[y][x - 1] == 'C'))
		flood_fill(p, x - 1, y);
}

void	flood_fille(t_builders *p, int x, int y)
{
	p->check[y][x] = 'X';
	if ((p->check[y - 1][x] == '0' || p->check[y - 1][x] == 'E')
		|| (p->check[y - 1][x] == 'F'))
		flood_fille(p, x, y - 1);
	if ((p->check[y + 1][x] == '0' || p->check[y + 1][x] == 'E')
		|| (p->check[y + 1][x] == 'F'))
		flood_fille(p, x, y + 1);
	if ((p->check[y][x + 1] == '0' || p->check[y][x + 1] == 'E')
		|| (p->check[y][x + 1] == 'F'))
		flood_fille(p, x + 1, y);
	if ((p->check[y][x - 1] == '0' || p->check[y][x - 1] == 'E')
		|| (p->check[y][x - 1] == 'F'))
		flood_fille(p, x - 1, y);
}

int	check_path(t_builders *param)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < param->coors->height)
	{
		x = 0;
		while (x < param->coors->width)
		{
			if (param->check[y][x] == 'C')
			{
				ft_printf("Error..invalid path !");
				exit(1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_pathe(t_builders *param)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < param->coors->height)
	{
		x = 0;
		while (x < param->coors->width)
		{
			if (param->check[y][x] == 'E')
			{
				ft_printf("Error..invalid path !");
				exit(1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	end_program(t_builders *p)
{
	(void)p;
	ft_printf("you end the game");
	exit(1);
	return (0);
}
