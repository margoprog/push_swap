/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:48:25 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/19 21:11:51 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_list *addr_list, int father)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = addr_list;
	while (tmp->n != father)
		tmp = tmp->next;
	return (tmp->index);
}

void	ft_add_index(t_list *addr_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = addr_list;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

int	price(t_list *list, int pos)
{
	int	price;
	int	size;

	size = ft_lst_size(list);
	if (pos > size / 2)
		price = size - pos;
	else
		price = -pos;
	return (price);
}

int	ft_totalprice(int price_a, int price_b)
{
	int	a;
	int	b;

	a = abs(price_a);
	b = abs(price_b);
	if ((price_a < 0 && price_b < 0) || (price_a > 0 && price_b > 0))
	{
		if (a >= b)
			return (a);
		else
			return (b);
	}
	return (a + b);
}

t_price	count_step(t_list *list_a, t_list *list_b, int pos, int value)
{
	t_price	calc;

	calc.daron = find_the_real_father(list_a, value, &calc.pos_daron);
	ft_add_index(list_a);
	calc.pos_daron = find_index(list_a, calc.daron);
	calc.price_a = price(list_a, calc.pos_daron);
	calc.price_b = price(list_b, pos);
	calc.total = ft_totalprice(calc.price_a, calc.price_b);
	return (calc);
}
