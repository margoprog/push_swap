/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:36:57 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/07 00:06:04 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	print_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		ft_printf("%s\n", tab[y]);
		y++;
	}
	ft_printf("Y =%d\n", y);
}

void	*ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_long_limits(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (!(str[i] <= '9' && str[i] > '0') && str[i])
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		i++;
		n++;
	}
	if (n > 10)
		return (1);
	return (0);
}

int	ft_limits(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		if (ft_atoi_limits(tab[y]) > MAX || ft_long_limits(tab[y]))
			return (ft_error());
		y++;
	}
	return (0);
}
