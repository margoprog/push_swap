/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:48 by maheraul          #+#    #+#             */
/*   Updated: 2023/03/20 19:59:13 by maheraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "limits.h"
# include <stdio.h>

# define MAX 2147483647
# define MIN -2147483648

typedef struct t_list
{
	int				n;
	int				index;
	struct t_list	*next;
}					t_list;

typedef struct t_price
{
	int				daron;
	int				pos_daron;
	int				price_a;
	int				price_b;
	int				total;
}					t_price;

// typedef	struct s_list
// {
// 	int	n;
// 	struct t_list *next;
// }			t_list;

//parse.c
int					ft_good_ascii(char *argv);
int					ft_check_split(char **tab);
char				**ft_parse(char *argv);
long long int	ft_atoi_limits(const char *str);
char				**ft_parse_multp_arg(int argc, char **argv);
//utils.c
int					ft_error(void);
void				print_tab(char **tab);
void				*ft_free_tab(char **tab);
int					ft_long_limits(char *str);
int					ft_limits(char **tab);
//check_double.c
int					ft_double(char **tab);
char				*ft_strremove_zero(char *str);
char				**ft_remove_zero(char **tab);
//join.c
size_t				ft_strlen_b(const char *str);
void				ft_freejoin(char **new, char *buf);
char				*ft_strjoins(char *s1, char *s2, char *s3, int pos_s3);
//create.list.c
void				ft_printlist(t_list *list);
void				*ft_fulfill_a(t_list *list_a, char **tab);
void				ft_printpile(t_list *list_a, t_list *list_b);
//sort.c
int					ft_lst_size(t_list *lst);
void				swap(t_list *list, char *str);
void				rotate(t_list **addr_list, char *str);
void				rotate_reverse(t_list **addr_list, char *str);
void				push(t_list **addr_list, t_list **addr_list_b, char *str);
//utils_tab.c
int					ft_len_tab(char **tab);
void				*ft_tab_to_int(char **tab);
int					*ft_pile_to_tab(t_list *list);
void				print_tabint(int *tab, int size);
int					*ft_sort_tab(int *tab, int size);
//presort.c
void				ft_bubble_sort(char **tab_char);
void				*ft_three_arg(int *tab, t_list *list_a);
void				ft_sort(char **tab_char, int *tab, int min, int min2);
void				*rotate_optimise(t_list *list_a, int min);
void				*ft_five_arg(t_list *list_a, t_list *list_b, int min,
						int min2);
//median.c
t_list				*ft_median(t_list *list_a, t_list *list_b);
int					ft_find_father(int nb, int *tab, int size);
t_price				ft_faster_father(t_list *list_a, t_list **list_b,
						int size_b);
void				ft_lst_clear(t_list **lst);
t_list				*ft_move(t_list *list_a, t_list *list_b);
//to suppr
void				ft_print_pretri(int *tab);
int					find_index(t_list *addr_list, int father);
//optimise
void				ft_add_index(t_list *list_a);
int					find_index(t_list *addr_list, int father);
t_price				count_step(t_list *list_a, t_list *list_b, int pos,
						int value);

// max
int					get_min(t_list *list_a);
int					get_max(t_list *list_a);
int					find_the_real_father(t_list *list_a, int nb, int *index);
// int					find_the_real_father(t_list *list_a, int nb);

#endif