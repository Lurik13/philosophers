/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:36:08 by lribette          #+#    #+#             */
/*   Updated: 2024/01/22 15:53:45 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_struct *main)
{
	long	first;
	long	current;
	struct timeval	current_time;

	first = main->start.tv_sec * 1000 + main->start.tv_usec / 1000;
	gettimeofday(&current_time, NULL);
	current = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (current - first);
}