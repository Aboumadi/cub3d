/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_text_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:00:29 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/20 02:15:55 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_file(t_cub *map)
{
	if (map->map.dup_e >= 2 || map->map.dup_s >= 2 || map->map.dup_n >= 2 || map->map.dup_w >= 2)
	{
		free(map->map.e_exist);
		free(map->map.n_exist);
		free(map->map.w_exist);
		free(map->map.s_exist);
		printf("Error duplicate path\n");
		exit(0);
	}
	else if (!map->map.e_exist || !map->map.n_exist
		|| !map->map.w_exist || !map->map.s_exist)
	{
		free(map->map.e_exist);
		free(map->map.n_exist);
		free(map->map.w_exist);
		free(map->map.s_exist);
		puts("Error missing path\n");
		exit(0);
	}
}

char	*ft_check_path(t_cub *map, int i, int j, char *elem)
{
	char	*str;

	while (map->line[i] && (map->line[i] == ' '))
		i++;
	while (j && (map->line[j] == ' '))
		j--;
	str = ft_substr(map->line, i, j - i + 1);
	if (str)
		str[ft_strlen(str) - 1] = '\0';
	if (!ft_strrchr(str, '.') || ft_strncmp(ft_strrchr(str, '.'), ".xpm", 4))
	{
		free(str);
		printf("Error extension non valid\n");
		return (NULL);
	}
	if (check_file(str))
	{
		check_dup(map, elem);
		return (str);
	}
	return (NULL);
}

int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDWR);
		if (fd == -1)
	{
		free(str);
		return (0);
	}
	else
		close(fd);
	return (1);
}

void	check_dup(t_cub *map, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		map->map.dup_n++;
	else if (!ft_strncmp(str, "SO ", 3))
		map->map.dup_s++;
	else if (!ft_strncmp(str, "EA ", 3))
		map->map.dup_e++;
	else if (!ft_strncmp(str, "WE ", 3))
		map->map.dup_w++;
}

void	ft_check_col(t_cub *map)
{
	if ((!map->f.dup_col && !map->c.dup_col) || (map->f.dup_col && !map->c.dup_col)
		|| (!map->f.dup_col && map->c.dup_col))
		ft_error(3, NULL);
}
