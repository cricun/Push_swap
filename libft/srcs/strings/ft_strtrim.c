/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:25:01 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/30 14:23:23 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sp(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	end = 0;
	while (is_sp(s[i]) == 1)
		i++;
	start = s[i] == 0 ? 0 : i;
	while (s[i])
	{
		if (is_sp(s[i]) == 0 && (is_sp(s[i + 1]) == 1 || s[i + 1] == 0))
			end = i;
		i++;
	}
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (start <= end && end)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
