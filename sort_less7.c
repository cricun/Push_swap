/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 22:48:31 by djon-con          #+#    #+#             */
/*   Updated: 2019/06/11 22:48:33 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			sort2(t_list **stack, char c)
{
	if (ft_lstcount(*stack) > 2)
		return (3);
	if (c == 'a')
		if ((*stack)->next && get_int(*stack) > get_int((*stack)->next))
			swap_a(stack);
	if (c == 'b')
		if ((*stack)->next && get_int(*stack) < get_int((*stack)->next))
			swap_b(stack);
	return (2);
}

void		sort3left(t_list **stack)
{
	int	num1;
	int	num2;
	int	num3;

	if (sort2(stack, 'a') == 2)
		return ;
	num1 = *(int*)(*stack)->content;
	num2 = *(int*)(*stack)->next->content;
	num3 = *(int*)(*stack)->next->next->content;
	if (num1 > num2 && num2 > num3)
	{
		swap_a(stack);
		revrot_a(stack);
	}
	else if (num1 > num3 && num3 > num2)
		rot_a(stack);
	else if (num1 > num2 && num3 > num1)
		swap_a(stack);
	else if (num3 > num1 && num2 > num3)
	{
		revrot_a(stack);
		swap_a(stack);
	}
	else if (num1 < num2 && num1 > num3)
		revrot_a(stack);
}

void		revsort3right(t_list **stack)
{
	int	num1;
	int	num2;
	int	num3;

	if (sort2(stack, 'b') == 2)
		return ;
	num1 = *(int*)(*stack)->content;
	num2 = *(int*)(*stack)->next->content;
	num3 = *(int*)(*stack)->next->next->content;
	if (num1 < num2 && num2 < num3)
	{
		swap_b(stack);
		revrot_b(stack);
	}
	else if (num1 < num3 && num3 < num2)
		rot_b(stack);
	else if (num1 < num2 && num3 < num1)
		swap_b(stack);
	else if (num3 < num1 && num2 < num3)
	{
		revrot_b(stack);
		swap_b(stack);
	}
	else if (num1 > num2 && num1 < num3)
		revrot_b(stack);
}

static void	merge_left(t_list **stack1, t_list **stack2,
		int stack1_block, int stack2_block)
{
	if (is_stack_sorted(*stack1) && stack2_block == 0)
		return ;
	while (stack1_block > 0 || stack2_block > 0)
	{
		if (stack2_block == 0 || (get_int(stack_last(*stack1))
			> get_int(*stack2) && stack1_block != 0))
		{
			revrot_a(stack1);
			--stack1_block;
		}
		else
		{
			push_a(stack1, stack2);
			--stack2_block;
		}
	}
}

void		sort_less7(t_list **stack1, t_list **stack2)
{
	int iter;
	int size1;
	int size2;

	if (is_stack_sorted(*stack1))
		return ;
	size1 = ft_lstcount(*stack1);
	size2 = 0;
	while (size1 > 3)
	{
		push_b(stack1, stack2);
		size1--;
		size2++;
	}
	sort3left(stack1);
	if (*stack2)
		revsort3right(stack2);
	merge_left(stack1, stack2, size1, size2);
}
