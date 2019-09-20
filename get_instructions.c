/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:57:02 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 22:29:41 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void		tmp_function(t_list **stack1, t_list **stack2, t_list *todo)
{
	if (*(char*)todo->content == 's')
		do_swap((char*)todo->content + 1, stack1, stack2);
	else if (*(char*)todo->content == 'p')
		do_push((char*)todo->content + 1, stack1, stack2);
	else if (*(char*)todo->content == 'r')
		do_rotate((char*)todo->content + 1, stack1, stack2);
}

static int		valid_chk(char *str)
{
	static char	correct[11][4] = {"sa", "sb", "ss", "pa", "pb", "ra",
							"rb", "rr", "rra", "rrb", "rrr"};
	int			word;

	word = 0;
	while (word < 11)
	{
		if (ft_strcmp(str, correct[word]) == 0)
			return (1);
		word++;
	}
	return (0);
}

static void		lines_to_stack(t_list **stack1, t_list *top, t_list *bottom)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (!valid_chk(line) ||
		!(bottom->next = ft_lstnew(line, ft_strlen(line))))
			ft_exit(error, &top, stack1, &line);
		free(line);
		bottom = bottom->next;
	}
}

t_list			*get_instructions(t_list **stack1)
{
	t_list	*top;
	t_list	*bottom;
	int		gnl;
	char	*line;

	gnl = get_next_line(0, &line);
	if (gnl == 0)
	{
		make_decision(*stack1, NULL);
		ft_exit(nothing, NULL, stack1, NULL);
	}
	else if (gnl != 2)
		ft_exit(error, NULL, stack1, &line);
	if (!(bottom = ft_lstnew(line, ft_strlen(line))))
		ft_exit(error, &bottom, stack1, &line);
	top = bottom;
	if (!valid_chk(line))
		ft_exit(error, &top, stack1, &line);
	free(line);
	lines_to_stack(stack1, top, bottom);
	return (top);
}
