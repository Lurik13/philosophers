/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:49:54 by lribette          #+#    #+#             */
/*   Updated: 2024/01/10 18:04:09 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	
	i = 0;
	number = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		number = number * 10 + str[i] - 48;
		i++;
	}
	return (number);
}
