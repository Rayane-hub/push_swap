/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:31:09 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/19 12:45:06 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_str(int i, char **av)
{
	int	j;

	j = 0;
	while (av[i][j])
	{
		if ((!(av[i][j] >= '0' && av[i][j] <= '9')) && \
		av[i][j] != '-' && av[i][j] != '+' && av[i][j] != ' ')
			return (0);
		if (av[i][j] == '+' || av[i][j] == '-')
			if (!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
				return (0);
		if (av[i][j] >= '0' && av[i][j] <= '9')
			if (!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9') && \
			av[i][j + 1] != ' ' && av[i][j + 1] != 0)
				return (0);
		j++;
	}
	return (1);
}

//Fonction : Verifier les entrer 
// Retour : count_nb = succes, 0 = echec
int	ft_check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_check_str(i, av))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_double(t_stack *lst_a)
{
	t_stack	*lst_ptr;
	t_stack	*begin_lst;

	begin_lst = lst_a;
	while (begin_lst)
	{
		lst_ptr = begin_lst;
		while (lst_ptr->next)
		{
			if (begin_lst->content == lst_ptr->next->content)
				ft_exit(lst_a, -2);
			lst_ptr = lst_ptr->next;
		}
		begin_lst = begin_lst->next;
	}
}

int	ft_check_sort_tab(t_stack *lst)
{
	t_stack	*lst_ptr;

	while (lst->next)
	{
		lst_ptr = lst;
		while (lst_ptr->next)
		{
			if (lst->content > lst_ptr->next->content)
				return (0);
			lst_ptr = lst_ptr->next;
		}
		lst = lst->next;
	}
	return (1);
}

void	ft_print_lst(t_stack *lst_a, t_stack *lst_b)
{
	while (lst_a || lst_b)
	{
		if (lst_a)
		{
			ft_printf("%d :    ", lst_a->i);
			ft_printf("|%d|\t\t", lst_a->content);
			lst_a = lst_a->next;
		}
		else
			ft_printf("   \t\t\t");
		if (lst_b)
		{
			ft_printf("|%d|\t: %d\n", lst_b->content, lst_b->i);
			lst_b = lst_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\t_\t\t _\n\ta\t\t b\n");
}
