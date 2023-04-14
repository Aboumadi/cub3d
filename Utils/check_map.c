/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:40:51 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/30 21:15:27 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_frame(t_map *map, int i, int j)
{
	//printf("here\n");
	//printf("%d\n", map->map_w);
	while (++j < map->map_w)
	{
		if ((map->map[0][j] != ' ' && map->map[0][j] != '1') || (map->map
			[map->map_h - 1][j] != ' ' && map->map[map->map_h - 1][j] != '1'))
			ft_error(5, NULL, map);
	}
	while (++i < map->map_h - 1)
	{
		if ((map->map[i][0] != ' ' && map->map[i][0] != '1') || (map->map
			[i][map->map_w] != ' ' && map->map[i][map->map_w] != '1'))
			ft_error(5, NULL, map);
		//printf("here\n");
	}
	//ft_check_map(map, 0, 0);
}

void	ft_check_map(t_map *map, int i, int j)
{
	int	a;
	int	b;

	check_frame(map, -1, -1);
	while (++i <= map->map_h - 2)
	{
		j = 1;
		while (j++ < map->map_w - 1)
		{
			if (ft_strchr("NSWE", map->map[i][j]))
			{
				a = i;
				b = j;
			}
		}
	}
	if (!check_direction_p_pos(map, a, b))
		ft_error(6, NULL, map);
}

int	check_direction_p_pos(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'N' && !map->p_pos.x && !map->p_pos.y)
	{
		map->p_pos.x = j;
		map->p_pos.y = i;
		map->p_pos.ang = 90;
	}
	else if (map->map[i][j] == 'S' && !map->p_pos.x && !map->p_pos.y)
	{
		map->p_pos.x = j;
		map->p_pos.y = i;
		map->p_pos.ang = 270;
	}
	else if (map->map[i][j] == 'E' && !map->p_pos.x && !map->p_pos.y)
	{
		map->p_pos.x = j;
		map->p_pos.y = i;
		map->p_pos.ang = 180;
	}
	else if (map->map[i][j] == 'W' && !map->p_pos.x && !map->p_pos.y)
	{
		map->p_pos.x = j;
		map->p_pos.y = i;
		map->p_pos.ang = 0;
	}
	else 
		return (0);
	return (check_inside_map(map, 0, 1), 1);
}

void	check_inside_map(t_map *map, int i, int j)
{

	while (++i <= map->map_h - 2)
	{
		j = 1;
		while (j++ < map->map_w - 1)
		{
			if ((map->map[i][j] == '0'
				&& ((map->map[i + 1][j] && map->map[i + 1][j] == ' ')
				|| (map->map[i - 1][j] && map->map[i - 1][j] == ' ')
				|| (map->map[i][j + 1] && map->map[i][j + 1] == ' ')
				|| (map->map[i][j - 1] && map->map[i][j - 1] == ' '))))
			{
				printf("Error\nin walls\n");
				exit(0);
			}
			else if (!strchr("01NEWS ", map->map[i][j]))
			{
				printf("carater non valid\n");
				exit(0);
			}
		}
	}
}
