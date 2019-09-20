/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:48:20 by djon-con          #+#    #+#             */
/*   Updated: 2019/06/12 16:48:21 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		sort_by2_toright(int *stack1_size, t_list **stack1, t_list **stack2)
{
	int stack2_size;

	stack2_size = 0;
	while (stack2_size + 2 < *stack1_size)
	{
		push_b(stack1, stack2);
		push_b(stack1, stack2);
		if ((*stack2) && (*stack2)->next &&
				*(int*)(*stack2)->next->content > *(int*)(*stack2)->content)
		{
			if ((*stack1) && (*stack1)->next &&
					*(int*)(*stack1)->content > *(int*)(*stack1)->next->content)
			{
				swap_s(stack1, stack2);
			}
			else
				swap_b(stack2);
		}
		*stack1_size -= 2;
		stack2_size += 2;
	}
	return (stack2_size);
}

void	sort_by2_left(t_list **stack1, int stack1_size)
{
	while (stack1_size > 3)
	{
		if (*(int*)(*stack1)->content > *(int*)(*stack1)->next->content)
			swap_a(stack1);
		revrot_a(stack1);
		revrot_a(stack1);
		stack1_size -= 2;
	}
	if (*stack1 && (*stack1)->next &&
			*(int*)(*stack1)->content > *(int*)(*stack1)->next->content)
		swap_a(stack1);
}
