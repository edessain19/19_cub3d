/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:26:23 by edessain          #+#    #+#             */
/*   Updated: 2020/09/02 16:16:09 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_get_rgb(int i, int j, int k)
{
	if (i > 255 || i < 0 || j > 255 || j < 0 || k > 255 || k < 0)
	{
		write(1, "Error\nThe color is wrong\n", 25);
		return (-1);
	}
	return (65536 * i + 256 * j + k);
}

int		ft_strlen_parsing(char *str, int i, char c)
{
	int		count;

	count = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

int		ft_parsing_lettre(char *str, int i, t_data *data, char c)
{
	if (c == 'n' || c == 's' || c == 'e' || c == 'w' || c == 'S')
		if (ft_get_texture(str, i + 2, data, c) == -1)
			return (-1);
	if (c == 'r')
		ft_get_size(str, i + 1, data);
	if (c == 'f')
		ft_get_floor(str, i + 1, data);
	if (c == 'c')
		ft_get_ceiling(str, i + 1, data);
	return (i + 1);
}

void	ft_check_letters(t_data *data, char c)
{
	if (c == 'n')
		data->check.v_path_n++;
	if (c == 's')
		data->check.v_path_s++;
	if (c == 'e')
		data->check.v_path_e++;
	if (c == 'w')
		data->check.v_path_w++;
	if (c == 'S')
		data->check.v_path_sp++;
}

int		ft_parsing_info(t_data *data, int i)
{
	while (data->parse.info[++i])
	{
		if (data->parse.info[i] == 'R')
			i = ft_parsing_lettre(data->parse.info, i, data, 'r');
		else if (data->parse.info[i] == 'N' && data->parse.info[i + 1] == 'O')
			i = ft_parsing_lettre(data->parse.info, i, data, 'n');
		else if (data->parse.info[i] == 'S' && data->parse.info[i + 1] == 'O')
			i = ft_parsing_lettre(data->parse.info, i, data, 's');
		else if (data->parse.info[i] == 'W' && data->parse.info[i + 1] == 'E')
			i = ft_parsing_lettre(data->parse.info, i, data, 'w');
		else if (data->parse.info[i] == 'E' && data->parse.info[i + 1] == 'A')
			i = ft_parsing_lettre(data->parse.info, i, data, 'e');
		else if (data->parse.info[i] == 'S' && data->parse.info[i + 1] == ' ')
			i = ft_parsing_lettre(data->parse.info, i, data, 'S');
		else if (data->parse.info[i] == 'F')
			i = ft_parsing_lettre(data->parse.info, i, data, 'f');
		else if (data->parse.info[i] == 'C')
			i = ft_parsing_lettre(data->parse.info, i, data, 'c');
		if (i == 0)
			return (-1);
	}
	data->parse.c = ft_get_rgb(data->parse.c1, data->parse.c2, data->parse.c3);
	data->parse.f = ft_get_rgb(data->parse.f1, data->parse.f2, data->parse.f3);
	return (0);
}
