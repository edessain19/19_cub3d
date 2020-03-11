/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:26:23 by edessain          #+#    #+#             */
/*   Updated: 2020/03/11 12:56:16 by edessain         ###   ########.fr       */
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

int		ft_get_texture(char *str, int i, t_data *data, char c)
{
	int		j;
	char	*tab;
	
	j = 0;
	while (str[i] == ' ')
		i++;
	if (!(tab = malloc(ft_strlen_parsing(str, i) + 1)))
		return (-1);
	while (str[i] == '\n')
	{
		tab[j++] = str[i++];
		printf("%s\n", tab);
	}
	if (c == 'n')
		data->info.no = ft_strdup(tab);
	if (c == 's')
		data->info.so = ft_strdup(tab);
	if (c == 'e')
		data->info.ea = ft_strdup(tab);
	if (c == 'w')
		data->info.we = ft_strdup(tab);
	return (0);
}

void	ft_parsing_info(t_data *data)
{
	char	*str;
	int		i;
	
	str = data->parse.info;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' && str[i + 1] == 'O')
			ft_get_texture(str, i + 3, data, 'n');
		if (str[i] == 'S' && str[i + 1] == 'O')
			ft_get_texture(str, i + 3, data, 's');
		if (str[i] == 'W' && str[i = 1] == 'E')
			ft_get_texture(str, i + 3, data, 'w');
		if (str[i] == 'E' && str[i + 1] == 'A')
			ft_get_texture(str, i + 3, data, 'e');
	}

}
