/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 11:33:37 by edessain          #+#    #+#             */
/*   Updated: 2020/06/12 09:46:31 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    calculate_height(t_data *data)
{
    data->rec.wallheight = data->parse.r2;
    data->rec.lineheight = (int)(data->rec.wallheight / data->rec.perpwalldist);
    data->rec.drawstart = -data->rec.lineheight / 2 + data->parse.r2 / 2;
    if (data->rec.drawstart < 0)
        data->rec.drawstart = 0;
    data->rec.drawend = data->rec.lineheight / 2 + data->parse.r2 / 2;
    if (data->rec.drawend >= data->parse.r2)
        data->rec.drawend = data->parse.r2 - 1;
}

void    calculate_dist(t_data *data)
{
    if (data->rec.side == 0)
        data->rec.perpwalldist = (data->rec.mapX - data->rec.posX
                + (1 - data->rec.stepX) / 2) / data->rec.raydirX;
    else
        data->rec.perpwalldist = (data->rec.mapY - data->rec.posY
                + (1 - data->rec.stepY) / 2) / data->rec.raydirY;
    if (data->rec.perpwalldist == 0)
        data->rec.perpwalldist = 0.1;
}

//jump to next map square, OR in x-direction, OR in y-direction
void    perform_dda(t_data *data)
{
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
    }
}
//sidedist = length of ray from current position to next x or y-side
//calculate step and initial sideDist
void    step_and_sidedist(t_data *data)
{
    if (data->rec.raydirX < 0)
    {
        data->rec.stepX = -1;
        data->rec.sidedistX = (data->rec.posX - data->rec.mapX) * data->rec.deltadistX;
    }
    else
    {
        data->rec.stepX = 1;
        data->rec.sidedistX = (data->rec.mapX + 1.0 - data->rec.posX) * data->rec.deltadistX;
    }
    if (data->rec.raydirY < 0)
    {
        data->rec.stepY = -1;
        data->rec.sidedistY = (data->rec.posY - data->rec.mapY) * data->rec.deltadistY;
    }
    else
    {
        data->rec.stepY = 1;
        data->rec.sidedistY = (data->rec.mapY + 1.0 - data->rec.posY) * data->rec.deltadistY;
    }
}

void    ray_and_deltadist(int x, t_data *data)
{
    data->rec.cameraX = 2 * x / (float)data->parse.r1 - 1;//x-coordinate in camera space
    data->rec.raydirX = data->rec.dirX + data->rec.planeX * data->rec.cameraX;
    data->rec.raydirY = data->rec.dirY + data->rec.planeY * data->rec.cameraX;

    //which box of the map we're in
    data->rec.mapX = (int)data->rec.posX;
    data->rec.mapY = (int)data->rec.posY;

    //length of ray from one x or y-side to next x or y-side
    data->rec.deltadistX = fabs(1 / data->rec.raydirX);
    data->rec.deltadistY = fabs(1 / data->rec.raydirY);
}
