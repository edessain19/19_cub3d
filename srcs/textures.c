/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 09:49:35 by edessain          #+#    #+#             */
/*   Updated: 2020/06/23 16:10:57 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    calculate_colors(t_data *data)
{
    if (data->rec.side == 1 && (data->rec.mapY > data->rec.posY))
        data->tex.color = (int *)data->tex.color_s;
    else if (data->rec.side == 1 && (data->rec.mapY < data->rec.posY))
        data->tex.color = (int *)data->tex.color_n;
    else if (data->rec.side == 0 && (data->rec.mapX > data->rec.posX))
        data->tex.color = (int *)data->tex.color_e;
    else
        data->tex.color = (int *)data->tex.color_w;
}

void	calculate_textures(t_data *data)
{
	float	wallx;

    data->tex.texnum = data->parse.map[data->rec.mapX][data->rec.mapY] - 1;
	if (data->rec.side == 0)
		wallx = data->rec.posY + data->rec.perpwalldist * data->rec.raydirY;
	else
		wallx = data->rec.posX + data->rec.perpwalldist * data->rec.raydirX;
	wallx -= floor((wallx));
	data->tex.texx = (int)(wallx * data->tex.texheight);
	if (data->rec.side == 0 && data->rec.raydirX > 0)
		data->tex.texx = data->tex.texwidth - data->tex.texx - 1;
	if (data->rec.side == 1 && data->rec.raydirY < 0)
		data->tex.texx = data->tex.texwidth - data->tex.texx - 1;
    data->tex.step = 1.0 * data->tex.texheight / data->rec.lineheight;
	data->tex.texpos = (data->rec.drawstart - data->parse.r2 / 2 + data->rec.lineheight / 2)
		* data->tex.step;
}

int		create_images2(t_data *data)
{
	if (!(data->tex.color_e = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->parse.e_path,
		&data->tex.texwidth, &data->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "e wrong path texture", 20);
		return (-1);
	}
//	if (!(data->spr.spr_tex = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->el.spr_path,
//		&data->spr.sprwidth, &data->spr.sprheight)))
//	{
//		write(1, "Error\n", 6);
//		write(1, "texture of the sprite is wrong", 30);
//		return (exit_all(m));
//	}
	return (1);
}

int		create_images1(t_data *data)
{
	if (!(data->tex.color_n = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->parse.n_path,
		&data->tex.texwidth, &data->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "n wrong path texture\n", 20);
		return (-1);
	}
	if (!(data->tex.color_s = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->parse.s_path,
		&data->tex.texwidth, &data->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "s wrong path texture", 20);
		return (-1);
	}
	if (!(data->tex.color_w = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->parse.w_path,
		&data->tex.texwidth, &data->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "w wrong path texture", 20);
		return (-1);
	}
	return (1);
}

int		generate_textures(t_data *data)
{
	if (create_images1(data) < 0)
		return (-1);
	if (create_images2(data) < 0)
		return (-1);
    printf("%s\n", data->tex.color_n);
    data->tex.color_n = mlx_get_data_addr(data->tex.color_n,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
    printf("%s\n", data->tex.color_n);
    data->tex.color_s = mlx_get_data_addr(data->tex.color_s,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
	data->tex.color_w = mlx_get_data_addr(data->tex.color_w,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
	data->tex.color_e = mlx_get_data_addr(data->tex.color_e,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
//	m->spr.spr_tex = mlx_get_data_addr(m->spr.spr_tex,
//		&m->img.bits_per_pixel, &m->img.line_length, &m->img.endian);
	return (0);
}
