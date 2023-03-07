/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isgood.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:21:43 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 13:22:02 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	ft_isgood(t_list *stack)
{
	int	i;

	if (stack)
	{
		i = (stack)->content;
		while ((stack) != NULL)
		{
			if ((stack)->content > i)
				i = (stack)->content;
			if ((stack)->content < i)
				return (0);
			stack = (stack)->next;
		}
		return (1);
	}
	return (0);
}
