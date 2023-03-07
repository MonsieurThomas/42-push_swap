/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:13:56 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 15:31:39 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_list
{
	int				content;
	signed long		number;
	char			name;
	int				size;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_data
{
	int				size;
	int				min;
	int				max;
	int				middle;
	int				count;
	struct s_data	*next;
	struct s_data	*previous;
}					t_data;

t_list		*ft_lstnew(int content, int len, char name);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_front_data(t_data **lst, t_data *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstdelone(t_list *lst, void (*del)(void*));
int			ft_lstclear(t_list **lst, void (*del)(void*));
int			ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void		push_swap_less_4_2nd_part(int tmp2, int tmp3,
				int *move_count, t_list **stack_a);
char		*ft_concatenate(char **av);
t_list		*ft_sort_with_split(char *str);
int			check_av(char *str);
t_list		*create_pill(char **av);
int			number_limits(char *str);
void		print_list(t_list *stack, int move_count);
void		free_stack(t_list **stack);
void		free_string(char **av);
void		swap_to_2nd(t_list **stack, int *move_count);
void		swap_top_to_top(t_list **stack1, t_list **stack2, int *move_count);
void		top_to_bottom(t_list **stack, int *move_count);
void		top_to_2nd(t_list **stack, int *move_count);
void		bottom_to_top(t_list **stack, int *move_count);
void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_isgood(t_list *stack);
void		push_swap_less_6(t_list **stack_a, int *move_count);
void		push_swap_less_4(t_list **stack_a, int *move_count);
void		sort_complex(t_list **stack_a, t_list **stack_b);
t_data		*ft_lstnew_data(void);
void		ft_mediane(t_list **stack);
void		first_sort(t_list **stack_a, t_list **stack_b, int *move_count);
void		who_is_min_and_max(t_list **stack_a, t_data *data);
void		sort_biggest(t_list **stack_a, t_list **stack_b, int *move_count);
void		sort_biggest_debug(t_list **stack_a, t_list **stack_b);
void		sort_middle(t_list **stack_a, t_list **stack_b, int *move_count);
void		sort_smallest(t_list **stack_a, t_list **stack_b, int *move_count);
void		final_move(t_list **stack_a, t_list **stack_b, int *move_count);
void		go_down_loop(t_list **stack, int max, int *move_count);
void		go_up_loop(t_list **stack, int max, int *move_count);
void		push_swap_less_6_4th_part(t_list **stack_a, int max, int min,
				int *move_count);

#endif
