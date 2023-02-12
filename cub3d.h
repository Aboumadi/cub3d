/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:04:22 by aboumadi          #+#    #+#             */
/*   Updated: 2022/10/23 20:40:06 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <mlx.h>
# include <string.h>
# include "./libft/libft.h"

typedef	struct	s_color
{
	int		R;
	int		G;
	int		B;
	int		c_exist;
	int		f_exist;
}	t_color;

typedef struct s_map
{
	int s_exist;
	int n_exist;
	int w_exist;
	int e_exist;
}	t_map;


typedef	struct	s_cub
{
	int		nb_l;
	char	**array;
	char	*line;
	int		if_c;
	t_color	col_map;
	t_map	map;
}	t_cub;



char	*get_line(char **line, int fd);
void	ft_error(int n);
void	count_line_map(t_cub *count, char *file);
void	ft_read_map(char *argv, t_cub *map, int fd);
char	*get_next_line(int fd);
void	ft_init(t_cub *map);
int		parse_line(t_cub *map);
void	check_color(t_cub *map);
void	check_syntax_color(char *str, t_cub *map);
void	check_map(t_cub *map);

#endif