/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:38:04 by edessain          #+#    #+#             */
/*   Updated: 2020/03/11 13:52:33 by edessain         ###   ########.fr       */
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
	data->parse.info = ft_strjoin_2(data->parse.info, "\0");
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
	data->parse.map_str = ft_strjoin_2(data->parse.map_str, line);
	data->parse.map_str = ft_strjoin_2(data->parse.map_str, "\n");
	while (get_next_line(fd, &line))
	{
		data->parse.map_str = ft_strjoin(data->parse.map_str, line);
		data->parse.map_str = ft_strjoin(data->parse.map_str, "\n");
//		free(line);
//		line = NULL;
	}
	data->parse.map_str = ft_strjoin_2(data->parse.map_str, line);
	data->parse.map_str = ft_strjoin_2(data->parse.map_str, "\0");
	free(line);
	line = NULL;
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
	close(fd);
	ft_parsing_info(data);
	return (0);

}