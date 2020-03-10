/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:38:04 by edessain          #+#    #+#             */
/*   Updated: 2020/03/10 13:18:04 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		parse_data(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	data->parse.info = "";
	while (get_next_line(fd, &line) && i < 7)
	{
		if (line[0] == '\0')
			get_next_line(fd, &line);
		if (ft_isdigit(line[0]) == 0)
		{
			data->parse.info = ft_strjoin_2(data->parse.info, line);
			data->parse.info = ft_strjoin_2(data->parse.info, "\n");
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
	data->parse.map = ft_strjoin_2(data->parse.map, line);
	data->parse.map = ft_strjoin_2(data->parse.map, "\n");
	while (get_next_line(fd, &line))
	{
		data->parse.map = ft_strjoin(data->parse.map, line);
		data->parse.map = ft_strjoin(data->parse.map, "\n");
		free(line);
		line = NULL;
	}
	data->parse.info = ft_strjoin_2(data->parse.info, line);
	data->parse.info = ft_strjoin_2(data->parse.info, "\0");
	printf("\n%s\n", data->parse.map);
	return (1);
}

int ft_parse_cub(t_data *data, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
//	write(1, "1", 1);
	if (parse_data(fd, data) < 0)
		return (-1);
//	write(1, "2", 1);
	if (parse_map(fd, data) < 0)
		return (-1);
//	write(1, "3", 1);
	close(fd);
	return (0);

}
