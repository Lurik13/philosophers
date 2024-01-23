/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:12 by lribette          #+#    #+#             */
/*   Updated: 2024/01/23 14:14:14 by lribette         ###   ########.fr       */
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
	pthread_t	thread;
	struct s_struct	*structure;
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
	pthread_mutex_t	*forks;
}	t_struct;

int		ft_atoi(char *str);
long	get_time(t_struct *m);
void	launch_routine(t_struct *m);

#endif