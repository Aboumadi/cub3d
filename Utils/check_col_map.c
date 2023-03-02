/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:15:08 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/27 02:17:04 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	check_color(t_cub *map, int i, int j, bool k)
{
	char	*t_line;
	//int l = 0;
	
	while (map->line[i] && (map->line[i] == ' '))
		i++;
	while (j && (map->line[j] == ' '))
		j--;
	t_line = ft_substr(map->line, i, j - i + 1);
	t_line[ft_strlen(t_line) - 1] = '\0';
	i = -1;
	j = 0;
	while (t_line[++i])
	{
		if (t_line[i] == ',' && t_line[i + 1])
			j++;
		if (t_line[i] == ',' && !t_line[i + 1])
			j--;
	}
	if (j == 2 && get_val(t_line, map))
	{
		return (full_color(map, k));
	}
	else
	{
		return 0;
	}
}

bool	get_val(char *str, t_cub *map)
{
	int	i;

	i = 0;
	if (!ft_isdigit(str[i]))
		return false;
	map->array = (char **) malloc(3 * sizeof(char *));
	map->array = ft_split(str, ',');
		free(str);
		while (map->array[++i])
		{
			if ((ft_strchr(map->array[i], ' ') || !check_val(map->array[i])))
			{
//++++++++++++++++need fonction to free+++++++++++++++++++++//
				free(map->array);
				return false ;
			}
		}
	return true;
}

int check_val(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if ((!ft_isdigit(str[i]) || ft_isalpha(str[i])))
            return 0;
    }
    return 1;
}

int	full_color(t_cub *map, bool i)
{
	if (i == true)
	{
		map->f.R = ft_atoi(map->array[0]);
		map->f.G = ft_atoi(map->array[1]);
		map->f.B = ft_atoi(map->array[2]);
		if ((map->f.R >= 0 && map->f.R <= 255) && (map->f.G >= 0 && map->f.G <= 255) 
			&& (map->f.B >= 0 && map->f.B <= 255))
			return 1;
		return 0;
	}
	else
	{
		map->c.R = ft_atoi(map->array[0]);
		map->c.G = ft_atoi(map->array[1]);
		map->c.B = ft_atoi(map->array[2]);
		if ((map->c.R >= 0 && map->c.R <= 255) && (map->c.G >= 0 && map->c.G <= 255) 
			&& (map->c.B >= 0 && map->c.B <= 255))
			return 1;
		return 0;
	}
}