/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:31:07 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/15 17:03:45 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*sup;

	if (lst[0])
	{
		sup = ft_lstlast(lst[0]);
		sup->next = new;
		new->next = NULL;
		new->previous = sup;
	}
	else
	{
		lst[0] = new;
		new->next = NULL;
		new->previous = NULL;
	}
}
