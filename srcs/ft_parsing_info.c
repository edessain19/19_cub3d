/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:26:23 by edessain          #+#    #+#             */
/*   Updated: 2020/03/11 15:17:09 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_strlen_parsing(char *str, int i)
{
	int		count;

	count = 0;
	while (str[i] != '\n')
	{
		i++;
		count++;
	}
	return (count);
}

int		ft_next_stuff(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'R' || c == 'F' || 
			c == 'C')
		return (1);
	else
		return (0);
}

int		ft_get_texture(char *str, int i, t_data *data, char c)
{
	int		j;
	char	*tab;
	
	j = 0;
	while (str[i] == ' ')
		i++;
	if (!(tab = malloc(ft_strlen_parsing(str, i) + 1)))
		return (-1);
	while (str[i] != '\n')
		tab[j++] = str[i++];
	if (c == 'n')
		data->info.no = ft_strdup(tab);
	if (c == 's')
		data->info.so = ft_strdup(tab);
	if (c == 'e')
		data->info.ea = ft_strdup(tab);
	if (c == 'w')
		data->info.we = ft_strdup(tab);
	printf("%s\n", tab);
	free(tab);
	return (0);
}

int		ft_parsing_info(t_data *data)
{
	char	*str;
	int		i;
	
	str = data->parse.info;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
		{
			ft_get_texture(str, i + 2, data, 'n');
			i++;
		}
		else if (str[i] == 'S' && str[i + 1] == 'O')
		{
			ft_get_texture(str, i + 2, data, 's');
			i++;
		}
		else if (str[i] == 'W' && str[i + 1] == 'E')
		{
			ft_get_texture(str, i + 2, data, 'w');
			i++;
		}
		else if (str[i] == 'E' && str[i + 1] == 'A')
		{
			ft_get_texture(str, i + 2, data, 'e');
			i++;
		}
		i++;

	}
	return (0);
}
