/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printops_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:20:16 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/19 22:07:17 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rot_a(t_list **stack1)
{
	stack_rotate(stack1);
	ft_printf("ra\n");
}

void	rot_b(t_list **stack2)
{
	stack_rotate(stack2);
	ft_printf("rb\n");
}

void	rot_r(t_list **stack1, t_list **stack2)
{
	stack_rotate(stack1);
	stack_rotate(stack2);
	ft_printf("rr\n");
}
