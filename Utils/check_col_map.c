/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:15:08 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/30 21:51:35 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

/*7yd dk \0 fch t updati libft*/

int	check_color(t_map *map, int i, int j)
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
		return (free (t_line), ft_error(3, NULL, map), 0);
	while (t_line[++i])
	{
		if (t_line[i] == ',' && t_line[i + 1] && t_line[i + 1] != ',')
			j++;
		if (t_line[i] == ',' && !t_line[i + 1])
			j--;
	}
	if ((j == 2 && get_val(t_line, map)))
		return (1);
	return (0);
}

bool	get_val(char *str, t_map *map)
{
	int	i;

	i = -1;
	map->map = ft_split(str, ',');
	free(str);
	while (map->map[++i])
	{
		if ((ft_strchr(map->map[i], ' ') || !check_val(map->map[i]) || (ft_strlen(map->map[i]) > 3)))
		{
			printf("here\n");
			return (false);
		}
	}
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
	return (1);
}

int	full_color(t_map *map, bool i)
{
	if (i == true)
	{
		if ((ft_atoi(map->map[0]) >= 0 && ft_atoi(map->map[0]) <= 255)
		&& (ft_atoi(map->map[1]) >= 0 && ft_atoi(map->map[1]) <= 255)
		&& (ft_atoi(map->map[2]) >= 0 && ft_atoi(map->map[2]) <= 255))
		{
			if (map->f_col == -1)
				map->f_col = ft_atoi(map->map[0]) << 16 | ft_atoi(map->map[1]) << 8 | ft_atoi(map->map[2]);
			else
				return (ft_error(3, NULL, map), 0);
		}
		else
			return (ft_error(3, NULL, map), 0);
	}
	else
	{
		if ((ft_atoi(map->map[0]) >= 0 && ft_atoi(map->map[0]) <= 255)
		&& (ft_atoi(map->map[1]) >= 0 && ft_atoi(map->map[1]) <= 255)
		&& (ft_atoi(map->map[2]) >= 0 && ft_atoi(map->map[2]) <= 255))
		{
			if (map->c_col == -1)
				map->c_col = ft_atoi(map->map[0]) << 16 | ft_atoi(map->map[1]) << 8 | ft_atoi(map->map[2]);
			else
				return (ft_error(3, NULL, map), 0);
		}
		else
			return (ft_error(3, NULL, map), 0);
	}
	return (1);
}
