/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:22:50 by lribette          #+#    #+#             */
/*   Updated: 2024/01/24 17:41:44 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_struct *m)
{
	int		i;
	long	current;

	while (1)
	{
		i = 0;
		while (i < m->nb_of_philos)
		{
			current = get_time(m);
			pthread_mutex_lock(&m->dying);
			pthread_mutex_lock(&m->ate);
			if (current - m->p[i].last_meal > m->time_to_die)
			{
				pthread_mutex_unlock(&m->ate);
				printf("%ld %d %s%s", current, m->p[i].num, DYING, RESET);
				m->died = 1;
				pthread_mutex_unlock(&m->dying);
				return (1);
			}
			pthread_mutex_unlock(&m->ate);
			pthread_mutex_unlock(&m->dying);
			i++;
		}
	}
	return (0);
}

void	*reaper_init(void *data)
{
	t_struct	*m;

	m = (t_struct *) data;
	check_death(m);
	return (NULL);
}
