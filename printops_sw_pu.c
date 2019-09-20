/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:15:35 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 22:07:44 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_a(t_list **stack1, t_list **stack2)
{
	stack_push(stack2, stack1);
	ft_printf("pa\n");
}

void	push_b(t_list **stack1, t_list **stack2)
{
	stack_push(stack1, stack2);
	ft_printf("pb\n");
}

void	swap_a(t_list **stack1)
{
	stack_swap(stack1);
	ft_printf("sa\n");
}

void	swap_b(t_list **stack2)
{
	stack_swap(stack2);
	ft_printf("sb\n");
}

void	swap_s(t_list **stack1, t_list **stack2)
{
	stack_swap(stack1);
	stack_swap(stack2);
	ft_printf("ss\n");
}
