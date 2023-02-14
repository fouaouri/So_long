/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_of_animations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:05:52 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:02:14 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	check_wall(t_builders *param, int y, int x)
{
	return (param->map[y][x] != '1' && param->map[y][x] != 'E');
}

int	check_exit(t_builders *param, int y, int x)
{
	return (param->map[y][x] == 'E' && param->colects == 0);
}

void	eat_collect(t_builders *param, int y, int x)
{
	if (param->map[y][x] == 'C')
	{
		param->map[y][x] = '0';
		param->colects--;
	}
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->nan,
		param->coors->p_x * UNIT_SIZE, param->coors->p_y * UNIT_SIZE);
}

void	esc_exit(int keycode, t_builders *param)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(param->mlx, param->mlx_win);
		ft_printf("you end the game");
		exit(1);
	}
}
