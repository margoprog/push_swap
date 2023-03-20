/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:03:41 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/20 20:12:59 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_price	ft_faster_father(t_list *list_a, t_list **list_b, int size_b)
{
	int		pos;
	int		step;
	t_list	*temp;
	t_price	temps;
	t_price	calc;

	temp = *list_b;
	pos = 0;
	step = MAX;
	while (pos < size_b)
	{
		calc = count_step(list_a, *list_b, pos, temp->n);
		if (step > calc.total)
		{
			step = calc.total;
			temps = calc;
		}
		temp = temp->next;
		pos++;
	}
	return (temps);
}

t_list	*ft_last_move(t_list *list_a)
{
	int	min;
	int	pos_min;

	min = get_min(list_a);
	ft_add_index(list_a);
	pos_min = find_index(list_a, min);
	if (pos_min > ft_lst_size(list_a) / 2)
	{
		while (list_a->n != min)
			rotate_reverse(&list_a, "rra");
	}
	else
	{
		while (list_a->n != min)
			rotate(&list_a, "ra");
	}
	return (list_a);
}

t_price	ft_price(t_price calc, t_list **list_a, t_list **list_b)
{
	if (calc.price_b > 0)
	{
		rotate_reverse(list_a, "");
		rotate_reverse(list_b, "rrr");
		calc.price_b--;
	}
	else
		rotate_reverse(list_a, "rra");
	calc.price_a--;
	return (calc);
}

t_price	ft_price2(t_price calc, t_list **list_a, t_list **list_b)
{
	if (calc.price_b < 0)
	{
		rotate(list_a, "");
		rotate(list_b, "rr");
		calc.price_b++;
	}
	else
		rotate(list_a, "ra");
	calc.price_a++;
	return (calc);
}

t_list	*ft_move(t_list *list_a, t_list *list_b)
{
	int		size_b;
	t_price	calc;

	while (ft_lst_size(list_b) > 0)
	{
		size_b = ft_lst_size(list_b);
		calc = ft_faster_father(list_a, &list_b, size_b);
		while (calc.price_a > 0)
			calc = ft_price(calc, &list_a, &list_b);
		while (calc.price_b > 0)
		{
			rotate_reverse(&list_b, "rrb");
			calc.price_b--;
		}
		while (calc.price_a < 0)
			calc = ft_price2(calc, &list_a, &list_b);
		while (calc.price_b < 0)
		{
			rotate(&list_b, "rb");
			calc.price_b++;
		}
		push(&list_b, &list_a, "pa");
	}
	list_a = ft_last_move(list_a);
	return (list_a);
}
