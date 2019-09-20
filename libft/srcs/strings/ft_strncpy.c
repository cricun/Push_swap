/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:07:38 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/24 19:05:01 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*a;

	a = dst;
	while (len--)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = 0;
	}
	return (a);
}
