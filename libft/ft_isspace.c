/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 09:43:41 by evrard            #+#    #+#             */
/*   Updated: 2020/06/09 09:48:13 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == 'r')
		return (1);
	else
		return (0);
}