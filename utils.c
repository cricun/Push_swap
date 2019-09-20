/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:55:28 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 22:30:58 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		is_stack_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->next && *(int*)stack->content > *(int*)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	make_decision(t_list *stack1, t_list *stack2)
{
	if (!stack1 || stack2 || !is_stack_sorted(stack1))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int		get_int(t_list *list)
{
	return (*(int*)list->content);
}

t_list	*stack_last(t_list *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
}

void	ft_exit(enum e_xit i, t_list **head, t_list **tail, char **line)
{
	if (line && *line)
		free(*line);
	ft_lstfree(head);
	ft_lstfree(tail);
	if (i == error)
		ft_printf("Error\n");
	else if (i == OK)
		ft_printf("OK\n");
	else if (i == KO)
		ft_printf("KO\n");
	exit(0);
}
