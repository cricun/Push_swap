/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:01:33 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/11 22:10:33 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (void*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	if (!(tmp->content = (void*)malloc(content_size)))
	{
		free(tmp);
		return (NULL);
	}
	ft_memmove(tmp->content, content, content_size);
	(*tmp).content_size = (content == NULL ? 0 : content_size);
	tmp->next = NULL;
	return (tmp);
}
