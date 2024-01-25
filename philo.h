/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:12 by lribette          #+#    #+#             */
/*   Updated: 2024/01/25 17:16:29 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "colors.h"
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philos
{
	int				num;
	long			last_meal;
	int				nb_of_times_eaten_p;
	pthread_t		thread;
	struct s_struct	*m;
}	t_philos;

typedef struct s_struct
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_times_eating;
	int				died;
	struct timeval	start;
	t_philos		*p;
	pthread_t		reaper;
	pthread_mutex_t	*forks;
	pthread_mutex_t	ate;
	pthread_mutex_t	sleeping;
	pthread_mutex_t	thinking;
	pthread_mutex_t	dying;
	pthread_mutex_t	nb_of_times_eaten;
}	t_struct;

int		ft_atoi(char *str);
long	get_time(t_struct *m);
void	*routine(void *data);
void	destroy_routine(t_struct *m);
void	manage_routine(t_struct *m);
void	*reaper_init(void *data);

#endif