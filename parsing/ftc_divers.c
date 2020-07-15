/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftc_divers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 09:35:00 by evrard            #+#    #+#             */
/*   Updated: 2020/07/15 10:56:18 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strjoin_map(char const *s1, char const *s2, int i, int j)
{
    int     k;
	char	*dest;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char*)s2);
	if (!(dest = malloc((ft_strlen((char*)s1) +
						ft_strlen((char*)s2)) * sizeof(char*))))
		return (NULL);
    k = 0;
	while (s1[i])
	{
        if (ft_isspace(s1[i]) != 1)
            dest[k++] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[k + j] = s2[j];
		j++;
	}
	dest[k + j] = '\0';
	return (dest);
}
