/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:33 by evrard            #+#    #+#             */
/*   Updated: 2020/07/16 15:03:35 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int 	check_textures(t_data *data)
{
	if (check_path(data, data->parse.n_path) < 0)
		return (-1);
	if (check_path(data, data->parse.s_path) < 0)
		return (-1);
	if (check_path(data, data->parse.w_path) < 0)
		return (-1);
	if (check_path(data, data->parse.e_path) < 0)
		return (-1);
	if (check_path(data, data->parse.sp_path) < 0)
		return (-1);
	return (1);
}

int	    check_path(t_data *data, char *str)
{
	int 	i;

	i = 0;
	if (str[0] != '.' || str[1] != '/')
	{
		// Attention a verifier que cette condition soit bonne!!!! vraiment pas sûr
		write(1, "Error\n", 6);
		write(1, "Wrong texture path\n", 19);
		return (exit_all(data));
	}
	while (str[i] != 0)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			write(1, "Error\n", 6);
			write(1, "Wrong texture path\n", 19);
			return (exit_all(data));
		}
		i++;
	}
	return (1);
}

int	    check_others(t_data *data)
{
	if (data->parse.r1 <= 0 || data->parse.r2 <= 0)
	{
		write(1, "Error\n", 6);
		write(1, "--> Wrong resolution details\n", 28);
		return (exit_all(data));
	}
	if (data->parse.r1 > 2560)
		data->parse.r1 = 2560;
	if (data->parse.r2 > 1440)
		data->parse.r2 = 1440;
    if (data->parse.f < 0 || data->parse.c < 0)
        return (exit_all(data));
    return (1);
}
