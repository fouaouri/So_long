/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:43:30 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:02:05 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_right(int keycode, t_builders *param)
{
	if (keycode == RIGHT
		&& check_wall(param, param->coors->p_y, param->coors->p_x + 1))
	{
		param->coors->p_x++;
		param->moves++;
		ft_printf("move %d\n", param->moves);
	}
	else if (keycode == RIGHT
		&& check_exit(param, param->coors->p_y, param->coors->p_x + 1))
	{
		ft_printf("you end the game");
		exit(0);
	}
}

void	move_player_left(int keycode, t_builders *param)
{
	if (keycode == LEFT
		&& check_wall(param, param->coors->p_y, param->coors->p_x - 1))
	{
		param->coors->p_x--;
		param->moves++;
		ft_printf("move %d\n", param->moves);
	}
	else if (keycode == LEFT
		&& check_exit(param, param->coors->p_y, param->coors->p_x - 1))
	{
		ft_printf("you end the game");
		exit(0);
	}
}

void	move_player_down(int keycode, t_builders *param)
{
	if (keycode == DOWN
		&& check_wall(param, param->coors->p_y + 1, param->coors->p_x))
	{
		param->coors->p_y++;
		param->moves++;
		ft_printf("move %d\n", param->moves);
	}
	else if (keycode == DOWN
		&& check_exit(param, param->coors->p_y + 1, param->coors->p_x))
	{
		ft_printf("you end the game");
		exit(0);
	}
}

void	move_player_up(int keycode, t_builders *param)
{
	if (keycode == UP
		&& check_wall(param, param->coors->p_y - 1, param->coors->p_x))
	{
		param->moves++;
		ft_printf("move %d\n", param->moves);
		param->coors->p_y--;
	}
	else if (keycode == UP
		&& check_exit(param, param->coors->p_y - 1, param->coors->p_x))
	{
		ft_printf("you end the game");
		exit(0);
	}
}

int	key_hook(int keycode, t_builders *param)
{
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->nan,
		param->coors->p_x * UNIT_SIZE, param->coors->p_y * UNIT_SIZE);
	esc_exit(keycode, param);
	move_player_right(keycode, param);
	move_player_left(keycode, param);
	move_player_down(keycode, param);
	move_player_up(keycode, param);
	eat_collect(param, param->coors->p_y, param->coors->p_x);
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->player,
		param->coors->p_x * UNIT_SIZE, param->coors->p_y * UNIT_SIZE);
	return (0);
}
