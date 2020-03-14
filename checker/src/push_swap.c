/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:27:04 by tdontos-          #+#    #+#             */
/*   Updated: 2019/07/12 19:27:06 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_printf("Error");
	exit(1);
}

void	make_stk(t_stk *stk)
{
	stk->cnt_a = 0;
	stk->cnt_b = 0;
	stk->min = 0;
	stk->max = 0;
}

int		main(int argc, char **argv)
{
	t_stk	stk;

	make_stk(&stk);
	if (argc <= 1)
		error();
	stk.cnt_a = read_arg(argc, argv, &stk);
	s_rotate_rev(&stk, 'a');
	s_push(&stk, 'b');
	s_swap(&stk, 'a');
	s_rotate_rev(&stk, 'a');
	s_push(&stk, 'a');
	checker(&stk);
	free(stk.a);
	free(stk.b);
	return (0);
}
