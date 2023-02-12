/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:15:08 by aboumadi          #+#    #+#             */
/*   Updated: 2022/10/23 20:55:31 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int		parse_line(t_cub *map)
{
	map->col_map.f_exist = ft_strncmp(map->line, "F", 1);
	if (!map->col_map.f_exist)
		check_color(map);
	map->col_map.c_exist = ft_strncmp(map->line, "C", 1);
	if (!map->col_map.c_exist)
		check_color(map);
	if (map->if_c)
		return 1;
	return 0;
}

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
	check_syntax_color(t_line, map);
}

void	check_syntax_color(char *str, t_cub *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			j++;
			i++;
		}
		else
			i++;
	}
	if (j == 2)
		map->if_c = 1;
	else
		map->if_c = 0;
}

void	check_map(t_cub *map)
{
	(void) map;
	/*int		i;
	int		j;
	int		k;
	char	*check;
	
	i = 0;
	while (map->t_map[i])
	{
		j = 0;
		check = (char *) malloc(ft_strlen(map->t_map[i]) * sizeof(char *));
		k = 0;
		check = map->t_map[i];
		while (check)
		{
			if (is_space(check[k]))
				k++;
			else if (ft_is_valid(check[k]))
				pars_string()
		}
		i++;
	}*/
}