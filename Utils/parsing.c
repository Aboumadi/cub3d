/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:55:21 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/18 19:49:31 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	ft_advanced_read(t_cub *map, int fd, int i, int j)
{
	map->array = (char **)malloc(sizeof(char *) * (map->nb_l - i + 1));
	ft_free (map->array, map->nb_l);
	while (map->line)
	{
		map->array[j] = malloc (sizeof(char) * map->max_l + 1);
		ft_free(map->array, map->nb_l);
		i = -1;
		while (++i <= map->max_l)
		{
			if ((ft_strlen(map->line) - 1) == map->max_l
				&& map->line[i] != '\n')
					map->array[j][i] = map->line[i];
			else if ((ft_strlen(map->line) - 1) < map->max_l)
			{
				if (i < ft_strlen(map->line) - 1)
					map->array[j][i] = map->line[i];
				else
				map->array[j][i] = ' ';
			}
		}
		map->array[j][map->max_l] = '\0';
		j++;
		map->line = get_next_line(fd);
	}
	free (map->line);
}

void	ft_init(t_cub *map)
{
	map->map.e_exist = NULL;
	map->map.n_exist = NULL;
	map->map.s_exist = NULL;
	map->map.w_exist = NULL;
	map->c_exist = -1;
	map->f_exist = -1;
	map->col_v = 0;
	map->if_c = -1;
	map->nb_l = 0;
	map->max_l = 0;
}

void	count_line_map(t_cub *count, char *file)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(2, NULL);
	line = get_next_line(fd);
	count->max_l = ft_strlen(line);
	while (line && ++i)
	{
		if (count->max_l < ft_strlen(line) - 1)
			count->max_l = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(fd);
	}
	count->nb_l = i;
	close(fd);
}

void	ft_read_map(char *file, t_cub *map2, int fd, int i)
{
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(2, NULL);
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
	if (map2->array)
		ft_free(map2->array, 3);
	ft_advanced_read(map2, fd, i, 0);
	close (fd);
	free(map2->line);
	close(fd);
}

int	parse_line(t_cub *map)
{
	if (!ft_strncmp(map->line, "F ", 2)
		&& check_color(map, 1, ft_strlen(map->line), 1))
			map->f_exist = 1;
	else if (!ft_strncmp(map->line, "C ", 2)
		&& check_color(map, 1, ft_strlen(map->line), 0))
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
		return (0);
	}
	return (1);
}
