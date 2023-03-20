/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:47:54 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/20 20:15:23 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_the_move_is_2(t_list **list_a, t_list **list_b, char *action,
		char **tab)
{
	if (ft_strcmp(action, "rrr\n") == 0)
	{
		rotate_reverse(list_a, "");
		rotate_reverse(list_b, "");
	}
	else if (ft_strcmp(action, "rr\n") == 0)
	{
		rotate(list_a, "");
		rotate(list_b, "");
	}
	else
	{
		free(action);
		ft_error_2(list_a, list_b, tab);
	}
}

void	ft_the_move_is(t_list **list_a, t_list **list_b, char *action,
		char **tab)
{
	if (ft_strcmp(action, "pb\n") == 0)
		push(list_a, list_b, "");
	else if (ft_strcmp(action, "pa\n") == 0)
		push(list_b, list_a, "");
	else if (ft_strcmp(action, "ra\n") == 0)
		rotate(list_a, "");
	else if (ft_strcmp(action, "rb\n") == 0)
		rotate(list_b, "");
	else if (ft_strcmp(action, "rra\n") == 0)
		rotate_reverse(list_a, "");
	else if (ft_strcmp(action, "rrb\n") == 0)
		rotate_reverse(list_b, "");
	else if (ft_strcmp(action, "sa\n") == 0)
		swap(*list_a, "");
	else if (ft_strcmp(action, "sb\n") == 0)
		swap(*list_b, "");
	else
		ft_the_move_is_2(list_a, list_b, action, tab);
	return ;
}

void	ft_make_a_move(t_list **list_a, t_list **list_b, char **tab)
{
	char	*action;

	while (1)
	{
		action = get_next_line(0, 0);
		if (!action)
			break ;
		ft_the_move_is(list_a, list_b, action, tab);
		free(action);
	}
	get_next_line(0, 1);
	return ;
}

void	*ft_fill_a(char **tab)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = malloc(sizeof(t_list));
	if (list_a == NULL)
		return (NULL);
	list_b = NULL;
	if (!ft_fulfill_a(list_a, tab))
		return (NULL);
	ft_make_a_move(&list_a, &list_b, tab);
	return (list_a);
}

int	*ft_sort_a(char **tab_char)
{
	int	i;
	int	tmp;
	int	*tab;

	tab = ft_tab_to_int(tab_char);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ft_len_tab(tab_char) - 1)
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
