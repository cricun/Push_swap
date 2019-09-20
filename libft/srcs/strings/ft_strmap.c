/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:18:57 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/30 15:15:08 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	a;

	a = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (a < i)
	{
		if (f)
			*(str + a) = f(*(s + a));
		a++;
	}
	*(str + a) = 0;
	return (str);
}
