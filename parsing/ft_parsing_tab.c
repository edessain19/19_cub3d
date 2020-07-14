/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 09:03:04 by evrard            #+#    #+#             */
/*   Updated: 2020/07/03 10:02:15 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char     *ft_remove_tab(t_data *data, int i, int j)
{
    char    *tmp;
    char    **tmp_line;
    char    *new_line;

    j = 0;
    if (!(tmp = malloc(sizeof(char) * 4)))
        return (NULL);
    while (j < 4)
    {
        tmp[j] = ' ';
        j++;
    }
    tmp[j] = 0;
    tmp_line = ft_split(data->parse.map[i], 9);
    new_line = ft_strjoin_2(ft_strjoin_2(tmp_line[0], tmp), tmp_line[1]);
    //free(tmp_line[0]);
    //free(tmp_line[1]);
    return (new_line);
}
