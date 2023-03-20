/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:37:06 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/19 21:47:32 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_clear(t_list **lst)
{
	t_list	*temp;
	t_list	*copylst;

	if ((*lst) == NULL)
		return ;
	copylst = (*lst);
	while (copylst)
	{
		temp = copylst->next;
		free(copylst);
		copylst = temp;
	}
	(*lst) = NULL;
}

t_list	*ft_median(t_list *list_a, t_list *list_b)
{
	int	*tab;
	int	med;
	int	i;
	int	pos;
	int	size_a;

	i = 0;
	pos = 0;
	size_a = ft_lst_size(list_a);
	while (size_a != 3)
	{
		size_a = ft_lst_size(list_a);
		tab = ft_pile_to_tab(list_a);
		tab = ft_sort_tab(tab, size_a);
		med = tab[(size_a / 7) * 5];
		if (list_a->n <= med)
			rotate(&list_a, "ra");
		else
			push(&list_a, &list_b, "pb");
		free(tab);
	}
	tab = ft_pile_to_tab(list_a);
	list_a = ft_three_arg(tab, list_a);
	free(tab);
	return (ft_move(list_a, list_b));
}
