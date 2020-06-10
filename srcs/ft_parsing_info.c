/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:26:23 by edessain          #+#    #+#             */
/*   Updated: 2020/06/10 14:45:30 by evrard           ###   ########.fr       */
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
	int 	h;
	int 	w;
	char	*tab;

	h = 0;
	w = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	if (!(tab = malloc(ft_strlen_parsing(str, i, '\n') + 1)))
		return (-1);
	while (str[i] != '\n')
		tab[j++] = str[i++];
	tab[j] = 0;
	if (c == 'n')
//		data->info.no = mlx_xpm_file_to_image(data->mlx.mlx_ptr, tab, &h, &w);
		data->parse.n_path = ft_strdup(tab);
	if (c == 's')
		data->parse.s_path = ft_strdup(tab);
		//data->info.so = mlx_xpm_file_to_image(data->mlx.mlx_ptr, tab, &h, &w);;
	if (c == 'e')
		data->parse.e_path = ft_strdup(tab);
		//data->info.ea = mlx_xpm_file_to_image(data->mlx.mlx_ptr, tab, &h, &w);
	if (c == 'w')
		data->parse.w_path = ft_strdup(tab);
		//data->info.we = mlx_xpm_file_to_image(data->mlx.mlx_ptr, tab, &h, &w);
	if (c == 'S')
		data->parse.sp_path = ft_strdup(tab);
	if (tab == NULL)
		return (-1);
	free(tab);
	return (0);
}

int		ft_get_size(char *str, int i, t_data *data, char c)
{
	int		j;
	int 	c1;
	int 	f1;

	j = 0;
	c1 = 0;
	f1 = 0;
	if (c == 'r')
	{
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]) == 1)
		{
			data->parse.r1 = data->parse.r1 * 10 + str[i] - 48;
			i++;
		}
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]) == 1)
		{
			data->parse.r2 = data->parse.r2 * 10 + str[i] - 48;
			i++;
		}
	}
	if (c == 'f')
	{
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]) == 1)
		{
			f1 = f1 * 10 + str[i] - 48;
			i++;
		}
		data->parse.f = 65536 * f1;
		f1 = 0;
		i++;
		while (ft_isdigit(str[i]) == 1)
		{
			f1 = f1 * 10 + str[i] - 48;
			i++;
		}
		data->parse.f = data->parse.f + 256 * f1;
		f1 = 0;
		i++;
		while (ft_isdigit(str[i]) == 1)
		{
			f1 = f1 * 10 + str[i] - 48;
			i++;
		}
		data->parse.f = data->parse.f + f1;
	}

	if (c == 'c')
	{
		while (str[i] == ' ')
			i++;
		while (ft_isdigit(str[i]) == 1)
		{
			c1 = c1 * 10 + str[i] - 48;
			i++;
		}
		data->parse.c = 65536 * c1;
		c1 = 0;
		i++;
		while (ft_isdigit(str[i]) == 1)
		{
			c1 = c1 * 10 + str[i] - 48;
			i++;
		}
		data->parse.c = data->parse.c + 256 * c1;
		c1 = 0;
		i++;
		while (ft_isdigit(str[i]) == 1)
		{
			c1 = c1 * 10 + str[i] - 48;
			i++;
		}
		data->parse.c = data->parse.c + c1;
	}
	return (0);
}

int		ft_parsing_lettre(char *str, int i, t_data *data, char c)
{
	if (c == 'n' || c == 's' || c == 'e' || c == 'w' || c == 'S')
		ft_get_texture(str, i + 2, data, c);
	else if (c == 'r' || c == 'f' || c == 'c')
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
		else if (str[i] == 'S')
			i = ft_parsing_lettre(str, i, data, 'S');
		else if (str[i] == 'F')
			i = ft_parsing_lettre(str, i, data, 'f');
		else if (str[i] == 'C')
			i = ft_parsing_lettre(str, i, data, 'c');
		else
			i++;
	}
	//printf(" %i\n %i\n %d\n %d\n %d\n %d\n %i\n %i\n", data->info.r1, data->info.r2, data->info.no, data->info.so, data->info.we, data->info.ea, data->info.f, data->info.c);
	return (0);
}
