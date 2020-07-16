/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 08:49:19 by evrard            #+#    #+#             */
/*   Updated: 2020/07/16 15:22:41 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		return_error_exit(t_data *data)
{
	write(1, "Error\n", 6);
	write(1, "Map not surrounded by 1\n", 24);
	printf("\n%s\n", data->parse.map_str);
	exit_all(data);
	return (-1);
}

int		check_map_characters(t_data *data)
{
	int i;

	i = 0;
	while (data->parse.map_str[i] != 0)
	{
		if (data->parse.map_str[i] != '1' &&
			data->parse.map_str[i] != '2' &&
			data->parse.map_str[i] != '0' &&
			data->parse.map_str[i] != 'N' &&
			data->parse.map_str[i] != 'S' &&
			data->parse.map_str[i] != 'E' &&
			data->parse.map_str[i] != 'W' &&
			data->parse.map_str[i] != ' ' &&
			ft_isspace(data->parse.map_str[i]) != 1)
		{
			write(1, "Error\n", 6);
			write(1, "Wrong caractere in the map\n", 27);
			return (exit_all(data));
		}
		i++;
	}
	return (1);
}

int		check_around(int i, int j, t_data *data)
{
    if (data->parse.map[i - 1][j - 1] == ' ')
		return (-1);
    if (data->parse.map[i - 1][j + 1] == ' ')
		return (-1);
	if (data->parse.map[i + 1][j + 1] == ' ')
		return (-1);
	if (data->parse.map[i + 1][j - 1] == ' ')
		return (-1);
	if (data->parse.map[i][j - 1] == ' ')
		return (-1);
	if (data->parse.map[i][j + 1] == ' ')
		return (-1);
	if (data->parse.map[i - 1][j] == ' ')
		return (-1);
	if (data->parse.map[i + 1][j] == ' ')
		return (-1);
	return (1);
}

int     check_walls(t_data *data)
{
    int     i;
    int     j;
    int k;

    k = 0;
    i = 0;
    j = 0;
    while (i < data->parse.map_h)
    {
        j = 0;
        while (data->parse.map[i][j] != 0)
        {
            if (data->parse.map[i][j] == '0' && (check_around(i, j, data) == -1))
            {
                printf("/n/n hello /n/n");
                k = check_around(i,j,data);
                printf("%i", k);
                return (return_error_exit(data));
            }
            if (data->parse.map[i][j] == '2' && (check_around(i, j, data) == -1))
                return (return_error_exit(data));
            j++;
        }
        i++;
    }
    return (1);
}

int     check_errors(t_data *data)
{
    if (check_walls(data) < 0)
        return (-1);
    if (check_map_characters(data) < 0)
        return (-1);
	if (check_pos_init(data) < 0)
		return (-1);
	if (check_borders_columns(data) < 0)
		return (-1);
	if (check_borders_lines(data) < 0)
		return (-1);
	if (check_textures(data) < 0)
		return (-1);
	if (check_others(data) < 0)
		return (-1);
    return (1);
}
