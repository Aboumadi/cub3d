/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:04:22 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/27 01:13:40 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <mlx.h>
# include <string.h>
# include "./libft/libft.h"

typedef	struct	s_color
{
	int		R;
	int		G;
	int		B;
	//int		c_is_v;
	//int		f_is_v;
}	t_color;

typedef struct s_text
{
	char	*s_exist;
	char	*n_exist;
	char	*w_exist;
	char	*e_exist;
}	t_text;


typedef	struct	s_cub
{
	int		nb_l;
	char	**array;
	char	*line;
	int		if_c;
	int		c_exist;
	int		f_exist;
	int		col_v;
	t_color col_map;
	t_color	c;
	t_color f;
	t_text	map;
	
	
}	t_cub;



char	*get_line(char **line, int fd);
void	ft_error(int n);
void	count_line_map(t_cub *count, char *file);
void	ft_read_map(char *argv, t_cub *map, int fd);
char	*get_next_line(int fd);
void	ft_init(t_cub *map);
void	parse_line(t_cub *map);
int		check_color(t_cub *map, int i, int j, bool k);
bool	get_val(char *str, t_cub *map);
int		pars_val(t_cub *map);
int		check_val(char *str);
int		full_color(t_cub *map, bool i);
char	*ft_check_path(t_cub *map, int i, int j);
int		check_file(char *str);

#endif