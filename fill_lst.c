/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:29:13 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/19 15:36:07 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lstlast;

	lstlast = ft_lstlast(*lst);
	if (*lst)
	{
		lstlast->next = new;
		new->prev = lstlast;
	}
	else
		*lst = new;
}

static t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static int	ft_atoi_swap(const char *str, int *len_nb, t_stack *lst, int i)
{
	int		sign;
	long	n;

	n = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n * 10 / 10 != n)
			ft_exit(lst, -1);
		n *= 10;
		n = n + str[i] - '0';
		i++;
	}
	*len_nb = i;
	if (((n * sign) > 2147483647) || ((n * sign) < -2147483648))
		ft_exit(lst, -1);
	return (n * sign);
}

void	ft_fill_lst(int ac, char **av, t_stack **lst)
{
	t_stack	*new_elem;
	int		i;
	int		j;
	int		len_nb;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ')
			{
				new_elem = ft_lstnew(ft_atoi_swap(&av[i][j], &len_nb, *lst, 0));
				ft_lstadd_back(lst, new_elem);
				j += len_nb;
			}
			if (av[i][j])
				j++;
		}
		i++;
	}
}
