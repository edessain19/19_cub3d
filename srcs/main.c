/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:33:14 by edessain          #+#    #+#             */
/*   Updated: 2020/03/04 12:52:21 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	mlx_t			mlx;

	if ((mlx.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, 640, 480, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	ft_algo(argc, argv);
	mlx_loop(mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
