/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:15:36 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/19 21:11:51 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *list_a)
{
	t_list	*temp;
	int		min;

	temp = list_a;
	min = list_a->n;
	while (temp)
	{
		if (temp->n < min)
			min = temp->n;
		temp = temp->next;
	}
	return (min);
}

int	get_max(t_list *list_a)
{
	t_list	*temp;
	int		max;

	temp = list_a;
	max = list_a->n;
	while (temp)
	{
		if (temp->n > max)
			max = temp->n;
		temp = temp->next;
	}
	return (max);
}

int	find_the_real_father(t_list *list_a, int nb, int *index)
{
	int		max;
	int		min;
	t_list	*tmp_a;

	(void)index;
	max = get_max(list_a);
	if (nb > max)
	{
		min = get_min(list_a);
		return (min);
	}
	tmp_a = list_a;
	while (tmp_a)
	{
		if (tmp_a->n > nb && max > tmp_a->n)
			max = tmp_a->n;
		tmp_a = tmp_a->next;
	}
	return (max);
}
