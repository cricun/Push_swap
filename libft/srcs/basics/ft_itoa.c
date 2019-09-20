/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:22:46 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/25 20:40:23 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		nc;
	int		sz;
	char	*str;
	char	*tmp;

	sz = 1;
	nc = n >= 0 ? -1 : 1;
	while (n / nc < -9)
	{
		sz++;
		nc *= 10;
	}
	if (!(str = (char*)malloc(sizeof(char) * (sz + 2))))
		return (NULL);
	tmp = str;
	if (n < 0)
		*str++ = '-';
	while (sz-- > 0)
	{
		*str++ = -(n / nc) + '0';
		n = n % nc;
		nc /= 10;
	}
	*str = 0;
	return (tmp);
}
