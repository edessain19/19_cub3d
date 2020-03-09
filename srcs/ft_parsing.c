/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:38:04 by edessain          #+#    #+#             */
/*   Updated: 2020/03/09 15:31:23 by edessain         ###   ########.fr       */
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
		{
			data->parse.info = ft_strjoin(data->parse.info, line);
			data->parse.info = ft_strjoin(data->parse.info, "\n");
			free(line);
			line = NULL;
			i++;
		}
	}
	printf("\n%s\n", data->parse.info);
	return (1);
}

int		parse_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = "";
	while (line[0] == 0)
		get_next_line(fd, &line);
	while (get_next_line(fd, &line))
	{
		data->parse.map = ft_strjoin(data->parse.map, line);
		data->parse.map = ft_strjoin(data->parse.map, "\n");
		free(line);
		line = NULL;
	}
	printf("\n%s\n", data->parse.map);
	return (1);
}

int ft_parse_cub(t_data *data, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (parse_data(fd, data) < 0)
		return (-1);
	if (parse_map(fd, data) < 0)
		return (-1);
	return (0);

}
