/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:40:51 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/19 16:32:40 by aboumadi         ###   ########.fr       */
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
}
