/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:03:44 by tdontos-          #+#    #+#             */
/*   Updated: 2019/07/13 14:03:46 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort(t_stk *stk)
{
	int		i;

	i = -1;
	ft_printf("_____A________\n");
	while (++i < stk->cnt_a)
		ft_printf("%d) %d\n", i, stk->a[i]);
	i = -1;
	ft_printf("_____B________\n");
	while (++i < stk->cnt_b)
		ft_printf("%d) %d\n", i, stk->b[i]);
	return (1);
}

void	checker(t_stk *stk)
{
	int		i;

	i = -1;
	while (++i < stk->cnt_a - 1)
	{
		ft_printf("stk->a[%d] = %d > %d\n", i, stk->a[i], stk->a[i + 1]);
		if (stk->a[i] > stk->a[i + 1])
		{
			ft_printf("KO\n");
			return ;
		}
	}
	ft_printf("OK\n");
}
