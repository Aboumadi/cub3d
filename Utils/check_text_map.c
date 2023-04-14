/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_text_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:00:29 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/30 21:42:59 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_file(t_map *map)
{
// 	if (map->map.dup_e >= 2 || map->map.dup_s >= 2
// 		|| map->map.dup_n >= 2 || map->map.dup_w >= 2)
// 	{
// 		free(map->map.e_exist);
// 		free(map->map.n_exist);
// 		free(map->map.w_exist);
// 		free(map->map.s_exist);
// 		printf("Error duplicate path\n");
// 		exit(0);
// 	}
 	if (!map->e_textures || !map->n_textures
 		|| !map->s_textures|| !map->w_textures)
 	{
 		free(map->e_textures);
 		free(map->n_textures);
 		free(map->s_textures);
 		free(map->w_textures);
 		puts("Error\nmissing path");
 		exit(0);
 	}
}

char	*ft_check_path(t_map *map, int i, int j)
{
	char	*str;

	while (map->line[i] && (map->line[i] == ' '/* || map->line[i] == '\t'*/))
		i++;
	while (j && (map->line[j] == ' '/* || map->line[j] == '\t'*/))
		j--;
	str = ft_substr(map->line, i, j - i + 1);
	str[ft_strlen(str) - 1] = '\0';
	if (!ft_strrchr(str, '.') || ft_strncmp(ft_strrchr(str, '.'), ".xpm", 4))
	{
		free(str);
		printf("Error extension non valid\n");
		return (NULL);
	}
	if (check_file(str))
	{
		return (free(map->line), str);
	}
	return (NULL);
}

int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDWR);
	
	if (fd == -1)
	{
		printf("%s", str);
		printf("%d\n", ft_strlen(str));
		ft_error(7, str, NULL);
	}
	else
		close(fd);
	return (1);
}

// void	ft_check_col(t_map *map)
// {
// 	if ((!map->f.dup_col && !map->c.dup_col)
// 		|| (map->f.dup_col && !map->c.dup_col)
// 		|| (!map->f.dup_col && map->c.dup_col))
// 		ft_error(3, NULL);
// }
