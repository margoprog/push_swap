/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:38:41 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/19 22:30:48 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_fulfill_a(t_list *list_a, char **tab)
{
	t_list	*tmp;
	int		y;

	y = 1;
	list_a->n = ft_atoi(tab[0]);
	while (tab[y])
	{
		tmp = malloc(sizeof(t_list));
		if (!tmp)
			return (ft_lst_clear(& list_a), NULL);
		tmp->n = ft_atoi(tab[y]);
		tmp->next = NULL;
		list_a->next = tmp;
		list_a = list_a->next;
		y++;
	}
	return (list_a);
}

void	ft_printlist(t_list *list)
{
	t_list	*tmp;
	int		n;

	n = 0;
	tmp = list;
	ft_printf("%s", "\n");
	while (tmp != NULL && n < 20)
	{
		ft_printf("%d \n", tmp->n);
		tmp = tmp->next;
		n++;
	}
}

// void	ft_printpile(t_list *list_a, t_list *list_b)
// {
// 	t_list	*a;
// 	t_list	*b;

// 	a = list_a;
// 	b = list_b;
// 	ft_printf("%s", "\n");
// 	while (a != NULL || b != NULL)
// 	{
// 		if (a != NULL)
// 		{
// 			ft_printf(".%d ", a->index);
// 			ft_printf("%d    ", a->n);
// 			a = a->next;
// 		}
// 		else
// 			ft_printf("%s	", " ");
// 		if (b != NULL)
// 		{
// 			ft_printf(".%d ", b->index);
// 			ft_printf("%d \n", b->n);
// 			b = b->next;
// 		}
// 		else
// 			ft_printf("%s\n", " ");
// 	}
// 	ft_printf("%s", "_		_");
// 	ft_printf("\n%s", "a		b\n \n");
// }
