/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:24:56 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/14 17:03:18 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_a(t_stack **lst_a, t_stack **lst_b)
{
	int		i_min;
	t_stack	*last_a;

	i_min = find_i_min(*lst_a);
	last_a = ft_lstlast(*lst_a);
	if (i_min <= (last_a->i / 2))
	{
		while (i_min > 0)
		{
			rotate_a(lst_a);
			i_min--;
		}
	}
	else
	{
		while (i_min <= last_a->i)
		{
			reverse_rotate_a(lst_a);
			i_min++;
		}
	}
	push_b(lst_a, lst_b);
	fill_i_lst(*lst_a);
	fill_i_lst(*lst_b);
}

void	up_min_a(t_stack **lst_a, t_stack **lst_b)
{
	int		i_min;
	t_stack	*last_a;

	last_a = ft_lstlast(*lst_a);
	i_min = find_i_min(*lst_a);
	if (i_min <= (last_a->i / 2))
	{
		while (i_min > 0)
		{
			rotate_a(lst_a);
			i_min--;
		}
	}
	else
	{
		while (i_min <= last_a->i)
		{
			reverse_rotate_a(lst_a);
			i_min++;
		}
	}
	fill_i_lst(*lst_a);
	fill_i_lst(*lst_b);
}

void	push_max_a(t_stack **lst_a, t_stack **lst_b)
{
	int		i_max;
	t_stack	*last_a;

	i_max = find_i_max(*lst_a);
	last_a = ft_lstlast(*lst_a);
	if (i_max <= (last_a->i / 2))
	{
		while (i_max > 0)
		{
			rotate_a(lst_a);
			i_max--;
		}
	}
	else
	{
		while (i_max <= last_a->i)
		{
			reverse_rotate_a(lst_a);
			i_max++;
		}
	}
	push_b(lst_a, lst_b);
	fill_i_lst(*lst_a);
	fill_i_lst(*lst_b);
}

void	push_max_b(t_stack **lst_a, t_stack **lst_b)
{
	int		i_max;
	t_stack	*last_b;

	i_max = find_i_max(*lst_b);
	last_b = ft_lstlast(*lst_b);
	if (i_max <= (last_b->i / 2))
	{
		while (i_max > 0)
		{
			rotate_b(lst_b);
			i_max--;
		}
	}
	else
	{
		while (i_max <= last_b->i)
		{
			reverse_rotate_b(lst_b);
			i_max++;
		}
	}
	push_a(lst_a, lst_b);
	fill_i_lst(*lst_b);
}
