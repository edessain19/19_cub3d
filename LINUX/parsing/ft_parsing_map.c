/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:21:45 by evrard            #+#    #+#             */
/*   Updated: 2020/09/02 16:21:49 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*create_line(char *str, int diff)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = malloc(sizeof(char *) * (ft_strlen(str) + diff + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			str[i] = '1';
		new[i] = str[i];
		i++;
	}
	while (diff > 0)
	{
		new[i] = '1';
		i++;
		diff--;
	}
	new[i] = '\0';
	return (new);
}

int		ft_size_map(t_data *data, int i)
{
	size_t	len;
	int		diff;

	diff = 0;
	len = ft_strlen(data->parse.map[i]);
	while (data->parse.map[i] != NULL)
	{
		if (ft_strlen(data->parse.map[i]) > len)
			len = ft_strlen(data->parse.map[i]);
		i++;
	}
	data->parse.map_h = i;
	data->parse.map_w = len;
	i = 0;
	while (data->parse.map[i] != NULL)
	{
		if (ft_strlen(data->parse.map[i]) < len)
		{
			diff = len - ft_strlen(data->parse.map[i]);
			if (!(data->parse.map[i] = create_line(data->parse.map[i], diff)))
				return (-1);
		}
		i++;
	}
	return (1);
}

int		ft_get_position2(int i, int j, t_data *data)
{
	if (ft_isalpha(data->parse.map[i][j]) == 1 && data->parse.dir != 0)
		return (error_pos_init(data));
	if (ft_isalpha(data->parse.map[i][j]) == 1)
	{
		data->rec.posx = j;
		data->rec.posy = i;
		data->parse.dir = data->parse.map[i][j];
		data->parse.map[i][j] = '0';
		if (check_pos_init(data) < 0)
			return (-1);
	}
	if (data->parse.map[i][j] == '2')
	{
		data->spr.nbsprites += 1;
	}
	if (data->parse.map[i][j] == 9)
	{
		ft_remove_tab(data, i, j);
	}
	return (1);
}

int		ft_get_position(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->parse.map[i] != NULL)
	{
		j = 0;
		while (data->parse.map[i][j] != 0)
		{
			if (ft_get_position2(i, j, data) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

/*
**void 	ft_print_map(t_data *data)
**{
**	int i;
**
**	i = 0;
**	while (data->parse.map[i] != NULL)
**	{
**		printf("%s\n", data->parse.map[i]);
**		i++;
**	}
**}
*/

int		ft_parsing_map(t_data *data)
{
	if (!(data->parse.map = ft_split(data->parse.map_str, '\n')))
		return (-1);
	if (ft_get_position(data) < 0)
		return (-1);
	if (ft_size_map(data, 0) < 0)
		return (-1);
	if (ft_get_sprt(data) < 0)
		return (-1);
	return (0);
}
