# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djon-con <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 20:58:28 by djon-con          #+#    #+#              #
#    Updated: 2019/06/12 21:03:18 by djon-con         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH=make -f make-push
CHECKER=make -f make-checker

all:
	@$(PUSH)
	@$(CHECKER)

clean:
	@$(PUSH) clean
	@$(CHECKER) clean

fclean:
	@$(PUSH) fclean
	@$(CHECKER) fclean

re: fclean all
