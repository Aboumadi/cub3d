/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:19:27 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/25 02:22:21 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	ft_error(int n, char *arr)
{
	if (n == 1)
		printf("Error in arguments\n");
	if (n == 2)
		printf("Error in file descriptor\n");
	if (n == 3)
		printf("Error in colors\n");
	if (n == 4)
	{
		if (!arr)
		{
			free(arr);
			printf("error in allocation for one dimension\n");
		}
	}
	if (n == 5)
		printf("error in map : no wall\n");
	if (n == 6)
		printf("Error in player\n");
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

void	check_line(char *str, t_cub *map, int fd)
{
	if (!ft_strcmp(str, "\n"))
	{
		free(str);
		ft_free2(map->array, map->nb_l);
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