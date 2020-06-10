/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:35:39 by evrard            #+#    #+#             */
/*   Updated: 2020/06/10 14:46:52 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int     check_pos_init(t_data *data)
{
    if (data->parse.dir == 'N' || data->parse.dir == 'S' ||
            data->parse.dir == 'W' || data->parse.dir == 'E')
            return (0);
    else
    {
        write(1, "Error\n", 6);
        write(1, "There is no initial position\n", 29);
        return (exit_all(data));
    }
}

int		check_borders_columns(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->parse.map[i] != NULL)
	{
		j = 0;
		while (data->parse.map[i][j] != '\0')
			j++;
		if (data->parse.map[i][j - 1] != '1')
            return_error_exit(data);
        i++;
	}
	i = 0;
	while (data->parse.map[i] != NULL)
	{
		if (data->parse.map[i][0] != '1' && ft_isspace(data->parse.map[i][0]) == 0)
            return_error_exit(data);
        i++;
	}
	return (1);
}

int		check_borders_lines(t_data *data)
{
	int j;

	j = 0;
	while (data->parse.map[0][j] != '\0')
	{
		if (data->parse.map[0][j] != '1' && ft_isspace(data->parse.map[0][j]) == 0)
            return (return_error_exit(data));
        j++;
	}
	j = 0;
	while (data->parse.map[data->parse.map_h - 1][j] != '\0')
	{
		if ((data->parse.map[data->parse.map_h - 1][j] != '1') &&
			ft_isspace(data->parse.map[data->parse.map_h - 1][j]) == 0)
			return (return_error_exit(data));
		j++;
	}
	return (1);
}
