/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:55:53 by tdontos-          #+#    #+#             */
/*   Updated: 2019/07/12 20:55:54 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		read_arg(int argc, char **argv, t_stk *stk)
// {
// 	int		i;
// 	int		j;
// 	int		a[count_elem(argc, argv)];

// 	i = 0;
// 	j = -1;
// 	while (++j < argc - 1)
// 	{
// 		if (ft_strchr(argv[j + 1], ' ') != NULL)
// 			i += check_arg(argv[j + 1], a, i, stk) - 1;
// 		else if (check_forbidn(argv[j + 1]))
// 			error();
// 		else
// 			a[i] = add_new(a, ft_atoi(argv[j + 1]), i, stk);
// 		i++;
// 	}
// 	stk->a = (int *)ft_memalloc(sizeof(int) * i);
// 	stk->b = (int *)ft_memalloc(sizeof(int) * i);
// 	j = -1;
// 	while (++j < i)
// 		stk->a[j] = a[j];
// 	return (i);
// }

int		read_arg(int argc, char **argv, t_stk *stk)
{
	int		i;
	int		j;
	int		a[count_elem(argc, argv)];

	i = 0;
	j = -1;
	while (++j < argc - 1)
	{
		if (ft_strchr(argv[j + 1], ' ') != NULL)
			i += check_arg(argv[j + 1], a, i, stk) - 1;
		else if (check_forbidn(argv[j + 1]))
			error();
		else
			a[i] = add_new(a, ft_atoi(argv[j + 1]), i, stk);
		i++;
	}
	stk->a = (int *)ft_memalloc(sizeof(int) * i);
	stk->b = (int *)ft_memalloc(sizeof(int) * i);
	j = -1;
	while (++j < i)
		stk->a[j] = a[j];
	return (i);
}

int		check_arg(char *line, int *a, int next, t_stk *stk)
{
	int		i;
	int		count;
	char	**get;

	count = ft_chr_rep(line, ' ') + 1;
	get = ft_strsplit(line, ' ');
	i = next - 1;
	while (++i < count)
	{
		if (get[i] == NULL || get[i][0] == '\0' || check_forbidn(get[i]))
			error();
		a[i] = add_new(a, ft_atoi(get[i]), i, stk);
		free(get[i]);
	}
	free(get);
	return (i);
}

int		check_forbidn(char *str)
{
	int		sign;

	sign = 0;
	if (str == NULL)
		return (1);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
			return (1);
		if (ft_isdigit(*str))
			sign = 1;
		if (*str == '-' || *str == '+')
			sign == 0 ? sign = 1 : error();
		str++;
	}
	return (0);
}

int		add_new(int a[], int new, int max, t_stk *stk)
{
	int		i;

	i = -1;
	while (++i < max)
	{
		stk->min = a[i] < stk->min ? a[i] : stk->min;
		stk->max = a[i] > stk->max ? a[i] : stk->max;
		if (new == a[i])
			error();
	}
	return (new);
}

int		count_elem(int argc, char **argv)
{
	int		i;
	int		count;

	i = 0;
	while (argc > 0)
	{
		count = ft_chr_rep(argv[argc], ' ');
		i += count == 0 ? 1 : count;
		argc--;
	}
	return (i);
}
