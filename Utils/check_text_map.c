/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:00:29 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/25 23:02:39 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char    *ft_check_path(t_cub *map, int i, int j)
{
    char    *str;

    while (map->line[i] && (map->line[i] == ' '))
		i++;
	while (j && (map->line[j] == ' '))
		j--;
    str = ft_substr(map->line, i, j - i + 1);
    if (str)
    str[ft_strlen(str) - 1] = '\0';
	if (ft_strcmp(ft_strnstr(str, ".xpm", ft_strlen(str)), ".xpm"))
    {
        free(str);
        return NULL;
    }
    if (check_file(str))
        return str;
    return NULL;
}

int check_file(char *str)
{
    int fd;

    fd = open(str, O_RDWR);
	if (fd == -1)
    {
		free(str);
        return 0;
    }
	else
    {
		close(fd);
        return 1;
    }
return 1;
}