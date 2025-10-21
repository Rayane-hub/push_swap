/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:26:18 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/19 16:02:53 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_rank(t_stack *lst_a, t_stack *lst_b)
{
	int	i;

	i = 1;
	ft_printf("RANK\n");
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			ft_printf("%d :    ", lst_a->i);
			ft_printf("|%d|\t\t", lst_a->rank);
			lst_a = lst_a->next;
		}
		else
			ft_printf("   \t\t");
		if (lst_b)
		{
			ft_printf("|%d|\n", lst_b->rank);
			lst_b = lst_b->next;
		}
		else
			ft_printf("\n");
		i++;
	}
	ft_printf("\t_\t\t _\n\ta\t\t b\n");
}

void	rank_list(t_stack **lst_a, int lst_size)
{
	long	max;
	long	min;
	int		i;
	t_stack	*tmp;
	t_stack	*first;

	min = -2147483649;
	i = 0;
	while (i < lst_size)
	{
		first = *lst_a;
		max = 2147483648;
		while (first)
		{
			if (max > first->content && first->content > min)
			{
				max = first->content;
				tmp = first;
			}
			first = first->next;
		}
		min = max;
		tmp->rank = i;
		i++;
	}
}

int	ft_find_i_rank_min(int rank_min, t_stack *lst_a)
{
	while (lst_a->rank != rank_min)
	{
		lst_a = lst_a->next;
	}
	return (lst_a->i);
}

void	ft_exit(t_stack *lst, int status)
{
	if (status == -1)
		write(2, "Error\nOverflow", 14);
	if (status == -2)
		write(2, "Error\nDuplicate", 15);
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			free(lst->prev);
		}
		if (lst)
			free(lst);
	}
	exit(0);
}
