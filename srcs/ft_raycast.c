/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:07:36 by edessain          #+#    #+#             */
/*   Updated: 2020/07/16 10:15:08 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*start_raycasting(t_data *data)
{
	int		x;
	int 	hit;

	x = 0;
	hit = 0;
	while (x < data->parse.r1)
	{
		hit = 0;
		ray_and_deltadist(x, data);
		step_and_sidedist(data);
		perform_dda(hit, data);
		calculate_dist(data);
		calculate_height(data);
		calculate_textures(data);
		calculate_colors(data);
		ft_verline(x, data);
		data->spr.zbuffer[x] = data->rec.perpwalldist;
		x++;
	}
	sprites_raycasting(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win, data->dis.img, 0, 0);
	return (NULL);
}

void	ft_verline(int x, t_data *data)
{
	int y;
	y = 0;
	while (y < data->rec.drawstart)
	{
		data->dis.addr[y * data->parse.r1 + x] = data->parse.c;
		y++;
	}
	while (y <= data->rec.drawend)
	{
		data->tex.texy = (int)data->tex.texpos & (data->tex.texheight - 1);
		data->tex.texpos += data->tex.step;
		data->dis.addr[y * data->parse.r1 + x] =
			data->tex.color[data->tex.texy * data->tex.texheight + data->tex.texx];
		y++;
	}
	while (y < data->parse.r2)
	{
		data->dis.addr[y * data->parse.r1 + x] = data->parse.f;
		y++;
	}
}
