/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:31:14 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/13 03:02:10 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	error_msg(t_builders *param)
{
	if (param->pcount != 1)
	{
		ft_printf("error\ncheck player!");
		exit(1);
	}
	if (param->ecount != 1)
	{
		ft_printf("error\ncheck exit!");
		exit(1);
	}
	if (param->colects < 1)
	{
		ft_printf("error\nthere is 0 collect!");
		exit(1);
	}
}

void	p_count(t_builders *param)
{
	param->coors->i = 0;
	while (param->coors->i < param->coors->height)
	{
		param->coors->j = 0;
		while (param->coors->j < param->coors->width)
		{
			if (param->map[param->coors->i][param->coors->j] == 'C')
				param->colects += 1;
			else if (param->map[param->coors->i][param->coors->j] == 'P')
			{
				param->pcount += 1;
				param->coors->p_x = param->coors->j;
				param->coors->p_y = param->coors->i;
			}
			else if (param->map[param->coors->i][param->coors->j] == 'E')
				param->ecount += 1;
			else if (param->map[param->coors->i][param->coors->j] != '0'
				&& param->map[param->coors->i][param->coors->j] != '1')
				error(param);
			param->coors->j++;
		}
		param->coors->i++;
	}
}

void	t_b_walls(t_builders *param)
{
	param->coors->i = 0;
	param->coors->j = 0;
	while (param->map[0][param->coors->i])
	{
		if (param->map[0][param->coors->i] != '1')
		{
			ft_printf("top walls broken !");
			exit(1);
		}
		param->coors->i++;
		if (param->map[0][param->coors->i] == '\n')
			break ;
	}
	param->coors->i = 0;
	while (param->map[0][param->coors->i])
	{
		if (param->map[param->coors->height - 1][param->coors->i] != '1')
		{
			ft_printf("bot walls broken !");
			exit(1);
		}
		param->coors->i++;
		if (param->map[0][param->coors->i] == '\n')
			break ;
	}
}

void	r_l_walls(t_builders *param)
{
	param->coors->i = 0;
	while (param->coors->i < param->coors->height)
	{
		if (param->map[param->coors->i][param->coors->width - 1] != '1')
		{
			ft_printf("right walls broken !");
			exit(1);
		}
		param->coors->i++;
	}
	param->coors->i = 0;
	while (param->coors->i < param->coors->height)
	{
		if (param->map[param->coors->i][0] != '1')
		{
			ft_printf("left walls broken !");
			exit(1);
		}
		param->coors->i++;
	}
}

void	checkmap(t_builders *param)
{
	int	count;

	count = 0;
	param->coors->i = 0;
	while (param->coors->i < param->coors->height)
	{
		param->coors->j = 0;
		count = 0;
		while (param->map[param->coors->i][param->coors->j] != '\n'
			&& param->map[param->coors->i][param->coors->j] != '\0')
		{
			count++;
			param->coors->j++;
		}	
		if (count != param->coors->width)
			error(param);
		param->coors->i++;
	}
	t_b_walls(param);
	r_l_walls(param);
	p_count(param);
	error_msg(param);
}
