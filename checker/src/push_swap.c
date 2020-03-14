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

int		count_char(char **argv) {
	int			size;
	char		**buf;
	int			i;

	i = -1;
	size = 0;
	while (*argv++ != NULL)
	{
		buf = ft_strsplit(*argv, ' ');
		while (buf && buf[++i])
		{
			size += ft_strlen(buf[i]) + 1;
			ft_strdel(&buf[i]);
		}
		i = -1;
		free(buf);
	}
	return (size);
}

char	*merge_args(char **argv) {
	char	*res;
	char	*current;
	char	**buf;
	int		i;

	i = -1;
	res = (char *)ft_memalloc(sizeof(char) * count_char(argv));
	current = res;
	while (*argv++ != NULL)
	{
		buf = ft_strsplit(*argv, ' ');
		while (buf && buf[++i]) {
			res = ft_strcpy(res, buf[i]);
			res[ft_strlen(res)] = ' ';
			res += ft_strlen(res);
			ft_strdel(&buf[i]);
		}
		free(buf);
		i = -1;
	}
	res = current;
	res[ft_strlen(res) - 1] = '\0';
	return (res);
}

int		main(int argc, char **argv)
{
	t_stk	stk;
	char	*params;

	if (argc <= 1)
		error();
	params = merge_args(argv);
	make_stk(&stk);
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
