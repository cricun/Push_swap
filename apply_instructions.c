/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:42:53 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 17:12:40 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	do_swap(char *str, t_list **stack1, t_list **stack2)
{
	if (ft_strcmp(str, "a") == 0)
		stack_swap(stack1);
	else if (ft_strcmp(str, "b") == 0)
		stack_swap(stack2);
	else if (ft_strcmp(str, "s") == 0)
	{
		stack_swap(stack1);
		stack_swap(stack2);
	}
}

void	do_push(char *str, t_list **stack1, t_list **stack2)
{
	if (ft_strcmp(str, "a") == 0)
		stack_push(stack2, stack1);
	else if (ft_strcmp(str, "b") == 0)
		stack_push(stack1, stack2);
}

void	do_rotate(char *str, t_list **stack1, t_list **stack2)
{
	if (ft_strcmp(str, "a") == 0)
		stack_rotate(stack1);
	else if (ft_strcmp(str, "b") == 0)
		stack_rotate(stack2);
	else if (ft_strcmp(str, "r") == 0)
	{
		stack_rotate(stack1);
		stack_rotate(stack2);
	}
	else if (ft_strcmp(str, "ra") == 0)
		stack_revrotate(stack1);
	else if (ft_strcmp(str, "rb") == 0)
		stack_revrotate(stack2);
	else if (ft_strcmp(str, "rr") == 0)
	{
		stack_revrotate(stack1);
		stack_revrotate(stack2);
	}
}

int		apply_instructions(t_list **stack1, t_list **stack2,
					t_list *todo)
{
	while (todo)
	{
		if (!todo->content)
			return (0);
		if (*(char*)todo->content == 's')
			do_swap((char*)todo->content + 1, stack1, stack2);
		else if (*(char*)todo->content == 'p')
			do_push((char*)todo->content + 1, stack1, stack2);
		else if (*(char*)todo->content == 'r')
			do_rotate((char*)todo->content + 1, stack1, stack2);
		else
			return (0);
		todo = todo->next;
	}
	return (1);
}
