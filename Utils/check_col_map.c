/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:15:08 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/26 22:10:30 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	check_color(t_cub *map, int i, int j, bool k)
{
	char	*t_line;

	while (map->line[i] && (map->line[i] == ' '))
		i++;
	while (j && (map->line[j] == ' '))
		j--;
	t_line = ft_substr(map->line, i, j - i + 1);
	t_line[ft_strlen(t_line) - 1] = '\0';
	i = -1;
	j = 0;
	if (!ft_isdigit (t_line[0]))
		return (free (t_line), ft_error(3, NULL), 0);
	while (t_line[++i])
	{
		if (t_line[i] == ',' && t_line[i + 1] && t_line[i + 1] != ',')
			j++;
		if (t_line[i] == ',' && !t_line[i + 1])
			j--;
	}
	if ((j == 2 && get_val(t_line, map, k)) && (map->f.dup_col <= 1 && map->c.dup_col <= 1))
		return (full_color(map, k));
	else
		return (ft_error(3, NULL), 0);
}

bool	get_val(char *str, t_cub *map, bool k)
{
	int	i;

	i = -1;
	map->array = ft_split(str, ',');
	free(str);
	while (map->array[++i])
	{
		if ((ft_strchr(map->array[i], ' ') || !check_val(map->array[i])))
		{
			ft_free2(map->array, 3);
			return (false);
		}
	}
	if (k == true)
		map->f.dup_col++;
	else
		map->c.dup_col++;
	return (true);
}

int	check_val(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((!ft_isdigit(str[i]) || ft_isalpha(str[i]) || str[i] == ' '))
		{
			return (0);
		}
	}
	if (i >=1 && i <= 3)
		return (1);
	return 0;
}

int	full_color(t_cub *map, bool i)
{
	if (i == true)
	{
		map->f.r = ft_atoi(map->array[0]);
		map->f.g = ft_atoi(map->array[1]);
		map->f.b = ft_atoi(map->array[2]);
		if ((map->f.r >= 0 && map->f.r <= 255)
			&& (map->f.g >= 0 && map->f.g <= 255)
			&& (map->f.b >= 0 && map->f.b <= 255))
			return (1);
		return (ft_error(3, NULL), 0);
	}
	else
	{
		map->c.r = ft_atoi(map->array[0]);
		map->c.g = ft_atoi(map->array[1]);
		map->c.b = ft_atoi(map->array[2]);
		if ((map->c.r >= 0 && map->c.r <= 255)
			&& (map->c.g >= 0 && map->c.g <= 255)
			&& (map->c.b >= 0 && map->c.b <= 255))
			return (1);
		return (ft_error(3, NULL), 0);
	}
}
