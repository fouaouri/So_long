/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:03:40 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/14 23:45:44 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_mlx_fun(t_builders *param)
{
		param->mlx = mlx_init();
		param->mlx_win = mlx_new_window(param->mlx, param->coors->width
			* UNIT_SIZE, param->coors->height * UNIT_SIZE, "window");
		param->image = mlx_xpm_file_to_image(param->mlx,
			" textures/walls.xpm", &param->coors->i, &param->coors->j);
		param->player = mlx_xpm_file_to_image(param->mlx,
			" textures/player.xpm", &param->coors->i, &param->coors->j);
		param->nan = mlx_xpm_file_to_image(param->mlx,
			" textures/grass.xpm", &param->coors->i, &param->coors->j);
		param->collect = mlx_xpm_file_to_image(param->mlx,
			" textures/collect.xpm", &param->coors->i, &param->coors->j);
		param->exit = mlx_xpm_file_to_image(param->mlx,
			" textures/door.xpm", &param->coors->i, &param->coors->j);
}

int	main(int ac, char **av)
{
	t_builders		param;
	t_coordinates	coor;

	if (ac == 2)
	{		
		coor.j = 0;
		coor.i = 0;
		param.coors = &coor;
		checkexe(av[1]);
		get_dementions(av[1], &param);
		get_mlx_fun(&param);
		param.map = get_map(av[1], &param);
		param.check = get_map(av[1], &param);
		checkmap(&param);
		flood_fill(&param, coor.p_x, coor.p_y);
		check_path(&param);
		flood_fille(&param, coor.p_x, coor.p_y);
		check_pathe(&param);
		parsemap(&param);
		mlx_key_hook(param.mlx_win, &key_hook, &param);
		mlx_hook(param.mlx_win, 17, 0l, end_program, &param);
		mlx_loop(param.mlx);
		//system("leaks so_long");
	}
	else
		ft_printf("wrong args !");
}
