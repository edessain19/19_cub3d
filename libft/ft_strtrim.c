/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:28:57 by edessain          #+#    #+#             */
/*   Updated: 2019/10/28 11:55:49 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_test(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_reduce1(char const *c, char const *set)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (ft_test(c[i], set) == 1)
			i++;
		else
			return (i);
	}
	return (i);
}

static int		ft_reduce2(char const *c, char const *set)
{
	int i;

	i = ft_strlen((char*)c) - 1;
	while (i > 0 && ft_test(c[i], set) == 1)
		i--;
	return (i);
}

static char		*ft_null(void)
{
	char	*str;

	str = malloc(1 * sizeof(str));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		debut;
	int		fin;
	int		size;
	char	*dest;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	debut = ft_reduce1(s1, set);
	fin = ft_strlen((char*)s1) - ft_reduce2(s1, set);
	size = ft_strlen((char*)s1) - debut - fin;
	if (size < 1)
		return (ft_null());
	if (!(dest = malloc((size + 2) * sizeof(*dest))))
		return (NULL);
	while (size >= 0)
	{
		dest[i] = s1[debut];
		i++;
		debut++;
		size--;
	}
	dest[i] = '\0';
	return (dest);
}
