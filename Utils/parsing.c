/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:55:21 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/30 21:53:53 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"
#include <sys/fcntl.h>

void	ft_advanced_read(t_map *map, int fd, int i, int j)
{
	while (map->line)
	{
		check_line(map->line, map, fd);
		map->map[j] = malloc (sizeof(char) * map->map_w + 1);
		ft_free(map->map, map->map_h);
		i = -1;
		while (++i <= map->map_w)
		{
			if (((ft_strlen(map->line) - 1) == map->map_w
					&& map->line[i] != '\n' && map->line[i]))
					map->map[j][i] = map->line[i];
			else if ((ft_strlen(map->line) - 1) < map->map_w)
			{
				if ((i < ft_strlen(map->line) && map->line[i])
					&& map->line[i] != '\n')
					map->map[j][i] = map->line[i];
				else
					map->map[j][i] = ' ';
			}
		}
		j++;
		free(map->line);
		map->line = get_next_line(fd);
		if (map->line[0] != '\0')
		printf("error");
	}
}

void	ft_init(t_map *map)
{
	map->e_textures = NULL;
	map->n_textures = NULL;
	map->s_textures = NULL;
	map->w_textures = NULL;
	map->f_col = -1;
	map->c_col = -1;
	map->checker = 0;
	map->map_h = 0;
	map->map_w = 0;
	map->p_pos.x = 0;
	map->p_pos.y = 0;
}

void	count_line_map(t_map *count, char *file)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDWR);
	if (fd < 0)
		ft_error(2, NULL, count);
	line = get_next_line(fd);
	while (line && ++i)
	{
		if (count->map_w < ft_strlen(line))
			count->map_w = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	if (count->map_w == 0)
	 	return (ft_putstr_fd("Error\nfile is empty\n", 2), free(line), exit(1));
	count->map_h = i;
	close(fd);
}

void	ft_read_map(t_map *map2, int fd, int i)
{
	map2->line = get_next_line(fd);
	while (map2->line && ++i)
	{
		if (!strncmp(map2->line, "\n", 1))
		{
			free (map2->line);
			map2->line = get_next_line(fd);
			continue ;
		}
		if (parse_line(map2))
			map2->line = get_next_line(fd);
		else
			break ;
	}
	if (!map2->line)
	{
		printf("error\n");
		exit(0);
	}
	ft_check_file(map2);
	if (map2->map)
		ft_free2(map2->map, 3);
	map2->map_h = map2->map_h - i + 1;
	map2->map = (char **)malloc(sizeof(char *) * (map2->map_h));
	ft_free (map2->map, map2->map_h);
	ft_advanced_read(map2, fd, map2->map_h, 0);
	free(map2->line);
	close(fd);
}

int	parse_line(t_map *map)
{
	if (!ft_strncmp(map->line, "F ", 2)
		&& check_color(map, 1, ft_strlen(map->line)) && full_color(map, 1));
	else if (!ft_strncmp(map->line, "C ", 2)
		&& check_color(map, 1, ft_strlen(map->line)) && full_color(map, 0));
	else if (!ft_strncmp(map->line, "NO ", 3) && !map->n_textures)
		map->n_textures = ft_check_path(map, 2, ft_strlen(map->line));
	else if (!ft_strncmp(map->line, "SO ", 3) && !map->s_textures)
		map->s_textures = ft_check_path(map, 2, ft_strlen(map->line));
	else if (!ft_strncmp(map->line, "EA ", 3) && !map->e_textures)
		map->e_textures = ft_check_path(map, 2, ft_strlen(map->line));
	else if (!ft_strncmp(map->line, "WE ", 3) && !map->w_textures)
		map->w_textures = ft_check_path(map, 2, ft_strlen(map->line));
	else
		return (0);
	return (1);
}
