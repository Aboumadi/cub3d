/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:45:30 by aboumadi          #+#    #+#             */
/*   Updated: 2023/03/26 03:07:34 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	begin(int argc, char **argv, t_cub *map)
{
	int fd;
	// t_cub	*map;
	
	if (argc != 2)
		ft_error(1, NULL);
	ft_check_extension_file(argv[1]);
	// map = (t_cub *)malloc(sizeof(t_cub));
	ft_init(map);
	count_line_map(map, argv[1]);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error(2, NULL);
	ft_read_map(argv[1], map, fd, 0);
	ft_check_map(map, -1, -1);
		
}

int main(int argc, char **argv)
{
	t_cub	*map;

	map = (t_cub *)malloc(sizeof(t_cub));
	begin(argc, argv, map);
	// map->m_map.mlx = mlx_init();
	// map->m_map.mlx = mlx_new_window(map->m_map.mlx, (map->max_l) * 64, (map->nb_l) * 64, "cub3d");
	// mlx_pixel_put(map->m_map.mlx, &map->m_map.mlx_wind, 200, 300, 0x0000ff);
	// map->m_map.img = mlx_new_image(map->m_map.mlx, 640, 360);
	// mlx_loop(map->m_map.mlx);
	
	/*int fd;
	t_cub	*map;
	
	if (argc != 2)
		ft_error(1, NULL);
	ft_check_extension_file(argv[1]);
	map = (t_cub *)malloc(sizeof(t_cub));
	ft_init(map);
	count_line_map(map, argv[1]);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error(2, NULL);
	ft_read_map(argv[1], map, fd, 0);
	ft_check_map(map, -1, -1);*/
	
	return 0;
}