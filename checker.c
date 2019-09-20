/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:32:22 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 22:08:30 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		print_instr(t_list *lst)
{
	ft_printf("instructions:\n");
	while (lst && lst->content)
	{
		ft_printf("%s\n", (char*)lst->content);
		lst = lst->next;
	}
}

void		print_args(t_list *lst)
{
	ft_printf("nums:\n");
	while (lst && lst->content)
	{
		ft_printf("%d\n", *(int*)lst->content);
		lst = lst->next;
	}
}

int			main(int argc, char **argv)
{
	t_list	*stack1;
	t_list	*stack2;
	t_list	*instructions;

	if (argc < 2)
		return (nothing);
	stack2 = NULL;
	stack1 = args_to_list(argc, argv);
	instructions = get_instructions(&stack1);
	if (apply_instructions(&stack1, &stack2, instructions))
		make_decision(stack1, stack2);
	else
		ft_printf("Error\n");
	ft_lstfree(&instructions);
	ft_lstfree(&stack1);
	ft_lstfree(&stack2);
}
