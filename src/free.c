/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:21:14 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 13:21:15 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	free_string(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av[i]);
	free(av);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while ((*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
	free(*stack);
}
