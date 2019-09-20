/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:15:37 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 19:26:10 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static inline void	ps_skip_number(char **str, t_list **head)
{
	if (**str == '-')
		(*str)++;
	while (ft_isnumber(**str))
		(*str)++;
}

static inline void	ps_skip_spaces(char **str, t_list **head)
{
	while (ft_isspace(**str))
		++(*str);
	if (**str && !ft_isnumber(**str) &&
		(**str == '-' && !ft_isnumber(*(*str + 1))))
		ft_exit(error, NULL, head, NULL);
}

static long			get_number(char **str, t_list **head)
{
	long		tmp;
	const char	*strstart;

	strstart = *str;
	if (**str == 0)
		ft_exit(error, NULL, head, NULL);
	ps_skip_number(str, head);
	ps_skip_spaces(str, head);
	if ((tmp = ft_atol(strstart)) < INT_MIN || tmp > INT_MAX)
		ft_exit(error, NULL, head, NULL);
	return (tmp);
}

static inline void	check_if_copy(int i, t_list *head)
{
	while (head)
	{
		if (*(int*)head->content == i)
			ft_exit(error, NULL, &head, NULL);
		head = head->next;
	}
}

t_list				*args_to_list(int argc, char **argv)
{
	t_list	*head;
	t_list	*tail;
	t_list	*lst;
	long	num;

	argv++;
	num = get_number(argv, NULL);
	if (!(tail = ft_lstnew(&num, sizeof(num))))
		ft_exit(error, NULL, &head, NULL);
	head = tail;
	while (--argc >= 1)
	{
		while (**argv)
		{
			num = get_number(argv, &head);
			check_if_copy(num, head);
			if (!(lst = ft_lstnew(&num, sizeof(num))))
				ft_exit(error, NULL, &head, NULL);
			ft_lstaddrev(&tail, lst);
		}
		++argv;
	}
	return (head);
}
