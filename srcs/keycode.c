/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:50:53 by hbuisser          #+#    #+#             */
/*   Updated: 2020/06/30 11:33:41 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		keys_up_down(t_data *data, int keycode)
{
	if (keycode == 126 || keycode == 13)
	{
		if (data->parse.map[(int)(data->rec.posX + data->rec.dirX *
				data->rec.speed)][(int)data->rec.posY] != '1')
			data->rec.posX += data->rec.dirX * data->rec.speed;
		if (data->parse.map[(int)data->rec.posX][(int)(data->rec.posY +
				data->rec.dirY * data->rec.speed)] != '1')
			data->rec.posY += data->rec.dirY * data->rec.speed;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (data->parse.map[(int)(data->rec.posX - data->rec.dirX *
				data->rec.speed)][(int)data->rec.posY] != '1')
			data->rec.posX -= data->rec.dirX * data->rec.speed;
		if (data->parse.map[(int)data->rec.posX][(int)(data->rec.posY -
				data->rec.dirY * data->rec.speed)] != '1')
			data->rec.posY -= data->rec.dirY * data->rec.speed;
	}
	return (1);
}

int		keys_rot_left(t_data *data, int keycode)
{
	if (keycode == 123 || keycode == 0)
	{
		data->rec.olddirX = data->rec.dirX;
		data->rec.dirX = data->rec.dirX * cos(-data->rec.rotation) -
			data->rec.dirY * sin(-data->rec.rotation);
		data->rec.dirY = data->rec.olddirX * sin(-data->rec.rotation) +
			data->rec.dirY * cos(-data->rec.rotation);
		data->rec.oldplaneX = data->rec.planeX;
		data->rec.planeX = data->rec.planeX * cos(-data->rec.rotation) -
			data->rec.planeY * sin(-data->rec.rotation);
		data->rec.planeY = data->rec. oldplaneX * sin(-data->rec.rotation) +
			data->rec.planeY * cos(-data->rec.rotation);
	}
	return (1);
}

int		keys_rot_right(t_data *data, int keycode)
{
	if (keycode == 124 || keycode == 2)
	{
		data->rec.olddirX = data->rec.dirX;
		data->rec.dirX = data->rec.dirX * cos(data->rec.rotation) -
			data->rec.dirY * sin(data->rec.rotation);
		data->rec.dirY = data->rec.olddirX * sin(data->rec.rotation) +
			data->rec.dirY * cos(data->rec.rotation);
		data->rec.oldplaneX = data->rec.planeX;
		data->rec.planeX = data->rec.planeX *  cos(data->rec.rotation) -
			data->rec.planeY * sin(data->rec.rotation);
		data->rec.planeY = data->rec.oldplaneX * sin(data->rec.rotation) +
			data->rec.planeY * cos(data->rec.rotation);
	}
	return (1);
}

int		ft_keyboard(int keycode, t_data *data)
{
	data->rec.oldplaneX = data->rec.planeX;
	if (keycode == 53 || keycode == 17)
		exit_all(data);
	keys_up_down(data, keycode);
	keys_rot_right(data, keycode);
	keys_rot_left(data, keycode);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	start_raycasting(data);
	return (0);
}
