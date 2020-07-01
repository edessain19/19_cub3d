/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sprt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:14:21 by evrard            #+#    #+#             */
/*   Updated: 2020/06/30 18:39:30 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		malloc_size_sprite(t_data *data)
{
	if (!(data->spr.sprites_x = malloc(sizeof(int *) * data->spr.numsprites + 1)))
	{
		write(1, "Error\n", 6);
		write(1, "Can't malloc the sprite", 23);
		exit_all(data);
		return (-1);
	}
	if (!(data->spr.sprites_y = malloc(sizeof(int *) * data->spr.numsprites + 1)))
	{
		write(1, "Error\n", 6);
		write(1, "Can't malloc the sprite", 23);
		exit_all(data);
		return (-1);
	}
	return (1);
}

void	parse_sprites(t_data *data)
{
	int		i;
	int		j;
	float	k;

	i = 0;
	j = 0;
	k = 0;
	while (data->parse.map[(int)i] != NULL)
	{
		j = 0;
		while (data->parse.map[(int)i][(int)j] != '\0')
		{
			if (data->parse.map[(int)i][(int)j] == '2')
			{
				data->spr.sprites_x[(int)k] = j + 0.5;
				data->spr.sprites_y[(int)k] = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}

int		get_sprites(t_data *data)
{
	if (malloc_size_sprite(data) < 0)
		return (-1);
	parse_sprites(data);
	return (1);
}
