/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:27:04 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/22 22:06:36 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (*(dst + i) && i < size)
		i++;
	if (*(dst + i))
		return (size + ft_strlen(src));
	else
	{
		while (i + 1 < size && *src)
		{
			*(dst + i) = *src++;
			i++;
		}
		*(dst + i) = 0;
		return (i + ft_strlen(src));
	}
}
