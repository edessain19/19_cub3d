/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:50:53 by edessain          #+#    #+#             */
/*   Updated: 2020/10/01 10:56:16 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		keys_up_down(t_data *data, int keycode)
{
	if (keycode == 119)
	{
		if (data->parse.map[(int)data->rec.posy]
			[(int)(data->rec.posx + data->rec.dirx *
				data->rec.speed)] != '1')
			data->rec.posx += data->rec.dirx * data->rec.speed;
		if (data->parse.map[(int)(data->rec.posy +
				data->rec.diry * data->rec.speed)][(int)data->rec.posx] != '1')
			data->rec.posy += data->rec.diry * data->rec.speed;
	}
	if (keycode == 115)
	{
		if (data->parse.map[(int)data->rec.posy]
			[(int)(data->rec.posx - data->rec.dirx *
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
	if (keycode == 65361)
	{
		data->rec.olddirx = data->rec.dirx;
		data->rec.dirx = data->rec.dirx * cos(-data->rec.rotation) -
			data->rec.diry * sin(-data->rec.rotation);
		data->rec.diry = data->rec.olddirx * sin(-data->rec.rotation) +
			data->rec.diry * cos(-data->rec.rotation);
		data->rec.oldplanex = data->rec.planex;
		data->rec.planex = data->rec.planex * cos(-data->rec.rotation)
			- data->rec.planey * sin(-data->rec.rotation);
		data->rec.planey = data->rec.oldplanex * sin(-data->rec.rotation) +
			data->rec.planey * cos(-data->rec.rotation);
	}
	return (1);
}

int		keys_rot_right(t_data *data, int keycode)
{
	if (keycode == 65363)
	{
		data->rec.olddirx = data->rec.dirx;
		data->rec.dirx = data->rec.dirx * cos(data->rec.rotation) -
			data->rec.diry * sin(data->rec.rotation);
		data->rec.diry = data->rec.olddirx * sin(data->rec.rotation) +
			data->rec.diry * cos(data->rec.rotation);
		data->rec.oldplanex = data->rec.planex;
		data->rec.planex = data->rec.planex * cos(data->rec.rotation) -
			data->rec.planey * sin(data->rec.rotation);
		data->rec.planey = data->rec.oldplanex * sin(data->rec.rotation) +
			data->rec.planey * cos(data->rec.rotation);
	}
	return (1);
}

int		key_move_right_left(t_data *data, int keycode)
{
	if (keycode == 97)
	{
		if (data->parse.map[(int)(data->rec.posy - data->rec.dirx *
		(data->rec.speed))][(int)data->rec.posx] != '1')
			data->rec.posy -= data->rec.dirx * data->rec.speed;
		if (data->parse.map[(int)data->rec.posy][(int)(data->rec.posx +
		data->rec.diry * (data->rec.speed))] != '1')
			data->rec.posx += data->rec.diry * data->rec.speed;
	}
	if (keycode == 100)
	{
		if (data->parse.map[(int)(data->rec.posy + data->rec.dirx *
		(data->rec.speed))][(int)data->rec.posx] != '1')
			data->rec.posy += data->rec.dirx * data->rec.speed;
		if (data->parse.map[(int)data->rec.posy][(int)(data->rec.posx -
		data->rec.diry * (data->rec.speed))] != '1')
			data->rec.posx -= data->rec.diry * data->rec.speed;
	}
	return (1);
}

int		ft_keyboard(int keycode, t_data *data)
{
	data->rec.oldplanex = data->rec.planex;
	if (keycode == 65307 || keycode == 17)
		exit_all(data);
	keys_up_down(data, keycode);
	keys_rot_right(data, keycode);
	keys_rot_left(data, keycode);
	key_move_right_left(data, keycode);
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	start_raycasting(data);
	return (0);
}
