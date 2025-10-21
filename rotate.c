/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:29:12 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/14 17:09:31 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **lst_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	last = ft_lstlast(*lst_a);
	ft_printf("ra\n");
	if ((*lst_a) && (*lst_a)->next)
	{
		first = (*lst_a);
		second = (*lst_a)->next;
		first->prev = last;
		first->next = NULL;
		last->next = first;
		second->prev = NULL;
		*lst_a = second;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile a.\n");
}

void	rotate_b(t_stack **lst_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	ft_printf("rb\n");
	last = ft_lstlast(*lst_b);
	if ((*lst_b) && (*lst_b)->next)
	{
		first = (*lst_b);
		second = (*lst_b)->next;
		first->prev = last;
		first->next = NULL;
		last->next = first;
		second->prev = NULL;
		*lst_b = second;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile b.\n");
}

static void	rrotate_a(t_stack **lst_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	last = ft_lstlast(*lst_a);
	if ((*lst_a) && (*lst_a)->next)
	{
		first = (*lst_a);
		second = (*lst_a)->next;
		first->prev = last;
		first->next = NULL;
		last->next = first;
		second->prev = NULL;
		*lst_a = second;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile a.\n");
}

static void	rrotate_b(t_stack **lst_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	last = ft_lstlast(*lst_b);
	if ((*lst_b) && (*lst_b)->next)
	{
		first = (*lst_b);
		second = (*lst_b)->next;
		first->prev = last;
		first->next = NULL;
		last->next = first;
		second->prev = NULL;
		*lst_b = second;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile b.\n");
}

void	rr(t_stack **lst_a, t_stack **lst_b)
{
	ft_printf("rr\n");
	rrotate_a(lst_a);
	rrotate_b(lst_b);
}
