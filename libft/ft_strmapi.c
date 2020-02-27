/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:30:27 by edessain          #+#    #+#             */
/*   Updated: 2019/10/28 10:58:10 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	char	*str;

	counter = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[counter])
		++counter;
	if (!(str = (char*)malloc(counter + 1 * sizeof(char))))
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		str[counter] = f(counter, s[counter]);
		++counter;
	}
	str[counter] = '\0';
	return (str);
}
