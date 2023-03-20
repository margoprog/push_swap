/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:35:34 by maheraul          #+#    #+#             */
/*   Updated: 2023/02/17 18:57:45 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen_b(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoins(char *s1, char *s2, char *s3, int pos_s3)
{
	size_t	tab[3];
	char	*buff;

	if (!s2)
		return (NULL);
	tab[0] = ft_strlen(s1);
	tab[1] = ft_strlen(s2);
	tab[2] = ft_strlen(s3);
	buff = ft_calloc(sizeof(char), (tab[0] + tab[1] + tab[2] + 1));
	if (!buff)
		return (NULL);
	if (pos_s3 == 0)
	{
		ft_memcpy(buff, s1, tab[0]);
		if (s3)
			ft_memcpy(buff + tab[0], s3, tab[2]);
		ft_memcpy(buff + tab[0] + tab[2], s2, tab[1]);
		return (buff);
	}
	ft_memcpy(buff, s1, tab[0]);
	ft_memcpy(buff + tab[0], s2, tab[1]);
	if (s3)
		ft_memcpy(buff + tab[0] + tab[1], s3, tab[2] + 1);
	return (buff);
}

void	ft_freejoin(char **new, char *buf)
{
	char	*temp;
	char	space[2];

	space[0] = ' ';
	space[1] = '\0';
	temp = *new;
	*new = ft_strjoin(*new, space);
	*new = ft_strjoin(*new, buf);
	if (temp)
		free(temp);
}
