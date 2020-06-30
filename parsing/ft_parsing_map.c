#include "../include/cub3d.h"

char	*create_new_line(char *str, int diff)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = malloc(sizeof(char *) * (ft_strlen(str) + diff + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			str[i] = '1';
		new[i] = str[i];
		i++;
	}
	while (diff > 0)
	{
		new[i] = '1';
		i++;
		diff--;
	}
	new[i] = '\0';
	return (new);
}

int		ft_size_map(t_data *data)
{
	int i;
	size_t len;
	int diff;

	i = 0;
	diff = 0;
	len = ft_strlen(data->parse.map[i]);
	while (data->parse.map[i] != NULL)
	{
		if (ft_strlen(data->parse.map[i]) > len)
			len = ft_strlen(data->parse.map[i]);
		i++;
	}
	data->parse.map_h = i;
	data->parse.map_w = len;
	i = 0;
	while (data->parse.map[i] != NULL)
	{
		if (ft_strlen(data->parse.map[i]) < len)
		{
			diff = len - ft_strlen(data->parse.map[i]);
			if (!(data->parse.map[i] = create_new_line(data->parse.map[i], diff)))
				return (-1);
		}
		i++;
	}
	return (1);
}

int		ft_get_position2(int i, int j, t_data *data)
{
	if (ft_isalpha(data->parse.map[i][j]) == 1)
	{
		data->parse.pos_init_x = j + 0.5;
		data->parse.pos_init_y = i + 0.5;
		printf("%f\n%f\n", data->parse.pos_init_x, data->parse.pos_init_y);
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

void	ft_fill_the_blank(t_data *data)
{
	int		i;

	i = 0;
	while (data->parse.map_str[i] != 0)
		{
			if (data->parse.map_str[i] == ' ')
				data->parse.map_str[i] = '9';
			i++;
		}
}

int		ft_parsing_map(t_data *data)
{

//	ft_fill_the_blank(data);
	if (!(data->parse.map = ft_split(data->parse.map_str, '\n')))
		return (-1);
	ft_size_map(data);
	if (ft_get_position(data) < 0)
		return (-1);
//	init_dir(data);
	return (0);
}
