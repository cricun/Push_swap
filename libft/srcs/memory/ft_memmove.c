/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:53:45 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/24 17:19:28 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst > src)
	{
		while (len > 0)
		{
			*(unsigned char*)(dst + len - 1) =
				*((unsigned char*)(src + len - 1));
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *((unsigned char*)(src + i));
			i++;
		}
	}
	return (dst);
}
