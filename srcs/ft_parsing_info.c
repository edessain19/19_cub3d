/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:26:23 by edessain          #+#    #+#             */
/*   Updated: 2020/03/10 14:44:54 by edessain         ###   ########.fr       */
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

char	*ft_get_texture(char *str, int i, t_data *data)
{
	if (!(data->info.no = malloc(ft_strlen_parsing(str, i) + 1)))
		return (NULL);
	while (str[i] == '\n')
		

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
			ft_get_texture(str, i, data);







	}

}
