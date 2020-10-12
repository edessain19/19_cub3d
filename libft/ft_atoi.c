/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 08:58:14 by edessain          #+#    #+#             */
/*   Updated: 2020/02/12 16:19:30 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					a;
	int					plusmoins;
	unsigned long int	rep;

	a = 0;
	rep = 0;
	plusmoins = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			plusmoins *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		rep = rep * 10 + str[a] - 48;
		a++;
	}
	if (rep > 2147483648)
		return ((plusmoins == -1) ? 0 : -1);
	return (rep * plusmoins);
}
