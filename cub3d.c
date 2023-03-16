/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:45:30 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/25 00:22:28 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	ft_error(int n)
{
	if (n == 1)
		printf("error in arguments\n");
	if (n == 2)
		printf("error in file descriptor\n");
	if (n == 3)
		printf("error in allocation\n");
	exit(0);
}

void	ft_chek_alloc(char **str)
{
	if (!str)
		ft_error(3);
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

int main(int argc, char **argv)
{
	int fd;
	t_cub	*map;
	
	if (argc != 2)
		ft_error(1);
	ft_check_extension_file(argv[1]);
	map = (t_cub *)malloc(sizeof(t_cub));
	ft_init(map);
	count_line_map(map, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(2);
	ft_read_map(argv[1], map, fd, 0);
	return 0;
}