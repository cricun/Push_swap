/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:32:18 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/30 18:15:17 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_count(const char **str, char c)
{
	int			i;

	i = 0;
	while (**str != c && **str)
	{
		i++;
		(*str)++;
	}
	while (**str == c && **str)
		(*str)++;
	return (i);
}

static void	ft_free(char ***s, int w)
{
	while (w > 0)
		free((*s)[--w]);
	*s = NULL;
}

static int	fill_it(const char **s, char **sarr, int wc, char c)
{
	const char	*tmp;
	int			i;
	int			w;

	i = 0;
	w = 0;
	while (w < wc)
	{
		tmp = *s;
		if (!(sarr[w] = (char*)malloc(sizeof(char) * (char_count(s, c) + 1))))
		{
			if (w > 0)
				ft_free(&sarr, w);
			return (0);
		}
		while (*tmp && *tmp != c)
			sarr[w][i++] = *tmp++;
		sarr[w++][i] = 0;
		i = 0;
	}
	sarr[w] = NULL;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**sarr;
	int			wc;

	if (!s)
		return (NULL);
	wc = ft_wordcount(s, c);
	if (!(sarr = (char**)malloc(sizeof(char*) * wc + 1)))
		return (NULL);
	while (*s == c)
		s++;
	if (fill_it(&s, sarr, wc, c) == 0)
		return (NULL);
	return (sarr);
}
