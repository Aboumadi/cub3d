/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:15:08 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/25 22:05:04 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	check_color(t_cub *map)
{
	int		i;
	int		j;
	int		k;
	char	*t_line;

	i = 1;
	j = ft_strlen(map->line);
	while (map->line[i] && (map->line[i] == ' '))
		i++;
	while (j && (map->line[j] == ' '))
		j--;
	k = j - i;
	t_line = ft_substr(map->line, i, k + 1);
	t_line[ft_strlen(t_line) - 1] = '\0';
	check_syntax_color(t_line, map);
	if (map->if_c && get_val(t_line, map))
		pars_val(map);
	else
		map->col_map.is_v = 0;
	printf("%d\n", map->col_map.is_v);
}

void	check_syntax_color(char *str, t_cub *map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	if (j == 2)
		map->if_c = 1;
	else
		map->if_c = 0;
}

bool	get_val(char *str, t_cub *map)
{
	int	i;

	i = 0;
	map->array = (char **) malloc(3 * sizeof(char *));
		if (!ft_isdigit(str[i]))
			return false;
		map->array = ft_split(str, ',');
		free(str);
		i = -1;
		while (map->array[++i])
		{
			if (!map->array[i])
			{
				free(map->array);
				return false;
			}
		}
		//conv_val(map);
	return true;
}

int	pars_val(t_cub *map)
{
	int	i;

	i = -1;
	while(map->array[++i])
	{
		if ((ft_strchr(map->array[i], ' ') || !check_val(map->array[i])))
		{
			free(map->array);
			map->col_map.is_v = 0;
			return 0;
		}
	}
	map->col_map.is_v = 1;
	return 1;
}

int check_val(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((!ft_isdigit(str[i]) || ft_isalpha(str[i])))
            return 0;
        i++;
    }
    return 1;;
}
