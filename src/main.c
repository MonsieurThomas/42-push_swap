/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:11:12 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 16:23:49 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	push_swap_choice(t_list **stack_a, t_list **stack_b, int *move_count)
{
	if ((*stack_a)->size < 4)
	{
		push_swap_less_4(stack_a, move_count);
		return ;
	}
	if ((*stack_a)->size < 6)
	{
		push_swap_less_6(stack_a, move_count);
		return ;
	}
	else
	{
		first_sort(stack_a, stack_b, move_count);
		if (ft_isgood(*stack_a))
			return ;
		sort_biggest(stack_a, stack_b, move_count);
		sort_middle(stack_a, stack_b, move_count);
		sort_smallest(stack_a, stack_b, move_count);
		final_move(stack_a, stack_b, move_count);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		move_count;
	int		i;
	char	*str;

	move_count = 0;
	stack_b = NULL;
	i = -1;
	if (ac < 2)
		return (0);
	av = av + 1;
	str = ft_concatenate(av);
	if (!check_av(str))
		return (0);
	stack_a = ft_sort_with_split(str);
	free (str);
	if (!stack_a)
		return (0);
	ft_mediane(&stack_a);
	push_swap_choice(&stack_a, &stack_b, &move_count);
}
