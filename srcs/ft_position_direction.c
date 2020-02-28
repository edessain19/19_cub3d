/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:54:37 by edessain          #+#    #+#             */
/*   Updated: 2020/02/28 15:03:39 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ray_pos_dir(data_t *data, int w, int h)//calculate ray posi & dir
{
	data->dir->cameraX = 2 * (double)w - 1; //x-coordinate in camer space
	data->dir->raydirX = data->pos->dirX + data->pos->planeX + data->dir->cameraX;
	data->dir->raydirX = data->pos->dirY + data->pos->planeY + data->dir->cameraX;

	data->dir->deltadistX = fabs(1 / data->dir->raydirX);
	data->dir->deltadistY = fabs(1 / data->dir->raydirY);
}
