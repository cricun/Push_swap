/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:55:37 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/24 18:21:13 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (!(tmp = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	return (void*)tmp;
}
