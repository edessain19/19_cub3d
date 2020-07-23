/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:50:53 by hbuisser          #+#    #+#             */
/*   Updated: 2020/07/23 10:01:44 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		keys_up_down(t_data *data, int keycode)
{
	if (keycode == 126 || keycode == 13)
	{
		if (data->parse.map[(int)data->rec.posy][(int)(data->rec.posx + data->rec.dirx *
				data->rec.speed)] != '1')
			data->rec.posx += data->rec.dirx * data->rec.speed;
		if (data->parse.map[(int)(data->rec.posy +
				data->rec.diry * data->rec.speed)][(int)data->rec.posx] != '1')
			data->rec.posy += data->rec.diry * data->rec.speed;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (data->parse.map[(int)data->rec.posy][(int)(data->rec.posx - data->rec.dirx *
				data->rec.speed)] != '1')
			data->rec.posx -= data->rec.dirx * data->rec.speed;
		if (data->parse.map[(int)(data->rec.posy -
				data->rec.diry * data->rec.speed)][(int)data->rec.posx] != '1')
			data->rec.posy -= data->rec.diry * data->rec.speed;
	}
	return (1);
}

int		keys_rot_left(t_data *data, int keycode)
{
	if (keycode == 123)
	{
		data->rec.olddirx = data->rec.dirx;
		data->rec.dirx = data->rec.dirx * cos(-data->rec.rotation) -
			data->rec.diry * sin(-data->rec.rotation);
		data->rec.diry = data->rec.olddirx * sin(-data->rec.rotation) +
			data->rec.diry * cos(-data->rec.rotation);
		data->rec.oldplanex = data->rec.planex;
		data->rec.planex = data->rec.planex * cos(-data->rec.rotation) -
			data->rec.planey * sin(-data->rec.rotation);
		data->rec.planey = data->rec. oldplanex * sin(-data->rec.rotation) +
			data->rec.planey * cos(-data->rec.rotation);
	}
	return (1);
}

int		keys_rot_right(t_data *data, int keycode)
{
	if (keycode == 124)
	{
		data->rec.olddirx = data->rec.dirx;
		data->rec.dirx = data->rec.dirx * cos(data->rec.rotation) -
			data->rec.diry * sin(data->rec.rotation);
		data->rec.diry = data->rec.olddirx * sin(data->rec.rotation) +
			data->rec.diry * cos(data->rec.rotation);
		data->rec.oldplanex = data->rec.planex;
		data->rec.planex = data->rec.planex *  cos(data->rec.rotation) -
			data->rec.planey * sin(data->rec.rotation);
		data->rec.planey = data->rec.oldplanex * sin(data->rec.rotation) +
			data->rec.planey * cos(data->rec.rotation);
	}
	return (1);
}

int 	key_move_right_left(t_data *data, int keycode)
{
	if (keycode == 0) //left
	{
		if (data->parse.map[(int)(data->rec.posy - data->rec.dirx *
		(data->rec.speed + 0.1))][(int)data->rec.posx] != '1')
			data->rec.posy -= data->rec.dirx * data->rec.speed;
		if (data->parse.map[(int)data->rec.posy][(int)(data->rec.posx +
		data->rec.diry * (data->rec.speed + 0.1))] != '1')
			data->rec.posx += data->rec.diry * data->rec.speed;
	}
	if (keycode == 2) //right
	{
		if (data->parse.map[(int)(data->rec.posy + data->rec.dirx *
		(data->rec.speed * 0.1))][(int)data->rec.posx] != '1')
			data->rec.posy += data->rec.dirx * data->rec.speed;
		if (data->parse.map[(int)data->rec.posy][(int)(data->rec.posx -
		data->rec.diry * (data->rec.speed + 0.1))] != '1')
			data->rec.posx -= data->rec.diry * data->rec.speed;
	}
	return (1);
}

int		ft_keyboard(int keycode, t_data *data)
{
	data->rec.oldplanex = data->rec.planex;
	if (keycode == 53 || keycode == 17)
		exit_all(data);
	keys_up_down(data, keycode);
	keys_rot_right(data, keycode);
	keys_rot_left(data, keycode);
	key_move_right_left(data, keycode);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	start_raycasting(data);
	return (0);
}
