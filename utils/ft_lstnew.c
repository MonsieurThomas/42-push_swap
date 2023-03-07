/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:27:25 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/13 18:07:59 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

t_list	*ft_lstnew(int content, int len, char name)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->content = content;
	elem->size = len;
	elem->number = 0;
	elem->name = name;
	elem->next = NULL;
	return (elem);
}
