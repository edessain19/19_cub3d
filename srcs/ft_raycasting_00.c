/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:54:37 by edessain          #+#    #+#             */
/*   Updated: 2020/03/04 15:29:33 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	ray_pos_dir(data_t *data, int w, int h)//calculate ray posi & dir
{
	data->rec->cameraX = 2 * (double)w - 1; //x-coordinate in camer space
	data->rec->raydirX = data->rec->dirX + data->rec->planeX + data->rec->cameraX;
	data->rec->raydirX = data->rec->dirY + data->rec->planeY + data->rec->cameraX;

	data->rec->deltadistX = fabs(1 / data->rec->raydirX);
	data->rec->deltadistY = fabs(1 / data->rec->raydirY);
}

void	make_step(data_t *data) //calculate step and initial sideDist
{
	if (data->rec->raydirX < 0)
	{
		data->rec->stepX = -1;
		data->rec->sidedistX = (data->rec->posX - data->rec->mapX) 
			* data->rec->deltadistX;
	}
	else
	{
		data->rec->stepX = 1;
		data->rec->sidedistX = (data->rec->mapX + 1.0 - data->rec->posX) 
			* data->rec->deltadistX;
	}
	if (data->rec->raydirY < 0)
	{
		data->rec->stepY = -1;
		data->rec->sidedistY = (data->rec->posY - data->rec->mapY) 
			* data->rec->deltadistY;
	}
	else
	{
		data->rec->stepY = 1;
		data->rec->sidedistY = (data->rec->mapY + 1.0 - data->rec->posY) 
			* data->rec->deltadistY;
	}
}

void	perf_DDA(data_t *data)
{
	while (data->rec->hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (data->rec->sidedistX < data->rec->sidedistY)
		{
			data->rec->sidedistX += data->rec->deltadistX;
			data->rec->mapX += data->rec->stepX;
			data->rec->side = 0;
		}
		else
		{
			data->rec->sidedistY += data->rec->deltadistY;
			data->rec->mapY += data->rec->stepY;
			data->rec->side = 1;
		}
		//Check if ray has hit a wall
		if (world_map[data->rec->mapX][data->rec->mapY] > 0)
			data->rec->hit = 1;
	}
}

void	projection_wall(int x, data_t *data, int w, int h)
{
	if (data->rec->side == 0)
		data->rec->perpwalldist = (data->rec->mapX - data->rec->posX 
				+ (1 - data->rec->stepX) / 2) / data->rec->raydirX;
	else
		data->rec->perpwalldist = (data->rec->mapX - data->rec->posX
				+ (1 - data->rec->posY) / 2) / data->rec->raydirY;
	//Calculate height of line to draw on screen
	data->rec->lineheight = (int)(h / data->rec->perpwalldist);
	//calculate lowest and highest pixel to fill in current stripe
	data->rec->drawstart = (-1 * data->rec->lineheight) / 2 + h / 2;
	if(data->rec->drawstart < 0)
		data->rec->drawstart = 0;
	data->rec->drawend = data->rec->lineheight / 2 + h / 2;
	if(data->rec->drawend >= h)
		data->rec->drawend = h - 1;
	ft_verline(x, data);
	//	wall_color(data, world_map);
}

/*
   void	wall_color(data_t *data, int **world_map)
   {
   data->rec->color = 65536 * 210 + 256 * 25 + 50;
   if (data->rec->side == 1)
   data->rec->color = data->rec->color / 2;
   drawn_line(data->rec->posX, data->rec->drawstart, data->rec->drawend, 
   data->rec->color);
   }
   */

