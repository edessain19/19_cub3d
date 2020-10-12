/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:35:19 by edessain          #+#    #+#             */
/*   Updated: 2020/10/01 10:58:27 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_colors(t_data *data)
{
	if (data->rec.side == 1 && (data->rec.mapy > data->rec.posy))
		data->tex.color = (int *)data->tex.color_s;
	else if (data->rec.side == 1 && (data->rec.mapy < data->rec.posy))
		data->tex.color = (int *)data->tex.color_n;
	else if (data->rec.side == 0 && (data->rec.mapx > data->rec.posx))
		data->tex.color = (int *)data->tex.color_e;
	else
		data->tex.color = (int *)data->tex.color_w;
	data->spr.color = (int *)data->spr.spr_tex;
}

void	calculate_textures(t_data *data)
{
	float	wallx;

	if (data->rec.side == 0)
		wallx = data->rec.posy + data->rec.perpwalldist * data->rec.raydiry;
	else
		wallx = data->rec.posx + data->rec.perpwalldist * data->rec.raydirx;
	wallx -= floor((wallx));
	data->tex.texx = (int)(wallx * data->tex.texheight);
	if (data->rec.side == 0 && data->rec.raydirx > 0)
		data->tex.texx = data->tex.texwidth - data->tex.texx - 1;
	if (data->rec.side == 1 && data->rec.raydiry < 0)
		data->tex.texx = data->tex.texwidth - data->tex.texx - 1;
	data->tex.step = 1.0 * data->tex.texheight / data->rec.lineheight;
	data->tex.texpos = (data->rec.drawstart - data->parse.screen_y / 2 +
			data->rec.lineheight / 2) * data->tex.step;
}

int		create_images2(t_data *data)
{
	if (!(data->tex.color_e = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			data->parse.e_path, &data->tex.texwidth, &data->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "e wrong path texture", 20);
		return (exit_all(data));
	}
	if (!(data->spr.spr_tex = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			data->parse.sp_path, &data->spr.sprwidth, &data->spr.sprheight)))
	{
		write(1, "Error\n", 6);
		write(1, "texture of the sprite is wrong", 30);
		return (exit_all(data));
	}
	return (1);
}

int		create_images1(t_data *data)
{
	if (!(data->tex.color_n = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			data->parse.n_path, &data->tex.texwidth, &data->tex.texwidth)))
	{
		write(1, "Error\n", 6);
		write(1, "n wrong path texture\n", 20);
		return (exit_all(data));
	}
	if (!(data->tex.color_s = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			data->parse.s_path, &data->tex.texwidth, &data->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "s wrong path texture", 20);
		return (exit_all(data));
	}
	if (!(data->tex.color_w = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
		data->parse.w_path, &data->tex.texwidth, &data->tex.texheight)))
	{
		write(1, "Error\n", 6);
		write(1, "w wrong path texture", 20);
		return (exit_all(data));
	}
	return (1);
}

int		generate_textures(t_data *data)
{
	if (create_images1(data) < 0)
		return (exit_all(data));
	if (create_images2(data) < 0)
		return (exit_all(data));
	data->tex.color_n = mlx_get_data_addr(data->tex.color_n,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
	data->tex.color_s = mlx_get_data_addr(data->tex.color_s,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
	data->tex.color_w = mlx_get_data_addr(data->tex.color_w,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
	data->tex.color_e = mlx_get_data_addr(data->tex.color_e,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
	data->spr.spr_tex = mlx_get_data_addr(data->spr.spr_tex,
		&data->dis.bits_per_pixel, &data->dis.line_length, &data->dis.endian);
	return (0);
}
