/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:07:36 by edessain          #+#    #+#             */
/*   Updated: 2020/03/09 15:32:01 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//#define screenWidth 640
//#define screenHeight 480


#define mapWidth 24
#define mapHeight 24
/*
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
*/
int		ft_keyboard(int keycode, t_data *data)
{
	double		speed;
	double		rotation;
	
	speed = 0.2;
	rotation = 0.2;
	
	if (keycode == 53)
		exit(1);
	if (keycode == 126 || keycode == 13)
	{
//		if (worldMap[(int)(data->rec.posX + data->rec.dirX * speed)][(int)data->rec.posY] == '0')
			data->rec.posX += data->rec.dirX * speed;
//		if (worldMap[(int)data->rec.posX][(int)(data->rec.posY + data->rec.dirY * speed)] == '0')
			data->rec.posY += data->rec.dirY * speed;
	}
	if (keycode == 125 || keycode == 1)
	{
//		if (worldMap[(int)(data->rec.posX - data->rec.dirX * speed)][(int)data->rec.posY] == '0')
			data->rec.posX -= data->rec.dirX * speed;
//		if (worldMap[(int)data->rec.posX][(int)(data->rec.posY - data->rec.dirY * speed)] == '0')
			data->rec.posY -= data->rec.dirY * speed;
	}
	if (keycode == 124 || keycode == 2)
	{
		data->rec.olddirX = data->rec.dirX;
		data->rec.dirX = data->rec.dirX * cos(-rotation) - data->rec.dirY * sin(-rotation);
		data->rec.dirY = data->rec.olddirX * sin(-rotation) + data->rec.dirY * cos(-rotation);
		data->rec.oldplaneX = data->rec.planeX;
		data->rec.planeX = data->rec.planeX * cos(-rotation) - data->rec.planeY * sin(-rotation);
		data->rec.planeY = data->rec. oldplaneX * sin(-rotation) + data->rec.planeY * cos(-rotation);
	}
	if (keycode == 123 || keycode == 0)
	{
		data->rec.olddirX = data->rec.dirX;
		data->rec.dirX = data->rec.dirX * cos(rotation) - data->rec.dirY * sin(rotation);
		data->rec.dirY = data->rec.olddirX * sin(rotation) + data->rec.dirY * cos(rotation);
		data->rec.oldplaneX = data->rec.planeX;
		data->rec.planeX = data->rec.planeX *  cos(rotation) - data->rec.planeY * sin(rotation);
		data->rec.planeY = data->rec.oldplaneX * sin(rotation) + data->rec.planeY * cos(rotation);
	}
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	ft_algo(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win, data->dis.img, 0, 0);
	return (0);
}

void	ft_start_algo(t_data *data)
{
//	data->rec.posX = 22;
//	data->rec.posY = 12;
	data->rec.dirX = -1;
	data->rec.dirY = 0;
	data->rec.planeX = 0;
	data->rec.planeY = 0.66;

//	ft_parse_cub(data, filename);
	ft_algo(data);
}

void	*ft_algo(t_data *data)
{
	data->dis.color_sky = 65536 * 200 + 256 * 200 + 25;
	data->dis.color_wall_n = 65536 * 200 + 256 * 50 + 25;
	data->dis.color_wall_s = 65536 * 150 + 256 * 100 + 25;
	data->dis.color_wall_e = 65536 * 100 + 256 * 150 + 25;
	data->dis.color_wall_w = 65536 * 50 + + 256 * 200 + 25;
	data->dis.color_floor = 65536 * 200 + 256 * 175 + 150;
	
	int		x;
	x = 0;
	while (x < data->info.r1)
	{
		//caluclate ray position and direction
		data->rec.cameraX = 2 * x / (double)data->info.r1 - 1;//x-coordinate in camera space
		data->rec.raydirX = data->rec.dirX + data->rec.planeX * data->rec.cameraX;
		data->rec.raydirY = data->rec.dirY + data->rec.planeY * data->rec.cameraX;
		
		//which box of the map we're in
		data->rec.mapX = (int)data->rec.posX;
		data->rec.mapY = (int)data->rec.posY;
		
		//length of ray from one x or y-side to next x or y-side
		data->rec.deltadistX = fabs(1 / data->rec.raydirX);
		data->rec.deltadistY = fabs(1 / data->rec.raydirY);
		
//////////////////////////////////////////////////////////////////////////////////////////////

		//sidedist = length of ray from current position to next x or y-side
		//calculate step and initial sideDist
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
		
///////////////////////////////////////////////////////////////////////////////////////////
		//jump to next map square, OR in x-direction, OR in y-direction
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
			if (data->parse.map[data->rec.mapX][data->rec.mapY] == '1')
				data->rec.hit = 1;
//			if (worldMap[data->rec.mapX][data->rec.mapY] > 0)
//				data->rec.hit = 1;
		}
		
		
		
///////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (data->rec.side == 0)
			data->rec.perpwalldist = (data->rec.mapX - data->rec.posX
					+ (1 - data->rec.stepX) / 2) / data->rec.raydirX;
		else
			data->rec.perpwalldist = (data->rec.mapY - data->rec.posY
					+ (1 - data->rec.stepY) / 2) / data->rec.raydirY;

		data->rec.lineheight = (int)(data->info.r2 / data->rec.perpwalldist);
		data->rec.drawstart = -data->rec.lineheight / 2 + data->info.r2 / 2;
		
		
		
/////////////////////////////////////////////////////////////////////////////////////////////////////

		if (data->rec.drawstart < 0)
			data->rec.drawstart = 0;
		data->rec.drawend = data->rec.lineheight / 2 + data->info.r2 / 2;
		if (data->rec.drawend >= data->info.r2)
			data->rec.drawend = data->info.r2 - 1;
		ft_verline(x, data);
		x++;
	}
//	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win, data->dis.img, 0, 0);
	return (NULL);
}

void	ft_verline(int x, t_data *data)
{
	int y;
	
	y = 0;
	while (y < data->rec.drawstart)
	{
		data->dis.addr[y * data->info.r1 + x] = data->dis.color_floor;
		y++;
	}
	while (y < data->rec.drawend)
	{
//		if (data->rec.side == 0 && data->rec.raydirX <= 0)
//			data->dis.addr[y * screenWidth + x] = data->dis.color_wall_w;
//		if (data->rec.side == 0 && data->rec.raydirY > 0)
			data->dis.addr[y * data->info.r1 + x] = data->dis.color_wall_e;
//		if (data->rec.side == 1 && data->rec.raydirY > 0)
//			data->dis.addr[y * screenWidth + x] = data->dis.color_wall_s;
//		if (data->rec.side == 1 && data->rec.raydirY <= 0)
//			data->dis.addr[y * screenWidth + x] = data->dis.color_wall_n;
		y++;
	}
	while (y < data->info.r2)
	{
		data->dis.addr[y * data->info.r1 + x] = data->dis.color_sky;
		y++;
	}
}
