#include "../include/cub3d.h"

int		ft_size_map(t_data *data, char *str)
{
	int		i;
	int		j;
	int		counter;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] != '\n')
		{
			i++;
			j++;
		}
		if (j >= size)
			size = j;
		j = 0;
		while (str[i] == '\n')
			counter++;
		i++;
	}
	return (size);
}

int		ft_parsing_map(t_data *data)
{
	ft_size_map(data, data->parse.map_str);
	if (!(data->parse.map = ft_split(data->parse.map_str, '\n')))
		return (-1);
	
	
	return (0);
}
