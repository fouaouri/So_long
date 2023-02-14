/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:14:23 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/14 23:25:48 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	get_dementions(char *av, t_builders *param)
{
	int			fd;
	int			i;
	char		*line;

	fd = (open(av, O_RDONLY));
	error_fd(av, param);
	param->line = ft_calloc(1, 1);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		i++;
		if (!line)
			break ;
		param->line = ft_strjoin(param->line, line);
		free(line);
	}
	param->coors->height = i - 1;
	i = 0;
	while (param->line[i] != '\n' && param->line[i] != '\0')
		i++;
	param->coors->width = i;
}

char	**get_map(char *av, t_builders *param)
{
	int		index;
	char	*line;
	char	**all;
	int		fd;

	index = 0;
	fd = open(av, O_RDONLY);
	all = ft_calloc(sizeof(char *), (param->coors->height + 1));
	while (1)
	{
		line = get_next_line(fd);
		all[index++] = line;
		if (line == NULL)
			break ;
	}
	close(fd);
	return (all);
}

void	checkexe(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i -= 1;
	if (av[i] != 'r' || av[i - 1] != 'e'
		|| av[i - 2] != 'b' || av[i - 3] != '.')
	{
		ft_printf("wrong extention");
		exit(1);
	}
}

void	parsemap_j(t_builders *mlx)
{
	mlx->coors->j = 0;
	while (mlx->map[mlx->coors->i][mlx->coors->j])
	{	
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->nan, mlx->coors->j * UNIT_SIZE, mlx->coors->i * UNIT_SIZE);
		if (mlx->map[mlx->coors->i][mlx->coors->j] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->image,
				mlx->coors->j * UNIT_SIZE, mlx->coors->i * UNIT_SIZE);
		else if (mlx->map[mlx->coors->i][mlx->coors->j] == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->collect,
				mlx->coors->j * UNIT_SIZE, mlx->coors->i * UNIT_SIZE);
		else if (mlx->map[mlx->coors->i][mlx->coors->j] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->exit,
				mlx->coors->j * UNIT_SIZE, mlx->coors->i * UNIT_SIZE);
		else if (mlx->map[mlx->coors->i][mlx->coors->j] == 'P')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player,
				mlx->coors->j * UNIT_SIZE, mlx->coors->i * UNIT_SIZE);
			mlx->coors->p_x = mlx->coors->j;
			mlx->coors->p_y = mlx->coors->i;
		}
		mlx->coors->j++;
	}
}

void	parsemap(t_builders *mlx)
{
	mlx->coors->i = 0;
	while (mlx->map[mlx->coors->i] != NULL)
	{
		parsemap_j(mlx);
		mlx->coors->i++;
	}
}
