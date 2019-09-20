/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:29:23 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/23 23:38:18 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *a;

	if (!*s && c != 0)
		return (NULL);
	a = (NULL);
	while (*s || !c)
	{
		if (*s == (char)c)
			a = (char*)(s);
		if (!*s)
			break ;
		s++;
	}
	return (a);
}
