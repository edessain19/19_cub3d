/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:38:04 by edessain          #+#    #+#             */
/*   Updated: 2020/03/06 14:52:56 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		parse_data(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) && i < 7)
	{
		if (line[0] == '\0')
			get_next_line(fd, &line);
		if (ft_isdigit(line[0]) == 0)
			data->parse.info = ft_strjoin(data->parse.info, line);
	}
	printf("\n%s\n", data->parse.info);








	return (1);
}
