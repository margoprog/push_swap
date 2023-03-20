/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:02 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/17 18:57:00 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_double(char **tab)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (tab[a])
	{
		while (tab[b + a])
		{
			if (ft_atoi(tab[a]) == ft_atoi(tab[a + b]))
				return (ft_error());
			b++;
		}
		b = 1;
		a++;
	}
	return (0);
}

int	ft_check_symbol(char *str)
{
	if (!(str[1] <= '9' || str[1] >= '0'))
		return (ft_error());
	return (0);
}

char	**ft_remove_zero(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		if (tab[y][0] == '+' || tab[y][0] == '-')
		{
			if (ft_check_symbol(tab[y]))
				return (NULL);
		}
		y++;
	}
	return (tab);
}
