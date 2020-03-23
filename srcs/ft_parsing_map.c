#include "../include/cub3d.h"

void	ft_size_map(t_data *data, char *str)
{
	int		i;
	int		j;
	int		size_h;
	int		size_w;

	i = 0;
	j = 0;
	size_w = 0;
	size_h = 0;
	while (str[i] != 0)
	{
		while (str[i] && str[i] != '\n')
		{
			i++;
			j++;
		}
		if (j >= size_w)
			size_w = j;
		j = 0;
		if (str[i] == '\n')
			size_h++;
		i++;
	}
	data->info.map_h = size_h;
	data->info.map_w = size_w;
}

int		ft_get_position2(int i, int j, t_data *data)
{
	if (ft_isalpha(data->parse.map[i][j]))
	{
		data->rec.posX = j + 0.5;
		data->rec.posY = i + 0.5;
		if (data->parse.dir == 0)
			data->parse.dir = data->parse.map[i][j];
		data->parse.map[i][j] = '0';
	}
	if (data->parse.map[i][j] == '2')
		data->parse.nb_sprites += 1;
	return (1);
}

int ft_get_position(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->parse.map[i] != NULL)
	{
		j = 0;
		while(data->parse.map[i][j] != 0)
		{
			ft_get_position2(i, j, data);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_parsing_map(t_data *data)
{
	ft_size_map(data, data->parse.map_str);
	if (!(data->parse.map = ft_split(data->parse.map_str, '\n')))
		return (-1);
	if (ft_get_position(data) < 0)
		return (-1);
	return (0);
}
