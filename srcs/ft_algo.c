/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:31:12 by edessain          #+#    #+#             */
/*   Updated: 2020/03/05 13:32:56 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int		worldMap[mapWidth][mapHeight] =
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

void	ft_verline(int x, data_t *data)
{
	int i;

	i = 0;
	while (i < data->rec->drawstart)
	{
		data->rec->color = 65536 * 210 + 256 * 25 + 50;
		i++;
	}
	while (data->rec->drawstart < data->rec->drawend)
	{
		data->rec->color = 65536 * 100 + 256 * 25 + 50;
		data->rec->drawstart++;
	}
	while (data->rec->drawend < screenHeight)
	{
		data->rec->color = 65536 * 10 + 256 * 25 + 50;;
		data->rec->drawend++;
	}
}

void	pos_init(data_t *data)
{
	//position de depart
	data->rec->posX = 22; 
	data->rec->posY = 12;
	//direction de depart
	data->rec->dirX = -1;
	data->rec->dirY = 0;
	//vison de la camera
	data->rec->planeX = 0;
	data->rec->planeY = 0.66;
	//temps
	data->rec->time = 0;
	data->rec->oldtime = 0;
	//which box of the map we're in
	data->rec->mapX = data->rec->posX;
	data->rec->mapY = data->rec->posY;

	//length of ray from one x or y-side to next x or y-side
	data->rec->deltadistX = fabs(1 / data->rec->raydirX);
	data->rec->deltadistY = fabs(1 / data->rec->raydirY);

	data->rec->hit = 0; //was there a wall hit?

}


void	ft_algo(int argc, char **argv)
{
	data_t		data;
	int			x;

	x = 0;
	ft_init_struct(&data);
	pos_init(&data);
	while (++x < mapWidth)
	{
		ray_pos_dir(&data, mapWidth, mapHeight);
		make_step(&data);
		perf_DDA(&data);
		projection_wall(x, &data, mapWidth, mapHeight);
	}
}
