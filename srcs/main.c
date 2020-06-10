/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:33:14 by edessain          #+#    #+#             */
/*   Updated: 2020/06/08 12:00:17 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_data			data;

	if (argc < 2)
		return (-1);
	ft_init_struct(&data);
	ft_parse_cub(&data, argv[1]);
	if ((data.mlx.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx.mlx_win = mlx_new_window(data.mlx.mlx_ptr, 640, 480, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	data.dis.img = mlx_new_image(data.mlx.mlx_ptr, data.parse.r1, data.parse.r2);
	data.dis.addr = (int*)mlx_get_data_addr(data.dis.img, &data.dis.bits_per_pixel, &data.dis.line_length, &data.dis.endian);
	generate_textures(&data);

	ft_start_algo(&data);

	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.mlx_win, data.dis.img, 0, 0);
	mlx_hook(data.mlx.mlx_win, 2, 1L<<1, ft_keyboard, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
