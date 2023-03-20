/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:05:43 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/19 23:27:39 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		i++;
		if (tab[i] < tab[i - 1])
		{
			tmp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = tmp;
			i = 0;
		}
	}
	return (tab);
}

int	ft_len_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
		y++;
	return (y);
}

void	*ft_tab_to_int(char **tab)
{
	int	*tab_n;
	int	i;

	i = 0;
	tab_n = malloc(sizeof(int) * (ft_len_tab(tab) + 1));
	if (!tab_n)
		return (NULL);
	while (tab[i])
	{
		tab_n[i] = ft_atoi(tab[i]);
		i++;
	}
	tab_n[i] = '\0';
	return (tab_n);
}

void	print_tabint(int *tab, int size)
{
	int	y;

	y = 0;
	while (y < size)
	{
		ft_printf("%d\n", tab[y]);
		y++;
	}
}

int	*ft_pile_to_tab(t_list *list)
{
	t_list	*new;
	int		*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(int) * (ft_lst_size(list) + 1));
	new = list;
	while (new != NULL)
	{
		tab[i] = new->n;
		new = new->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
