/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:40:37 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/23 19:21:49 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t b;
	size_t c;

	i = 0;
	b = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		c = i;
		while (haystack[i] == needle[b] && i < len)
		{
			i++;
			b++;
			if (needle[b] == 0)
				return ((char*)(haystack + c));
		}
		i = c;
		b = 0;
		i++;
	}
	return (0);
}
