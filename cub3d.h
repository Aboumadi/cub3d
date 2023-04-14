/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:04:22 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/30 21:33:18 by aboumadi         ###   ########.fr       */
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

// typedef struct s_color
// {
// 	int			r;
// 	int			g;
// 	int			b;
// 	int			dup_col;
// }	t_color;


// typedef struct s_text
// {
// 	char		*s_exist;
// 	char		*n_exist;
// 	char		*w_exist;
// 	char		*e_exist;
// 	int			dup_s;
// 	int			dup_n;
// 	int			dup_e;
// 	int			dup_w;
// }	t_text;

// typedef struct s_p_pos
// {
// 	char	p_start;
// 	int		x;
// 	int		y;
// 	double	ang;
// 	int		p_position;
// 	int		count_pl;
// 	// int		direction;
// }	t_p_pos;

// typedef struct s_cub
// {
// 	int			map_h;
// 	char		**map;
// 	char		*line;
// 	int			if_c;
// 	int			c_exist;
// 	int			f_exist;
// 	int			col_v;
// 	int			map_w;
// 	t_color		col_map;
// 	t_color		c;
// 	t_color		f;
// 	t_text		map;
// 	t_p_pos	p_pos;
// }	t_map;


/*typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;*/

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	ang;
}	t_coordinates;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}			t_data;

typedef struct s_textures
{
	t_data	n_image;
	t_data	e_image;
	t_data	w_image;
	t_data	s_image;
}	t_textures;

typedef	struct s_ray
{
	double	ang;
	int		vh;
	double	x;
	double	y;
	double	w_height;
}	t_ray;


typedef struct s_map
{
	char			*line;
	int				checker;
	char			*n_textures;
	char			*s_textures;
	char			*e_textures;
	char			*w_textures;
	int				f_col;
	int				c_col;
	char			**map;
	int				map_h;
	int				map_w;
	t_coordinates	p_pos;
	//t_vars			mlx;
	t_data			img;
	t_textures		textures;
} t_map;

void	begin(int argc, char **argv, t_map *map);
void	ft_error(int n, char *arr, t_map *map);
void	ft_free(char **str, int k);
void	ft_free2(char **str, int k);
void	ft_check_extension_file(char *file);
void	count_line_map(t_map *count, char *file);
void	ft_read_map(t_map *map, int fd, int i);
void	ft_advanced_read(t_map *map, int fd, int i, int j);
void	check_line(char *str, t_map *map, int fd);
char	*get_next_line(int fd);
void	ft_init(t_map *map);
int		parse_line(t_map *map);
int		check_color(t_map *map, int i, int j);
void	ft_check_col(t_map *map);
bool	get_val(char *str, t_map *map);
int		pars_val(t_map *map);
int		check_val(char *str);
int		full_color(t_map *map, bool i);
char	*ft_check_path(t_map *map, int i, int j);
int		check_file(char *str);
void	ft_check_map(t_map *map, int i, int j);
void	check_frame(t_map *map, int i, int j);
int		check_direction_p_pos(t_map *map, int i, int j);
void	check_inside_map(t_map *map, int i, int j);
void	ft_check_file(t_map *map);

#endif
