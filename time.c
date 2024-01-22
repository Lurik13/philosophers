/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:36:08 by lribette          #+#    #+#             */
/*   Updated: 2024/01/22 17:13:15 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_struct *m)
{
	long			first;
	long			current;
	struct timeval	current_time;

	first = m->start.tv_sec * 1000 + m->start.tv_usec / 1000;
	gettimeofday(&current_time, NULL);
	current = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (current - first);
}
