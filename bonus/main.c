/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:28:27 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/20 20:52:52 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*gnl(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	buffer[10000];

	i = 0;
	rd = 0;
	rd = read(fd, &character, 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, 1);
	}
	if (i == 0)
		return (NULL);
	if ((!buffer[i - 1] && !rd) || rd == -1)
		return (NULL);
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}

void	ft_lst_clear(t_list **lst)
{
	t_list	*temp;
	t_list	*copylst;

	if ((*lst) == NULL)
		return ;
	copylst = (*lst);
	while (copylst)
	{
		temp = copylst->next;
		free(copylst);
		copylst = temp;
	}
	(*lst) = NULL;
}

int	ft_is_it_sort(int *sort, t_list *list_a)
{
	int		size;
	t_list	*temp;
	int		i;

	temp = list_a;
	i = 0;
	size = ft_lst_size(list_a);
	while (size != i)
	{
		if (list_a->n != sort[i])
			return (ft_lst_clear(&temp), 0);
		i++;
		list_a = list_a->next;
	}
	ft_lst_clear(&temp);
	return (1);
}

// int	ft_is_it_sort(int *sort, t_list **list_a)
// {
// 	int		size;
// 	t_list	**temp;
// 	int		i;

// 	temp = list_a;
// 	i = 0;
// 	size = ft_lst_size(*list_a);
// 	//ft_printpile(*list_a, *list_a);
// 	while (size != i)
// 	{
// 		if ((*list_a)->n != sort[i])
// 			return (ft_lst_clear(temp), 0);
// 		i++;
// 		*list_a = (*list_a)->next;
// 	}
// 	ft_lst_clear(temp);
// 	return (1);
// }

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
	ft_checker(tab);
	return (0);
}

int	ft_checker(char **tab)
{
	t_list	*list_a;
	int		*sort;

	list_a = ft_fill_a(tab);
	if (list_a == NULL)
		return (0);
	sort = ft_sort_a(tab);
	ft_free_tab(tab);
	if (!sort)
		return (0);
	if (ft_is_it_sort(sort, list_a))
	{
		free(sort);
		return (ft_printf("OK\n"));
	}
	free(sort);
	return (ft_printf("KO\n"));
}

// int	main(int argc, char **argv)
// {
// 	char	**tab;
// 	int		*sort;
// 	t_list	*list_a;

// 	if (argc < 2)
// 		return (0);
// 	if (argc == 2)
// 	{
// 		tab = ft_parse(argv[1]);
// 		if (!tab)
// 			return (0);
// 	}
// 	if (argc > 2)
// 	{
// 		tab = ft_parse_multp_arg(argc, argv);
// 		if (!tab)
// 			return (0);
// 	}
// 	list_a = ft_fill_a(tab);
// 	if (list_a == NULL)
// 		return (0);
// 	sort = ft_sort_a(tab);
// 	ft_free_tab(tab);
// 	if (!sort)
// 		return (0);
// 	if (ft_is_it_sort(sort, list_a))
// 	{
// 		free(sort);
// 		return (ft_printf("OK\n"));
// 	}
// 	free(sort);
// 	return (ft_printf("KO\n"));
// }
