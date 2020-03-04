/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_flat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:22:28 by aglorios          #+#    #+#             */
/*   Updated: 2020/03/02 15:52:46 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		ft_keyboard(int keycode, pos *one)
{
	(void)one;
	one->moveSpeed = 0.5;
	one->rotSpeed = 0.2;

	if (keycode == 53)
		exit(1);
	if (keycode == 13 || keycode == 126)
	{
		if (worldMap[(int)(one->posX + one->dirX * one->moveSpeed)][(int)one->posY] == 0)
			one->posX += one->dirX * one->moveSpeed;
		if (worldMap[(int)one->posX][(int)(one->posY + one->dirY * one->moveSpeed)] == 0)
			one->posY += one->dirY * one->moveSpeed;
	}
	if (keycode == 1 || keycode == 125)
	{
		if (worldMap[(int)(one->posX - one->dirX * one->moveSpeed)][(int)one->posY] == 0)
			one->posX -= one->dirX * one->moveSpeed;
		if (worldMap[(int)one->posX][(int)(one->posY - one->dirY * one->moveSpeed)] == 0)
			one->posY -= one->dirY * one->moveSpeed;
	}
	if (keycode == 14)
	{
		if (worldMap[(int)one->posX][(int)(one->posY - one->dirX * one->moveSpeed)] == 0)
			one->posY -= one->dirX * one->moveSpeed;
		if (worldMap[(int)(one->posX + one->dirX * one->moveSpeed)][(int)one->posY] == 0)
			one->posX += one->dirY * one->moveSpeed;
	}
	if (keycode == 12)
	{
		if (worldMap[(int)one->posX][(int)(one->posY + one->dirX * one->moveSpeed)] == 0)
			one->posY += one->dirX * one->moveSpeed;
		if (worldMap[(int)(one->posX - one->dirX * one->moveSpeed)][(int)one->posY] == 0)
			one->posX -= one->dirY * one->moveSpeed;
	}
	if (keycode == 2 || keycode == 124)
	{
		one->oldDirX = one->dirX;
		one->dirX = one->dirX * cos(-(one->rotSpeed)) - one->dirY * sin(-(one->rotSpeed));
		one->dirY = one->oldDirX * sin(-(one->rotSpeed)) + one->dirY * cos(-(one->rotSpeed));
		one->oldPlaneX = one->planeX;
		one->planeX = one->planeX * cos(-(one->rotSpeed)) - one->planeY * sin(-(one->rotSpeed));
		one->planeY = one->oldPlaneX * sin(-(one->rotSpeed)) + one->planeY * cos(-(one->rotSpeed));
	}
	if (keycode == 0 || keycode == 123)
	{
		one->oldDirX = one->dirX;
		one->dirX = one->dirX * cos(one->rotSpeed) - one->dirY * sin(one->rotSpeed);
		one->dirY = one->oldDirX * sin(one->rotSpeed) + one->dirY * cos(one->rotSpeed);
		one->oldPlaneX = one->planeX;
		one->planeX = one->planeX * cos(one->rotSpeed) - one->planeY * sin(one->rotSpeed);
		one->planeY = one->oldPlaneX * sin(one->rotSpeed) + one->planeY * cos(one->rotSpeed);
	}
	//	printf("%i", keycode);
	raycast_flat(one->mlx, one);
	mlx_put_image_to_window(one->mlx, one->mlx_win, one->img, 0, 0);
	return (0);
}
void	*raycast_flat(void *mlx1, pos *one)
{
	int	x;

	x = 0;
	mlx1 = 0;
	while (x < screenWidth)
	{
		one->cameraX = 2 * x / (double)screenWidth - 1;
		one->rayDirX = one->dirX + one->planeX * one->cameraX;
		one->rayDirY = one->dirY + one->planeY * one->cameraX;

		/////////////////////////////////////////////////////////////////////////
		one->mapX = (int)one->posX;
		one->mapY = (int)one->posY;

		one->deltaDistX = fabs(1 / one->rayDirX);
		one->deltaDistY = fabs(1 / one->rayDirY);

		one->hit = 0;

		/////////////////////////////////////////////////////////////////////////
		if (one->rayDirX < 0)
		{
			one->stepX = -1;
			one->sideDistX = (one->posX - one->mapX) * one->deltaDistX;
		}
		else
		{
			one->stepX = 1;
			one->sideDistX = (one->mapX + 1.0 - one->posX) * one->deltaDistX;
		}
		if (one->rayDirY < 0)
		{
			one->stepY = -1;
			one->sideDistY = (one->posY - one->mapY) * one->deltaDistY;
		}
		else
		{
			one->stepY = 1;
			one->sideDistY = (one->mapY + 1.0 - one->posY) * one->deltaDistY;
		}
		while (one->hit == 0)
		{
			if (one->sideDistX < one->sideDistY)
			{
				one->sideDistX += one->deltaDistX;
				one->mapX += one->stepX;
				one->side = 0;
			}
			else
			{
				one->sideDistY += one->deltaDistY;
				one->mapY += one->stepY;
				one->side = 1;
			}
			if (worldMap[one->mapX][one->mapY] > 0) 
				one->hit = 1;
		}
		/////////////////////////////////////////////////////////////////////////
		if (one->side == 0)
			one->perpWallDist = (one->mapX - one->posX + (1 - one->stepX) / 2) / one->rayDirX;
		else
			one->perpWallDist = (one->mapY - one->posY + (1 - one->stepY) / 2) / one->rayDirY;

		one->lineHeight = (int)(screenHeight / one->perpWallDist);
		one->drawStart = -one->lineHeight / 2 + screenHeight / 2; 
		if (one->drawStart < 0)
			one->drawStart = 0;
		one->drawEnd = one->lineHeight / 2 + screenHeight / 2; 
		if (one->drawEnd >= screenHeight)
			one->drawEnd = screenHeight - 1;
		/////////////////////////////////////////////////////////////////////////
		if (one->side == 2) /// MARCHE PLUS
			one->wall1 = one->wall2;
		int y = 0;
		while (y < one->drawStart)
		{
			one->addr[y * screenWidth + x] = one->sky;
			y++;
		}
		while (y < one->drawEnd)
		{
			one->addr[y * screenWidth + x] = one->wall1;
			y++;
		}
		while (y < screenHeight)
		{
			one->addr[y * screenWidth + x] = one->ground;
			y++;
		}
		x++;
	}
	return (NULL);
}
