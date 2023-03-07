/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:19:00 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 16:25:54 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

t_list	*ft_sort_with_split(char *str)
{
	t_list	*stack;
	char	**av;
	int		i;

	av = ft_split(str, ' ');
	i = -1;
	while (av[++i])
	{
		if (!number_limits(av[i]) || !check_av(str))
		{
			write(1, "Error\n", 6);
			free_string(av);
			return (0);
		}
	}
	stack = create_pill(av);
	free_string(av);
	return (stack);
}

int	check_doublon(t_list *stack)
{
	t_list	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		while (tmp)
		{
			if (tmp != stack)
			{
				if (tmp->content == stack->content)
				{
					write(1, "Error\n", 6);
					free_stack(&stack);
					return (0);
				}
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

t_list	*create_pill(char **av)
{
	t_list	*stack;
	int		i;
	int		len;

	len = 0;
	stack = 0;
	i = 0;
	while (av[len])
		len++;
	while (av[i])
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i]), len, 'a'));
		i++;
	}
	if (!check_doublon(stack))
		return (0);
	return (stack);
}

int	number_limits(char *str)
{
	long int	i;
	long int	neg;
	long int	result;

	i = 0;
	neg = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
			result = result * 10 + ((str[i] - '0'));
		i++;
	}
	if ((result > 2147483647 && neg == 1) || (result > 2147483648
			&& neg == -1))
		return (0);
	return (1);
}

int	check_av(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-' && str[i] > 33)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (str[i] == '-' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
