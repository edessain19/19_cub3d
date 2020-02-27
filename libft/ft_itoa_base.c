/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 09:13:15 by edessain          #+#    #+#             */
/*   Updated: 2020/02/18 09:49:43 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizebase(unsigned long long nbr, int b_size)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / b_size;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long long n, char *base, int b_size)
{
	char	*str;
	int		size;

	size = ft_sizebase(n, b_size);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (--size >= 0)
	{
		str[size] = base[n % b_size];
		n = n / b_size;
	}
	return (str);
}
