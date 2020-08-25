/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_info_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:19:55 by evrard            #+#    #+#             */
/*   Updated: 2020/08/25 10:09:45 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_get_size(char *str, int i, t_data *data)
{
	data->check.v_r++;
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
	if (data->parse.r1 >= 1920)
	 	data->parse.r1 = 1920;
	if (data->parse.r2 >= 1080)
		data->parse.r2 = 1080;
}

void        ft_get_floor(char *str, int i, t_data *data)
{
	data->check.v_f++;
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		data->parse.f1 = data->parse.f1 * 10 + str[i] - 48;
		i++;
	}
    if (str[i] != ',')
        data->parse.f1 = -1;
    i++;
	while (ft_isdigit(str[i]) == 1)
	{
		data->parse.f2 = data->parse.f2 * 10 + str[i] - 48;
		i++;
	}
    if (str[i] != ',')
        data->parse.f2 = -1;
    i++;
    while (ft_isdigit(str[i]) == 1)
	{
		data->parse.f3 = data->parse.f3 * 10 + str[i] - 48;
		i++;
	}
    if (str[i] != '\n')
        data->parse.f3 = -1;
}

void     ft_get_ceiling(char *str, int i, t_data *data)
{
	data->check.v_c += 1;
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		data->parse.c1 = data->parse.c1 * 10 + str[i] - 48;
		i++;
	}
    if (str[i] != ',')
        data->parse.c1 = -1;
    i++;
	while (ft_isdigit(str[i]) == 1)
	{
		data->parse.c2 = data->parse.c2 * 10 + str[i] - 48;
		i++;
	}
    if (str[i] != ',')
        data->parse.c2 = -1;
    i++;
    while (ft_isdigit(str[i]) == 1)
	{
		data->parse.c3 = data->parse.c3 * 10 + str[i] - 48;
		i++;
	}
    if (str[i] != '\n')
        data->parse.c3 = -1;
//    printf("%i\n%i\n%i\n", data->parse.c1, data->parse.c2, data->parse.c3);
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
    return (ft_get_texture_2(tab, data, c));
}

int		ft_get_texture_2(char *tab, t_data *data, char c)
{
	ft_check_letters(data, c);
	if (c == 'n')
		if (!(data->parse.n_path = ft_strdup(tab)))
			return (exit_all(data));
	if (c == 's')
		if (!(data->parse.s_path = ft_strdup(tab)))
			return (exit_all(data));
	if (c == 'e')
		if (!(data->parse.e_path = ft_strdup(tab)))
			return (exit_all(data));
	if (c == 'w')
		if (!(data->parse.w_path = ft_strdup(tab)))
			return (exit_all(data));
	if (c == 'S')
		if (!(data->parse.sp_path = ft_strdup(tab)))
			return (exit_all(data));
	if (tab == NULL)
		return (-1);
	free(tab);
	return (0);
}
