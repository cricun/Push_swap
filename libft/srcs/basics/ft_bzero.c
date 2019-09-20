/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:23:54 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/14 22:20:18 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	size_t	max;
	size_t	*str;

	str = (size_t*)s;
	max = n / sizeof(size_t);
	i = 0;
	while (max)
	{
		*str++ = 0;
		--max;
	}
	max = n % sizeof(size_t);
	while (max)
		*((char*)str + --max) = 0;
}
