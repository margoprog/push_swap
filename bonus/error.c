/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:39:40 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/20 20:19:03 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_error_2(t_list **list_a, t_list **list_b, char **tab)
{
	write(2, "Error\n", 6);
	ft_lst_clear(list_a);
	ft_lst_clear(list_b);
	ft_free_tab(tab);
	get_next_line(0, 1);
	exit(1);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
