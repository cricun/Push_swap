/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:34:07 by djon-con          #+#    #+#             */
/*   Updated: 2018/11/30 17:40:21 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_back(t_list **lst, t_list *nnew)
{
	t_list *tmp;

	tmp = *lst;
	if (!tmp)
	{
		*lst = nnew;
		nnew->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nnew;
		nnew->next = NULL;
	}
}
