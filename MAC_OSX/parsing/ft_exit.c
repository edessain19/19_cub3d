/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:56:02 by evrard            #+#    #+#             */
/*   Updated: 2020/06/10 11:08:49 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_win(t_data *data)
{
	if (data->mlx.mlx_ptr && data->mlx.mlx_win)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
}

void	free_map(t_data *data)
{
	int		i;

	i = 0;
	if (data->parse.map_h)
	{
		while (i < data->parse.map_h)
		{
			free(data->parse.map[i]);
			data->parse.map[i] = 0;
			i++;
		}
		free(data->parse.map);
		data->parse.map = 0;
	}
}

void	free_info(t_data *data)
{
	if (data->parse.n_path)
	{
		free(data->parse.n_path);
		data->parse.n_path = 0;
	}
	if (data->parse.s_path)
	{
		free(data->parse.s_path);
		data->parse.s_path = 0;
	}
	if (data->parse.e_path)
	{
		free(data->parse.e_path);
		data->parse.e_path = 0;
	}
	if (data->parse.w_path)
	{
		free(data->parse.w_path);
		data->parse.w_path = 0;
	}
}

void	free_parsing(t_data *data)
{
	if (data->parse.info)
	{
		free(data->parse.info);
		data->parse.info = 0;
	}
	if (data->parse.map_str)
	{
		free(data->parse.map_str);
		data->parse.map_str = 0;
	}
}

int		exit_all(t_data *data)
{
	free_win(data);
	free_map(data);
	free_info(data);
	free_parsing(data);
	exit(0);
	return (-1);
}
