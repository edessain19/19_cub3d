/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:23:04 by edessain          #+#    #+#             */
/*   Updated: 2020/03/04 17:06:14 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		init_position(data_t *data)
{
	data->rec->posX = 0;
	data->rec->posY = 0;
	data->rec->dirX = 0;
	data->rec->dirY = 0;
	data->rec->planeX = 0;
	data->rec->planeY = 0;
	data->rec->time = 0;
	data->rec->oldtime = 0;
	data->rec->cameraX = 0;
	data->rec->raydirX = 0;
	data->rec->raydirY = 0;
	data->rec->mapX = 0;
	data->rec->mapY = 0;
	data->rec->sidedistX = 0;
	data->rec->sidedistY = 0;
	data->rec->perpwalldist = 0;
	data->rec->stepX = 0;
	data->rec->stepY = 0;
	data->rec->hit = 0;
	data->rec->side = 0;
	data->rec->lineheight = 0;
	data->rec->drawstart = 0;
	data->rec->drawend = 0;
	data->rec->color = 0;
}

void		init_mlx(data_t *data)
{
	data->mlx->mlx_ptr = 0;
	data->mlx->mlx_win = 0;
}

void		init_dis(data_t *data)
{
	data->dis->addr = 0;
	data->dis->color_sky = 0;
	data->dis->color_floor = 0;
	data->dis->color_wall = 0;
}

void		ft_init_struct(data_t *data)
{
	init_position(data);
	init_mlx(data);
	init_dis(data);


}
