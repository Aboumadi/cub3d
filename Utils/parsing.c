/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:55:21 by aboumadi          #+#    #+#             */
/*   Updated: 2022/10/23 20:30:39 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

char	*get_line(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line);
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
	char	*line;
	int		j;
	
	j = map2->nb_l;
	i = 0;
	map2->t_map = (char **) malloc((map2->nb_l + 1) * sizeof(char *));
	if (!map2->t_map)
		ft_error(3);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(2);
	while (get_line(&line, fd))
	{
		map2->t_map[i] = line;
		//printf("%s", map2->t_map[i]);
		map2->t_map[i][ft_strlen(map2->t_map[i])] = '\0';
		i++;
	}
	free(line);
	close(fd);
}