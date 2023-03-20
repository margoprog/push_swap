/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:35:44 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/20 20:02:21 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long int	ft_atoi_limits(const char *str)
{
	long int	i;
	long int	total;
	long int	sign;

	i = 0;
	total = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	total *= sign;
	if (total < INT_MIN || total > INT_MAX)
		return ((long)MAX + 1);
	return (total * sign);
}

int	ft_good_ascii(char *argv)
{
	int	i;

	i = 0;
	if (ft_strlen(argv) == 0)
		return (ft_error());
	while (argv[i])
	{
		if (argv[i] == ' ')
		{
			i++;
			if (i == ft_strlen(argv))
				return (ft_error());
		}
		else
			break ;
	}
	while (argv[i])
	{
		if ((!(argv[i] <= '9' && argv[i] >= '0') && argv[i] != ' '
				&& argv[i] != '-' && argv[i] != '+'))
			return (ft_error());
		i++;
	}
	return (0);
}

int	ft_check_split(char **tab)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (tab[y])
	{
		if (tab[y][x] == '-' || tab[y][x] == '+')
			x++;
		if (!tab[y][x])
			return (ft_error());
		while (tab[y][x])
		{
			if (tab[y][x] == '-' || tab[y][x] == '+')
				return (ft_error());
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

char	**ft_parse_multp_arg(int argc, char **argv)
{
	int		i;
	char	*new;
	char	*tmp;
	char	**tab;

	i = 1;
	tmp = NULL;
	new = NULL;
	while (i < argc)
	{
		if (ft_good_ascii(argv[i]))
			return (free(new), NULL);
		tmp = new;
		new = ft_strjoins(new, argv[i], " ", 0);
		free(tmp);
		i++;
	}
	tab = ft_parse(new);
	if (!tab)
		return (free(new), NULL);
	free(new);
	return (tab);
}

char	**ft_parse(char *argv)
{
	char	**tab;

	if (ft_good_ascii(argv))
		return (NULL);
	tab = ft_split(argv, ' ');
	if (ft_check_split(tab) || ft_limits(tab) || !ft_remove_zero(tab)
		|| ft_double(tab))
	{
		ft_free_tab(tab);
		return (NULL);
	}
	return (tab);
}
