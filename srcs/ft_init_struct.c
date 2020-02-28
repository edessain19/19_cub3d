/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:23:04 by edessain          #+#    #+#             */
/*   Updated: 2020/02/28 11:54:09 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		init_position(data_t *data)
{
	data->position->posX = 0;
	data->position->posY = 0;
	data->position->dirX = 0;
	data->position->dirY = 0;
	data->position->planeX = 0;
	data->position->planeY = 0;
	data->position->time = 0;
	data->position->oldtime = 0;
	data->position->cameraX = 0;
	data->position->cameraY = 0;
}

void		init_mlx(data_t *data)
{
	data->mlx->mlx_ptr = 0;
	data->mlx->mlx_win = 0;
}



void		ft_init_struct(data_t *data)
{
	init_position(data);
	init_mlx(data);



}
