/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:19:27 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/30 21:17:11 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	ft_error(int n, char *arr, t_map *map)
{
	if (n == 1)
		printf("Error\nin arguments\n");
	if (n == 2)
		printf("Error\nin file descriptor\n");
	if (n == 3)
		printf("Error\nin colors\n");
	if (n == 4 && !arr)
		return (ft_putstr_fd("Error\nin allocation for one dimension\n", 2), free(arr), exit(0));
	if (n == 5)
		printf("Error\nin map : no wall\n");
	if (n == 6)
		return (ft_putstr_fd("Error\nin allocation for one dimension\n", 2), ft_free2(map->map, map->map_h), exit(0));
	if (n == 7)
		return (ft_putstr_fd("Error\nmissing path\n", 2), free(arr), exit(0));
	exit(0);
}

void	ft_free(char **str, int k)
{
	int	i;

	i = 0;
	if (!str)
	{
		while (i < k)
		{
			free(str[i]);
			i++;
		}
		printf("error in allocation for two dimension\n");
		exit(0);
	}
}

void	ft_free2(char **str, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	check_line(char *str, t_map *map, int fd)
{
	if (!ft_strcmp(str, "\n") || !str)
	{
		free(str);
		ft_free2(map->map, map->map_h);
		close(fd);
		printf("error lines\n");
		exit(0);
	}
}

void	ft_check_extension_file(char *file)
{
	char	*ch_file;

	if (ft_strlen(file) == 0)
	{
		printf("invalid file\n");
		exit(0);
	}
	ch_file = ft_strchr(file, '.');
	if (!ch_file || ft_strcmp(ch_file, ".cub"))
	{
		printf("error in file name\n");
		exit (0);
	}
}
