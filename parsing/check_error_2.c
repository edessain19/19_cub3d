/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:35:39 by edessain          #+#    #+#             */
/*   Updated: 2020/10/16 19:06:37 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		error_pos_init(t_data *data)
{
	write(1, "Error\n", 6);
	write(1, "There is an error in the initial position\n", 42);
	return (exit_all(data));
}

int		check_pos_init(t_data *data)
{
	if (data->parse.dir != 'N' && data->parse.dir != 'S' &&
			data->parse.dir != 'W' && data->parse.dir != 'E')
		return (error_pos_init(data));
	if (data->parse.map[(int)data->rec.posy][(int)data->rec.posx + 1] == ' ' ||
		data->parse.map[(int)data->rec.posy][(int)data->rec.posx - 1] == ' ' ||
		data->parse.map[(int)data->rec.posy + 1][(int)data->rec.posx] == ' ' ||
		data->parse.map[(int)data->rec.posy - 1][(int)data->rec.posx] == ' ')
		return (error_pos_init(data));
	return (0);
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
		if (data->parse.map[i][0] != '1'
			&& ft_isspace(data->parse.map[i][0]) == 0)
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
		if (data->parse.map[0][j] != '1'
			&& ft_isspace(data->parse.map[0][j]) == 0)
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
