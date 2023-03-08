/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:55:21 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/27 02:18:56 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

char	*get_line(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line);
}

void	ft_init(t_cub *map)
{
	map->map.e_exist = NULL;
	map->map.n_exist = NULL;
	map->map.s_exist = NULL;
	map->map.w_exist = NULL;
	//map->col_map.c_is_v = -1;
	//map->col_map.f_is_v = -1;
	map->c_exist = -1;
	map->f_exist = -1;
	map->col_v = 0;
	map->if_c = -1;
	map->nb_l = 0;
}

void	count_line_map(t_cub *count, char *file)
{
	int		i;
	char	*line;
	int		fd;
	
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(2);
	while (get_line(&line, fd))
	{
		free(line);
		i++;
	}
	count->nb_l = i;
	close(fd);
}

void	ft_read_map(char *file, t_cub *map2, int fd)
{
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(2);
	map2->line = get_line(&map2->line, fd);
	while (map2->line)
	{
		if (!strncmp(map2->line, "\n", 1))
		{
			free(map2->line);
			map2->line = get_line(&map2->line, fd);
			continue;
		}
		parse_line(map2);
		map2->line = get_line(&map2->line, fd);
		i++;
	}
	free(map2->line);
	close(fd);
}

void	parse_line(t_cub *map)
{
	if (!ft_strncmp(map->line, "F ", 2) && check_color(map, 1, ft_strlen(map->line), 1))
			map->f_exist = 1;
	else if (!ft_strncmp(map->line, "C ", 2) && check_color(map, 1, ft_strlen(map->line), 0))
			map->c_exist = 1;
	else if (!ft_strncmp(map->line, "NO ", 3))
		map->map.n_exist = ft_check_path(map, 2, ft_strlen(map->line));
	else if (!ft_strncmp(map->line, "SO ", 3))
		map->map.s_exist = ft_check_path(map, 2, ft_strlen(map->line));
	else if (!ft_strncmp(map->line, "EA ", 3))
		map->map.e_exist = ft_check_path(map, 2, ft_strlen(map->line));
	else if (!ft_strncmp(map->line, "WE ", 3))
		map->map.w_exist = ft_check_path(map, 2, ft_strlen(map->line));
	else
	{
		printf("error in params\n");
		exit(0);
	}
}
