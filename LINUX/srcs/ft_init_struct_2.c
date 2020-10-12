/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:28:56 by evrard            #+#    #+#             */
/*   Updated: 2020/09/01 09:09:38 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_parse(t_data *data)
{
	data->parse.info = NULL;
	data->parse.map_str = NULL;
	data->parse.map = NULL;
	data->parse.dir = 0;
	data->parse.screen_x = 0;
	data->parse.screen_y = 0;
	data->parse.n_path = 0;
	data->parse.s_path = 0;
	data->parse.w_path = 0;
	data->parse.e_path = 0;
	data->parse.sp_path = 0;
	data->parse.s = 0;
	data->parse.f = -1;
	data->parse.f1 = 0;
	data->parse.f2 = 0;
	data->parse.f3 = 0;
	data->parse.c = -1;
	data->parse.c1 = 0;
	data->parse.c2 = 0;
	data->parse.c3 = 0;
	data->parse.map_h = 0;
	data->parse.map_w = 0;
	data->parse.pos_ix = 0;
	data->parse.pos_iy = 0;
}

void		init_dis(t_data *data)
{
	data->dis.addr = 0;
	data->dis.img = 0;
	data->dis.line_length = 0;
	data->dis.endian = 0;
	data->dis.bits_per_pixel = 0;
}

void		init_check(t_data *data)
{
	data->check.v_r = -1;
	data->check.v_path_n = -1;
	data->check.v_path_s = -1;
	data->check.v_path_e = -1;
	data->check.v_path_w = -1;
	data->check.v_path_sp = -1;
	data->check.v_c = -1;
	data->check.v_f = -1;
}
