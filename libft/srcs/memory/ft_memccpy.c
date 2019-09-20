/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:30:06 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/21 20:53:31 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
		if (*((unsigned char*)(src + i)) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	if (i == n)
		return (NULL);
	return (dst);
}
