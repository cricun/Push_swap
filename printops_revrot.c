/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printops_revrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:21:56 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 22:07:28 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	revrot_a(t_list **stack1)
{
	stack_revrotate(stack1);
	ft_printf("rra\n");
}

void	revrot_b(t_list **stack2)
{
	stack_revrotate(stack2);
	ft_printf("rrb\n");
}

void	revrot_r(t_list **stack1, t_list **stack2)
{
	stack_revrotate(stack1);
	stack_revrotate(stack2);
	ft_printf("rrr\n");
}
