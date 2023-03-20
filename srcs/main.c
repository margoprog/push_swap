/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:21:36 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/19 21:46:35 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**tab;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tab = ft_parse(argv[1]);
		if (!tab)
			return (0);
	}
	if (argc > 2)
	{
		tab = ft_parse_multp_arg(argc, argv);
		if (!tab)
			return (0);
	}
	ft_bubble_sort(tab);
	ft_free_tab(tab);
	return (0);
}
