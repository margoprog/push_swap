/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:22:48 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/19 21:17:29 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lst_size(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	swap(t_list *list, char *str)
{
	int	tmp;

	if (list == NULL || list->next == NULL)
		return ;
	tmp = list->n;
	list->n = list->next->n;
	list->next->n = tmp;
	if (ft_strlen(str) > 0)
		ft_printf("%s\n", str);
	return ;
}

void	rotate(t_list **addr_list, char *str)
{
	t_list	*list;
	t_list	*first;

	list = *addr_list;
	if (ft_strlen(str) > 0)
		ft_printf("%s\n", str);
	if (list == NULL || list->next == NULL)
		return ;
	first = list;
	*addr_list = list->next;
	while (list->next)
		list = list->next;
	list->next = first;
	list = list->next;
	list->next = NULL;
	return ;
}

void	rotate_reverse(t_list **addr_list, char *str)
{
	t_list	*list;
	t_list	*last;
	t_list	*first;

	if (ft_strlen(str) > 0)
		ft_printf("%s\n", str);
	list = *addr_list;
	first = list;
	if (list == NULL || list->next == NULL)
		return ;
	while (list->next->next)
		list = list->next;
	last = list->next;
	list->next = NULL;
	*addr_list = last;
	last->next = first;
	return ;
}

void	push(t_list **addr_list, t_list **addr_list_b, char *str)
{
	t_list	*first;
	t_list	*list;
	t_list	*list_b;

	if (ft_strlen(str) > 0)
		ft_printf("%s\n", str);
	list_b = *addr_list_b;
	list = *addr_list;
	if (list == NULL)
		return ;
	first = list;
	if (list->next == NULL)
		*addr_list = NULL;
	else
		*addr_list = list->next;
	first->next = *addr_list_b;
	*addr_list_b = first;
	return ;
}
