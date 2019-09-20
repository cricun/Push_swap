/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:01:39 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 21:42:34 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_stacks(t_list *stack1, t_list *stack2)
{
	int stack1_len;
	int	stack2_len;

	stack1_len = ft_lstcount(stack1);
	stack2_len = ft_lstcount(stack2);
	while (stack1_len-- - stack2_len > 0)
	{
		ft_printf("{RED}%d\n", *(int*)stack1->content);
		stack1 = stack1->next;
	}
	while (stack1_len - stack2_len-- < 0)
	{
		ft_printf("{GREEN}\t%d\n", *(int*)stack2->content);
		stack2 = stack2->next;
	}
	while (stack1_len != 0)
	{
		ft_printf("{RED}%d\t{GREEN}%d\n",
				*(int*)stack1->content, *(int*)stack2->content);
		stack1 = stack1->next;
		stack2 = stack2->next;
		--stack1_len;
	}
	ft_printf("______________________\n");
}
