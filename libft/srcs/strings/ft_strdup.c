/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:22:09 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/25 20:41:05 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	char	*b;

	if (!(a = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	b = a;
	while (*s1)
		*a++ = *s1++;
	*a = 0;
	return (b);
}
