/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:56:37 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 22:41:57 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	merge_left(int stack1_block, int stack2_block,
		t_stack *stack1, t_stack *stack2)
{
	while (stack1_block > 0 || stack2_block > 0)
	{
		if (stack2_block == 0 ||
			(get_int(stack_last(stack1->lst)) > get_int(stack2->lst) &&
			stack1_block != 0))
		{
			revrot_a(&stack1->lst);
			--stack1_block;
			--stack1->size;
		}
		else
		{
			push_a(&stack1->lst, &stack2->lst);
			--stack2_block;
			--stack2->size;
		}
	}
}

void	toleft(const int sorted_block, t_stack *stack1, t_stack *stack2)
{
	int	stack1_block;
	int	stack2_block;
	int remain;

	remain = stack1->size % sorted_block;
	if (remain && stack1->size > stack2->size)
	{
		while (remain)
		{
			revrot_a(&stack1->lst);
			--remain;
		}
	}
	while (stack2->size > 0)
	{
		stack1_block = sorted_block;
		if (remain)
		{
			stack1_block = remain;
			remain = 0;
		}
		stack2_block = sorted_block;
		merge_left(stack1_block, stack2_block, stack1, stack2);
	}
}

void	toright(const int sorted_block, t_stack *stack1, t_stack *stack2)
{
	int	iter;
	int st1_remain;

	st1_remain = stack1->size % sorted_block;
	stack2->size = 0;
	while (stack2->size + sorted_block < stack1->size)
	{
		iter = 0;
		while (iter < sorted_block)
		{
			push_b(&stack1->lst, &stack2->lst);
			++iter;
			stack1->size--;
			stack2->size++;
		}
	}
}

void	st_mergesort(t_stack *stack1, t_stack *stack2)
{
	int	sorted_block;
	int maxstack1;
	int remain1;

	if (is_stack_sorted(stack1->lst))
		return ;
	stack1->size = ft_lstcount(stack1->lst);
	maxstack1 = stack1->size;
	stack2->size = sort_by2_toright(&stack1->size, &stack1->lst, &stack2->lst);
	sort_by2_left(&stack1->lst, stack1->size);
	sorted_block = 2;
	remain1 = maxstack1 % sorted_block;
	toleft(sorted_block, stack1, stack2);
	sorted_block *= 2;
	remain1 = maxstack1 % sorted_block;
	while (sorted_block < maxstack1)
	{
		if (is_stack_sorted(stack1->lst))
			return ;
		stack1->size = maxstack1;
		toright(sorted_block, stack1, stack2);
		toleft(sorted_block, stack1, stack2);
		sorted_block *= 2;
		remain1 += sorted_block;
	}
}

int		main(int argc, char **argv)
{
	t_stack stack1;
	t_stack stack2;

	if (argc < 2)
		return (1);
	stack2.lst = NULL;
	stack1.lst = NULL;
	stack1.lst = args_to_list(argc, argv);
	if (ft_lstcount(stack1.lst) == 0)
		return (1);
	if (ft_lstcount(stack1.lst) < 7)
		sort_less7(&stack1.lst, &stack2.lst);
	else
		st_mergesort(&stack1, &stack2);
	ft_lstfree(&stack1.lst);
	ft_lstfree(&stack2.lst);
}
