/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:12:01 by edessain          #+#    #+#             */
/*   Updated: 2019/10/28 10:19:50 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *a, const void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)a)[i] = ((unsigned char*)b)[i];
		if (((unsigned char*)b)[i] == (unsigned char)c)
			return (&a[i] + 1);
		i++;
	}
	return (NULL);
}
