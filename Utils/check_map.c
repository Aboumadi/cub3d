/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:40:51 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/20 01:59:15 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_map(t_cub *map, int i, int j)
{
	while (++j < map->max_l)
		if ((map->array[0][j] != ' ' && map->array[0][j] != '1') || (map->array
			[map->nb_l - 1][j] != ' ' && map->array[map->nb_l - 1][j] != '1'))
			ft_error(5, NULL);
	while (++i < map->nb_l - 1)
		if ((map->array[i][0] != ' ' && map->array[i][0] != '1') || (map->array
			[i][map->max_l - 1] != ' ' && map->array[i][map->max_l - 1] != '1'))
			ft_error(5, NULL);
	i = 1;
	while (i++ < map->nb_l - 2)
	{
		j = 1;
		while (j++ < map->max_l - 1)
		{
			if (ft_strchr("NSWE", map->array[i][j]))
			{
				map->player.p_start = map->array[i][j];
				map->player.count_pl++;
			}
		}
	}
	if (map->player.count_pl == 0 || map->player.count_pl > 1)
		ft_error(6, NULL);
	else
		check_direction_player(map);
}

void	check_direction_player(t_cub *map)
{
	if (map->player.p_start == 'N')
		map->player.direction = (3 * 3.14);
	else if (map->player.p_start == 'S')
		map->player.direction = (3.14 / 2);
	else if (map->player.p_start == 'E')
		map->player.direction = 0;
	else if (map->player.p_start == 'W')
		map->player.direction = 3.14;
	check_inside_map(map, 1, 1);
}

void	check_inside_map(t_cub *map, int i, int j)
{
	while (i++ < map->nb_l - 2)
	{
		j = 1;
		while (j++ < map->max_l - 1)
		{
			if (map->array[i][j] == '0')
				ft_check_around(map, &i, &j);
		}
	}
}

void	ft_check_around(t_cub *map, int *i, int *j)
{
	if ((map->array[*i][*j + 1] && !ft_strchr("01NEWS", map->array[*i][*j + 1]))
	|| (map->array[*i][*j - 1] && !ft_strchr("01NEWS", map->array[*i][*j - 1]))
	|| (map->array[*i + 1][*j] && !ft_strchr("01NEWS", map->array[*i + 1][*j]))
	|| (map->array[*i - 1][*j] && !ft_strchr("01NEWS", map->array[*i - 1][*j])))
	{
		printf("error\n");
		exit(0);
	}
}
