/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:11:25 by evrard            #+#    #+#             */
/*   Updated: 2020/09/02 09:35:40 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	creat_header(int fd, t_data *data, int file_size)
{
	char header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	header[2] = (unsigned char)(file_size);
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(data->parse.screen_x);
	header[19] = (unsigned char)(data->parse.screen_x >> 8);
	header[20] = (unsigned char)(data->parse.screen_x >> 16);
	header[21] = (unsigned char)(data->parse.screen_x >> 24);
	header[22] = (unsigned char)(data->parse.screen_y);
	header[23] = (unsigned char)(data->parse.screen_y >> 8);
	header[24] = (unsigned char)(data->parse.screen_y >> 16);
	header[25] = (unsigned char)(data->parse.screen_y >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

int		ft_bmp(t_data *data)
{
	int		fd;
	int		file_size;

	fd = open("./screenshot.bmp", O_WRONLY | O_CREAT
		| O_TRUNC | O_APPEND, S_IRWXU);
	if (fd < 0)
	{
		write(1, "Error\nThe screenshot has failed!\n", 33);
		return (exit_all(data));
	}
	file_size = 54 + (data->parse.screen_x * data->parse.screen_y) * 4;
	creat_header(fd, data, file_size);
	write(fd, (char *)data->dis.addr,
		(data->parse.screen_x * data->parse.screen_y * 4));
	close(fd);
	exit_all(data);
	return (0);
}
