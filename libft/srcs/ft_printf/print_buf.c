/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:31:26 by djon-con          #+#    #+#             */
/*   Updated: 2019/04/16 15:12:37 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_buf(t_buf *tbuf, char c)
{
	if (tbuf->i + 1 > PRINTF_BUF)
		print_buf(tbuf, 0);
	tbuf->buf[tbuf->i++] = c;
}

void	print_buf(t_buf *tbuf, int last_print)
{
	write(1, tbuf->buf, tbuf->i);
	tbuf->count += tbuf->i;
	tbuf->i = 0;
	if (last_print && COLOR)
		write(1, GREY, 7);
}
