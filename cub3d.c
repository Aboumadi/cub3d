/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:45:30 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/30 20:52:41 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	begin(int argc, char **argv, t_map *map)
{
	int	fd;

	if (argc != 2)
		ft_error(1, NULL, map);
	ft_check_extension_file(argv[1]);
	ft_init(map);
	count_line_map(map, argv[1]);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error(2, NULL, map);
	ft_read_map(map, fd, 0);
	ft_check_map(map, -1, -1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	begin(argc, argv, &map);
	return (0);
}
