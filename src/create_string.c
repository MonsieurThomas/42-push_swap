/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:16:47 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/16 13:16:48 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static char	*ft_concatenate_str(char **av, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			str[k] = av[i][j];
			k++;
			j++;
		}
		str[k] = ' ';
		k++;
		i++;
	}
	str[k - 1] = '\0';
	return (str);
}

char	*ft_concatenate(char **av)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			k++;
			j++;
		}
		k++;
		i++;
	}
	str = malloc(sizeof(char) * k + 1);
	str = ft_concatenate_str(av, str);
	return (str);
}
