/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:19:12 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/23 18:38:35 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tmp;
	char *tmpn;

	tmpn = (char*)needle;
	if (*needle == 0)
		return ((char*)haystack);
	while (*haystack)
	{
		tmp = (char*)haystack;
		while (*haystack == *needle)
		{
			haystack++;
			needle++;
			if (*needle == 0)
				return (tmp);
		}
		needle = tmpn;
		haystack = tmp;
		haystack++;
	}
	return (NULL);
}
