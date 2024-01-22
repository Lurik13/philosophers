/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:49:54 by lribette          #+#    #+#             */
/*   Updated: 2024/01/22 17:12:38 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int			i;
	long long	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		number = number * 10 + str[i] - 48;
		if (number > 2147483647 || number < -2147483648)
			return (0);
		i++;
	}
	return ((int)number);
}
