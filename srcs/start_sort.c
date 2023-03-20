/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:23:34 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/19 22:31:58 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_three_arg(int *tab, t_list *list_a)
{
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] > tab[0])
		swap(list_a, "sa");
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
		rotate_reverse(&list_a, "rra");
	if (tab[0] > tab[1] && tab[1] > tab[2] && tab[2] < tab[0])
	{
		swap(list_a, "sa");
		rotate_reverse(&list_a, "rra");
	}
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[2] > tab[0])
	{
		swap(list_a, "sa");
		rotate(&list_a, "ra");
	}
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[2] < tab[0])
		rotate(&list_a, "ra");
	return (list_a);
}

void	*rotate_optimise(t_list *list_a, int min)
{
	int	*tab;

	tab = ft_pile_to_tab(list_a);
	if (tab[0] == min || tab[1] == min)
		rotate(&list_a, "ra");
	else
		rotate_reverse(&list_a, "rra");
	free(tab);
	return (list_a);
}

void	*ft_five_arg(t_list *list_a, t_list *list_b, int min, int min2)
{
	int	*tab;

	tab = ft_pile_to_tab(list_a);
	while (list_a->n != min)
		list_a = rotate_optimise(list_a, min);
	push(&list_a, &list_b, "pb");
	free(tab);
	tab = ft_pile_to_tab(list_a);
	while (list_a->n != min2)
		list_a = rotate_optimise(list_a, min);
	push(&list_a, &list_b, "pb");
	if (ft_lst_size(list_a) == 2 && list_a->n > list_a->next->n)
		swap(list_a, "sa");
	if (ft_lst_size(list_a) == 3)
	{
		free(tab);
		tab = ft_pile_to_tab(list_a);
		list_a = ft_three_arg(tab, list_a);
	}
	push(&list_b, &list_a, "pa");
	push(&list_b, &list_a, "pa");
	free(tab);
	return (list_a);
}

void	ft_bubble_sort(char **tab_char)
{
	int	i;
	int	n;
	int	tmp;
	int	*tab;

	tab = ft_tab_to_int(tab_char);
	if (!tab)
		return ;
	i = 0;
	n = 0;
	while (i < ft_len_tab(tab_char) - 1)
	{
		i++;
		if (tab[i] < tab[i - 1])
		{
			tmp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = tmp;
			i = 0;
			n++;
		}
	}
	if (n != 0)
		ft_sort(tab_char, ft_tab_to_int(tab_char), tab[0], tab[1]);
	free(tab);
}

void	ft_sort(char **tab_char, int *tab, int min, int min2)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = malloc(sizeof(t_list));
	if (list_a == NULL)
	{
		free(tab);
		return ;
	}
	list_b = NULL;
	if (!ft_fulfill_a(list_a, tab_char))
	{
		free(tab);
		return ;
	}
	if (ft_len_tab(tab_char) == 2)
		swap(list_a, "sa");
	if (ft_len_tab(tab_char) == 3)
		list_a = ft_three_arg(tab, list_a);
	if (ft_len_tab(tab_char) == 4 || ft_len_tab(tab_char) == 5)
		list_a = ft_five_arg(list_a, list_b, min, min2);
	if (ft_len_tab(tab_char) > 5)
		list_a = ft_median(list_a, list_b);
	ft_lst_clear(&list_a);
	free(tab);
}
