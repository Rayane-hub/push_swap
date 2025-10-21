/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:28:44 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/14 17:08:26 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **lst_a)
{
	t_stack	*first;
	t_stack	*second;

	ft_printf("sa\n");
	if ((*lst_a) && (*lst_a)->next)
	{
		first = *lst_a;
		second = (*lst_a)->next;
		if (!second->next)
			first->next = NULL;
		else
		{
			first->next = second->next;
			second->next->prev = first;
		}
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		*lst_a = second;
	}
	else
		ft_printf("Pas asser d'éléments au sommet de la pile a.\n");
}

void	swap_b(t_stack **lst_b)
{
	t_stack	*first;
	t_stack	*second;

	ft_printf("sb\n");
	if ((*lst_b) && (*lst_b)->next)
	{
		first = *lst_b;
		second = (*lst_b)->next;
		if (!second->next)
			first->next = NULL;
		else
		{
			first->next = second->next;
			second->next->prev = first;
		}
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		*lst_b = second;
	}
	else
		ft_printf("Pas asser d'éléments au sommet de la pile b.\n");
}

void	ss(t_stack **lst_a, t_stack **lst_b)
{
	swap_a(lst_a);
	swap_b(lst_b);
}

void	push_a(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*first;
	t_stack	*second;

	ft_printf("pa\n");
	if (*lst_b)
	{
		first = *lst_b;
		second = (*lst_b)->next;
		if (*lst_a)
		{
			first->next = *lst_a;
			(*lst_a)->prev = first;
		}
		else
			first->next = NULL;
		if (second)
			second->prev = NULL;
		*lst_b = second;
		*lst_a = first;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile b.\n");
}

void	push_b(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*first;
	t_stack	*second;

	ft_printf("pb\n");
	if (*lst_a)
	{
		first = *lst_a;
		second = (*lst_a)->next;
		if (*lst_b)
		{
			first->next = (*lst_b);
			(*lst_b)->prev = first;
		}
		else
			first->next = NULL;
		if (second)
			second->prev = NULL;
		*lst_a = second;
		*lst_b = first;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile a.\n");
}
