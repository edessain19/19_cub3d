/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:33:14 by edessain          #+#    #+#             */
/*   Updated: 2020/03/10 10:20:33 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define screenWidth 640
#define screenHeight 480

int main(int argc, char **argv)
{
	t_data			data;

	if (argc < 2)
		return (-1);
	ft_init_struct(&data);
	ft_parse_cub(&data, argv[1]);
//	write(1, "1", 1);
	if ((data.mlx.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx.mlx_win = mlx_new_window(data.mlx.mlx_ptr, 640, 480, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	data.dis.img = mlx_new_image(data.mlx.mlx_ptr, screenWidth, screenHeight);
	data.dis.addr = (int*)mlx_get_data_addr(data.dis.img, &data.dis.bits_per_pixel, &data.dis.line_length, &data.dis.endian);

//	write(1, "2", 1);
	ft_start_algo(&data);
//	write(1, "3", 1);
	mlx_put_image_to_window(data.mlx.mlx_ptr, data.mlx.mlx_win, data.dis.img, 0, 0);
	mlx_hook(data.mlx.mlx_win, 2, 1L<<0, ft_keyboard, &data);
	
	mlx_loop(data.mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
