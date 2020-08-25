/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:38:04 by edessain          #+#    #+#             */
/*   Updated: 2020/08/25 16:13:38 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int 	ft_check_space(int i, char *str)
{
	int j;

	j = 0;
	while (str[i] == ' ' || str[i] == ',')
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j == 1)
		return (i);
	else
		return (-1);
}

int		parse_data(int fd, t_data *data, int i)
{
	char	*line;

	data->parse.info = "";
	while (get_next_line(fd, &line) && i < 8)
	{
		if (line[0] == 0)
			get_next_line(fd, &line);
		if (!ft_isdigit(line[0]) && line[0] != 0)
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

int		parse_map(int fd, t_data *data, char *line)
{
	while (line[0] == 0)
		get_next_line(fd, &line);
	data->parse.map_str = ft_strjoin_2(data->parse.map_str, line);
	data->parse.map_str = ft_strjoin(data->parse.map_str, "\n");
	while (get_next_line(fd, &line))
	{
		if (line[0] == 0 || data->parse.map_str == NULL)
		{
			write(1, "Error\nError with the parsing of the map\n",40);
			return (exit_all(data));
		}
		data->parse.map_str = ft_strjoin(data->parse.map_str, line);
		data->parse.map_str = ft_strjoin(data->parse.map_str, "\n");
		free(line);
		line = NULL;
	}
	data->parse.map_str = ft_strjoin(data->parse.map_str, line);
	data->parse.map_str = ft_strjoin(data->parse.map_str, "\0");
	free(line);
	line = NULL;
	if (data->parse.map_str == NULL)
		return (exit_all(data));
	return (1);
}

int ft_parse_cub(t_data *data, char *filename)
{
	int		fd;
	int 	i;
	char 	*line;

	i = 0;
	line = "";
	fd = open(filename, O_RDONLY);
	if (parse_data(fd, data, i) < 0)
		return (-1);
	if (parse_map(fd, data, line) < 0)
		return (-1);
	close(fd);
	if (ft_parsing_info(data) < 0)
		return (-1);
	if (check_info(data) < 0)
		return (-1);
	if (ft_parsing_map(data) < 0)
		return (-1);
	init_dir(data);
	if (check_errors(data) < 0)
		return (-1);
	return (0);
}
