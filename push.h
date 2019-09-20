/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:54:49 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 21:36:58 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define KEK print_stacks(*stack1, *stack2);
# define HERE printf("HERE\n");

enum			e_xit
{
	OK,
	KO,
	error,
	nothing
};

typedef struct	s_intarr
{
	int			*arr;
	int			len;
}				t_intarr;

typedef struct	s_stack
{
	t_list		*lst;
	int			size;
}				t_stack;

t_list			*args_to_list(int argc, char **argv);
t_list			*get_instructions(t_list **stack1);
void			ft_exit(enum e_xit i, t_list **head, t_list **tail,
				char **line);
void			stack_swap(t_list **stack);
void			stack_rotate(t_list **stack);
void			stack_revrotate(t_list **stack);
void			stack_push(t_list **src, t_list **dst);
void			print_args(t_list *lst);
int				apply_instructions(t_list **stack1, t_list **stack2,
				t_list *todo);
void			print_instr(t_list *lst);
void			print_args(t_list *lst);
void			make_decision(t_list *stack1, t_list *stack2);
void			print_stacks(t_list *stack1, t_list *stack2);
void			do_rotate(char *str, t_list **stack1, t_list **stack2);
void			do_push(char *str, t_list **stack1, t_list **stack2);
void			do_swap(char *str, t_list **stack1, t_list **stack2);
int				sort_by2_toright(int *stack1_size, t_list **stack1,
				t_list **stack2);
void			sort_by2_left(t_list **stack1, int stack1_size);
int				get_int(t_list *list);
void			sort_less7(t_list **stack1, t_list **stack2);
t_list			*stack_last(t_list *stack);
void			push_a(t_list **stack1, t_list **stack2);
void			push_b(t_list **stack1, t_list **stack2);
void			swap_a(t_list **stack1);
void			swap_b(t_list **stack1);
void			swap_s(t_list **stack1, t_list **stack2);
void			rot_a(t_list **stack1);
void			rot_b(t_list **stack2);
void			rot_r(t_list **stack1, t_list **stack2);
void			revrot_a(t_list **stack1);
void			revrot_b(t_list **stack2);
void			revrot_r(t_list **stack1, t_list **stack2);
int				is_stack_sorted(t_list *stack);
#endif
