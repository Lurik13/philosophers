/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:12 by lribette          #+#    #+#             */
/*   Updated: 2024/01/23 20:49:25 by lribette         ###   ########.fr       */
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
	int			num;
	long		last_meal;
	pthread_t	thread;
	struct s_struct	*m;
}	t_philos;

typedef struct s_struct
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_time_eating;
	struct timeval	start;
	t_philos		*p;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	sleeping;
	pthread_mutex_t	thinking;
}	t_struct;

int		ft_atoi(char *str);
long	get_time(t_struct *m);
void	launch_routine(t_struct *m);

#endif