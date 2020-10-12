/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 09:03:04 by edessain          #+#    #+#             */
/*   Updated: 2020/10/12 17:36:04 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_pass_space(char *str, int i)
{
	int		check;

	check = 0;
	while (str[i] == ',' || str[i] == ' ')
	{
		if (str[i] == ',')
		{
			check++;
		}
		i++;
	}
	if (check == 1)
		return (i);
	else
		return (-1);
}

char	*ft_remove_tab(t_data *data, int i, int j)
{
	char	*tmp;
	char	**tmp_line;
	char	*new_line;

	j = 0;
	if (!(tmp = malloc(sizeof(char) * 4)))
		return (NULL);
	while (j < 4)
	{
		tmp[j] = ' ';
		j++;
	}
	tmp[j] = 0;
	tmp_line = ft_split(data->parse.map[i], 9);
	new_line = ft_strjoin_2(ft_strjoin_2(tmp_line[0], tmp), tmp_line[1]);
	if (tmp_line[0] != NULL)
		free(tmp_line[0]);
	if (tmp_line[1] != NULL)
		free(tmp_line[1]);
	return (new_line);
}
