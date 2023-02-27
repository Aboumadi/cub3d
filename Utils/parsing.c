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
	map->map.e_exist = -1;
	map->map.n_exist = -1;
	map->map.s_exist = -1;
	map->map.w_exist = -1;
	map->col_map.c_exist = -1;
	map->col_map.f_exist = -1;
	map->is_v = 0;
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
		i = parse_line(map2);
		map2->line = get_line(&map2->line, fd);
		i++;
	}
	free(map2->line);
	close(fd);
}

int		parse_line(t_cub *map)
{
	map->col_map.f_exist = ft_strncmp(map->line, "F ", 2);
	if (map->col_map.f_exist && check_color(map, 1, ft_strlen(map->line), 1) == 0)
	{
		printf("false_f\n");
		return 0;
	}
	map->col_map.c_exist = ft_strncmp(map->line, "C ", 2);
	if (map->col_map.c_exist && check_color(map, 1, ft_strlen(map->line), 0) == 0)
	{
		printf("false_c\n");
		return 0;
	}
	//if (map->if_c)
	//printf("succes\n");
	return 1;
}
