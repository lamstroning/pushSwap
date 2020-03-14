/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 19:37:49 by tdontos-          #+#    #+#             */
/*   Updated: 2019/07/12 19:37:51 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>

typedef struct	s_stk
{
	int			*a;
	int			*b;
	int			cnt_a;
	int			cnt_b;
	int			min;
	int			max;
}				t_stk;

void			error(void);
void			make_stk(t_stk	*stk);
char			*merge_args(char **argv);
int				count_char(char **argv);


int				check_arg(char *line, int *a, int next, t_stk *stk);
int				check_forbidn(char *str);
int				add_new(int a[], int new, int max, t_stk *stk);
int				read_arg(int argc, char **argv, t_stk *stk);
int				count_elem(int argc, char **argv);

int				sort(t_stk *stk);

void			s_swap(t_stk *stk, char c);
void			s_push(t_stk *stk, char c);
void			s_rotate(t_stk *stk, char c);
void			s_rotate_rev(t_stk *stk, char c);
void			push_down(int **stk, int max);

void			checker(t_stk *stk);

#endif
