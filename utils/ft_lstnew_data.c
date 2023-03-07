/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:27:25 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/12 17:50:49 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

t_data	*ft_lstnew_data(void)
{
	t_data	*elem;

	elem = malloc(sizeof(t_data));
	if (!elem)
		return (0);
	elem->next = NULL;
	elem->previous = NULL;
	return (elem);
}
