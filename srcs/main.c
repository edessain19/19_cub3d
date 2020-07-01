/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:06:39 by edessain          #+#    #+#             */
/*   Updated: 2020/06/30 11:48:14 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_errors(int ac, char **av)
{
	int fd;

	if (ac == 1 || ac > 3)
	{
		write(1, "Error\nInvalid arguments\n", 24);
		return (-1);
	}
	else if (ac == 3 && (ft_strncmp(av[2], "--save", 6)))
	{
		write(1, "Error\nInvalid option\n", 21);
		return (-1);
	}
	else if ((fd = open(av[1], O_RDONLY)) <= 0)
	{
		write(1, "Error\nNo such file or directory\n", 32);
		return (-1);
	}
	return (1);
}

int		launch_program(t_data *data, char *av)
{
	ft_init_struct(data);
	if (ft_parse_cub(data, av) < 0)
		return (-1);
	if (!(data->mlx.mlx_ptr = mlx_init()))
		return (-1);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_ptr,
		data->parse.r1, data->parse.r2, "cub3D");
	generate_textures(data);
	data->dis.img = mlx_new_image(data->mlx.mlx_ptr, data->parse.r1, data->parse.r2);
	data->dis.addr = (int *)mlx_get_data_addr(data->dis.img, &data->dis.bits_per_pixel,
		&data->dis.line_length, &data->dis.endian);
	start_raycasting(data);
	return (1);
}

int		main(int ac, char **av)
{
	t_data		data;

	if (ft_errors(ac, av) < 0)
		return (-1);
	else if (ac == 2)
	{
		if ((launch_program(&data, av[1])) < 0)
			return (exit_all(&data));
		mlx_hook(data.mlx.mlx_win, 2, 1L << 1, ft_keyboard, &data);
		mlx_hook(data.mlx.mlx_win, 17, 0, exit_all, &data);
		mlx_loop(data.mlx.mlx_ptr);
	}
//	else if (ac == 3 && !ft_strncmp(av[2], "--save", 5))
//	{
//		if ((launch_program(&m, av[1])) < 0)
//			return (exit_all(&m));
//		if (screen_shot(&m) < 0)
//			return (exit_all(&m));
//	}
	else
		exit_all(&data);
	return (0);
}
