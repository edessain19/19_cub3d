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

int		ft_get_texture(char *str, int i, t_data *data, char c)
{
	int		j;
	char	*tab;
	
	j = 0;
	while (str[i] == ' ')
		i++;
	if (!(tab = malloc(ft_strlen_parsing(str, i, '\n') + 1)))
		return (-1);
	while (str[i] != '\n')
		tab[j++] = str[i++];
	tab[j] = 0;
	if (c == 'n')
		data->info.no = ft_strdup(tab);
	if (c == 's')
		data->info.so = ft_strdup(tab);
	if (c == 'e')
		data->info.ea = ft_strdup(tab);
	if (c == 'w')
		data->info.we = ft_strdup(tab);

	if (tab == NULL)
		return (-1);
	free(tab);
	return (0);
}

int		ft_get_size(char *str, int i, t_data *data, char c)
{
	int		j;

	j = 0;
	if (c == 'r')
	{
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]) == 1)
		{
			data->info.r1 = data->info.r1 * 10 + str[i] - 48;
			i++;
		}
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]) == 1)
		{
			data->info.r2 = data->info.r2 * 10 + str[i] - 48;
			i++;
		}
	}
	if (c == 'f')
	{
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]) == 1)
		{
			data->info.f1 = data->info.f1 * 10 + str[i] - 48;
			i++;
		}
		i++;
		while (ft_isdigit(str[i]) == 1)
		{
			data->info.f2 = data->info.f2 * 10 + str[i] - 48;
			i++;
		}
		i++;
		while (ft_isdigit(str[i]) == 1)
		{
			data->info.f3 = data->info.f3 * 10 + str[i] - 48;
			i++;
		}
	}
	return (0);
}

int		ft_parsing_lettre(char *str, int i, t_data *data, char c)
{
	if (c == 'n' || c == 's' || c == 'e' || c == 'w' || c == 'S')
		ft_get_texture(str, i + 2, data, c);
	else if (c == 'r' || c == 'f')
		ft_get_size(str, i + 1, data, c);
	return (i + 1);
}

int		ft_parsing_info(t_data *data)
{
	char	*str;
	int		i;
	
	str = data->parse.info;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'R')
			i = ft_parsing_lettre(str, i, data, 'r');
		else if (str[i] == 'N' && str[i + 1] == 'O')
			i = ft_parsing_lettre(str, i, data, 'n');
		else if (str[i] == 'S' && str[i + 1] == 'O')
			i = ft_parsing_lettre(str, i, data, 's');
		else if (str[i] == 'W' && str[i + 1] == 'E')
			i = ft_parsing_lettre(str, i, data, 'w');
		else if (str[i] == 'E' && str[i + 1] == 'A')
			i = ft_parsing_lettre(str, i, data, 'e');
		else if (str[i] == 'S' && str[i + 1] != 'O')
			i = ft_parsing_lettre(str, i, data, 'S');
		else if (str[i] == 'F')
			i = ft_parsing_lettre(str, i, data, 'f');
		else
			i++;
	}
	printf(" %i\n %i\n %s\n %s\n %s\n %s\n %i\n %i\n %i\n", data->info.r1, data->info.r2, data->info.no, data->info.so, data->info.we, data->info.ea, data->info.f1, data->info.f2, data->info.f3);
	return (0);
}