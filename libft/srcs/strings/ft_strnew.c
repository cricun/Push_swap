/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:00:54 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/25 21:26:08 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tmp;
	char *tmps;

	if (!(tmp = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tmps = tmp;
	while (1)
	{
		*tmp++ = 0;
		if (size-- == 0)
			break ;
	}
	return (tmps);
}
