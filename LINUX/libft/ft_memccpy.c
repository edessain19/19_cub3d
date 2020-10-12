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

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n != 0)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		if (*(unsigned char*)src == (unsigned char)c)
		{	
			*(unsigned char*)dst++ = *(unsigned char*)src++;
			return (dst);
		}
		n--;
	}
	return (NULL);
}
