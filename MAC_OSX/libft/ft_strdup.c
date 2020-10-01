/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:40:55 by edessain          #+#    #+#             */
/*   Updated: 2020/02/17 10:07:38 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*src;

	i = 0;
	if (str == NULL)
		return (NULL);
	src = malloc((ft_strlen(str) + 1) * sizeof(*src));
	if (src == 0)
		return (0);
	while (str[i] != '\0')
	{
		src[i] = str[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
