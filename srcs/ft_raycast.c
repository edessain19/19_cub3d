/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:07:36 by edessain          #+#    #+#             */
/*   Updated: 2020/03/05 13:57:48 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ft_algo(t_data *data)
{
	ft_start_algo(data);
}

void	*ft_start_algo(t_data *data)
{
	int x;

	x = 0;
	data->rec.posX = 22;
	data->rec.posY = 12;
	data->rec.dirX = -1;
	data->rec.dirY = 0;
	data->rec.planeX = 0;
	data->rec.planeY = 0.66;
	
	data->dis.color_sky = 65536 * 200 + 256 * 50 + 25;
	data->dis.color_wall1 = 65536 * 100 + 256 * 150 + 25;
	data->dis.color_wall2 = 65536 * 100 + 256 * 250 + 25;
	data->dis.color_floor = 65536 * 50 + 256 * 50 + 200;
	
	while (x < screenWidth)
	{
		
		data->rec.cameraX = 2 * x / (double)screenWidth - 1;
		data->rec.raydirX = data->rec.dirX + data->rec.planeX * data->rec.cameraX;
		data->rec.raydirY = data->rec.dirY + data->rec.planeY * data->rec.cameraX;
		
		data->rec.mapX = (int)data->rec.posX;
		data->rec.mapY = (int)data->rec.posY;

		data->rec.deltadistX = fabs(1 / data->rec.raydirX);
		data->rec.deltadistY = fabs(1 / data->rec.raydirY);
		
		data->rec.hit = 0;
		if (data->rec.raydirX < 0)
		{
			data->rec.stepX = -1;
			data->rec.sidedistX = (data->rec.posX - data->rec.mapX)
				* data->rec.deltadistX;
		}
		else
		{
			data->rec.stepX = 1;
			data->rec.sidedistX = (data->rec.mapX + 1.0 - data->rec.posX) *
				data->rec.deltadistX;
		}
		if (data->rec.raydirY < 0)
		{
			data->rec.stepY = -1;
			data->rec.sidedistY = (data->rec.posY - data->rec.mapY) *
				data->rec.deltadistY;
		}
		else
		{
			data->rec.stepY = 1;
			data->rec.sidedistY = (data->rec.mapY + 1.0 - data->rec.posY) *
				data->rec.deltadistY;
		}
		while (data->rec.hit == 0)
		{
			if (data->rec.sidedistX < data->rec.sidedistY)
			{
				data->rec.sidedistX += data->rec.deltadistX;
				data->rec.mapX += data->rec.stepX;
				data->rec.side = 0;
			}
			else
			{
				data->rec.sidedistY += data->rec.deltadistY;
				data->rec.mapY += data->rec.stepY;
				data->rec.side = 1;
			}
			if (worldMap[data->rec.mapX][data->rec.mapY] > 0)
				data->rec.hit = 1;
		}
		if (data->rec.side == 0)
			data->rec.perpwalldist = (data->rec.mapX - data->rec.posX
					+ (1 - data->rec.stepX) / 2) / data->rec.raydirX;
		else
			data->rec.perpwalldist = (data->rec.mapY - data->rec.posY
					+ (1 - data->rec.stepY) / 2) / data->rec.raydirY;

		data->rec.lineheight = (int)(screenHeight / data->rec.perpwalldist);
		data->rec.drawstart = -data->rec.lineheight / 2 + screenHeight / 2;
		
		if (data->rec.drawstart < 0)
			data->rec.drawstart = 0;
		data->rec.drawend = data->rec.lineheight / 2 + screenHeight / 2;
		if (data->rec.drawend >= screenHeight)
			data->rec.drawend = screenHeight - 1;
		
		if (data->rec.side == 2)
			data->dis.color_wall1 = data->dis.color_wall2;
		ft_verline(x, data);
		x++;
	}
	return (NULL);
}

void	ft_verline(int x, t_data *data)
{
	int y;
	
	y = 0;
	while (y < data->rec.drawstart)
	{
		data->dis.addr[y * screenWidth + x] = data->dis.color_floor;
		y++;
	}
	while (y < data->rec.drawend)
	{
		data->dis.addr[y * screenWidth + x] = data->dis.color_wall1;
		y++;
	}
	while (y < screenHeight)
	{
		data->dis.addr[y * screenWidth + x] = data->dis.color_sky;
		y++;
	}
}
