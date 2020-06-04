/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 11:33:37 by edessain          #+#    #+#             */
/*   Updated: 2020/06/04 11:36:23 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    ray_and_deltadist(int x, t_data *data)
{
    data->rec.cameraX = 2 * x / (double)data->parse.r1 - 1;//x-coordinate in camera space
    data->rec.raydirX = data->rec.dirX + data->rec.planeX * data->rec.cameraX;
    data->rec.raydirY = data->rec.dirY + data->rec.planeY * data->rec.cameraX;

    //which box of the map we're in
    data->rec.mapX = (int)data->rec.posX;
    data->rec.mapY = (int)data->rec.posY;

    //length of ray from one x or y-side to next x or y-side
    data->rec.deltadistX = fabs(1 / data->rec.raydirX);
    data->rec.deltadistY = fabs(1 / data->rec.raydirY);
}
