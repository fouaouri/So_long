/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fouaouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:36:14 by fouaouri          #+#    #+#             */
/*   Updated: 2023/02/14 23:24:08 by fouaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdarg.h>

# define UNIT_SIZE 50
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef struct s_coordinates
{
	int	i;
	int	j;
	int	height;
	int	width;
	int	p_x;
	int	p_y;
	int	counter;
}t_coordinates;

typedef struct s_builders
{
	void			*mlx;
	void			*mlx_win;
	void			*image;
	void			*player;
	void			*nan;
	void			*exit;
	void			*collect;
	char			*line;
	char			**map;
	char			**check;
	t_coordinates	*coors;
	int				colects;
	int				pcount;
	int				ecount;
	int				moves;
}t_builders;

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

char	*read_file(int fd, char *counter);
char	*put_on_the_line(char *counter);
char	*get_update(char *counter);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr( int n);
int		ft_lower_hex(unsigned long int n);
int		ft_upper_hex(unsigned long int n);
int		ft_pntr(size_t n);
int		ft_unsigned(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_num_hex(unsigned long d);
void	flood_fill(t_builders *p, int x, int y);
void	flood_fille(t_builders *p, int x, int y);
int		check_path(t_builders *param);
int		check_pathe(t_builders *param);
int		end_program(t_builders *p);
void	move_player_right(int keycode, t_builders *param);
void	move_player_left(int keycode, t_builders *param);
void	move_player_down(int keycode, t_builders *param);
void	move_player_up(int keycode, t_builders *param);
int		key_hook(int keycode, t_builders *param);
int		check_wall(t_builders *param, int y, int x);
void	eat_collect(t_builders *param, int y, int x);
void	checkmap(t_builders *param);
void	error(t_builders *param);
void	esc_exit(int keycode, t_builders *param);
void	checkexe(char *av);
char	**get_map(char *av, t_builders *param);
void	parsemap(t_builders *mlx);
void	get_dementions(char *av, t_builders *param);
int		check_exit(t_builders *param, int y, int x);
void	error_fd(char *av, t_builders *param);

#endif