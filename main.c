/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:37:55 by lribette          #+#    #+#             */
/*   Updated: 2024/01/10 18:10:48 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start(t_philosophers *philos)
{
	int	i;

	i = 0;
	philos->philos = malloc(philos->nb_of_philos * sizeof(int));
	if (!philos->philos)
		return (0);
	while (i < philos->nb_of_philos)
	{
		philos->philos[i] = i + 1;
		i++;
	}
	return (1);
}

int	ft_error(t_philosophers *philos)
{
	if (philos->nb_of_philos < 0)
	{
		printf("You have to put at least one philo\n");
		return (1);
	}
	if (!philos->nb_of_philos || philos->time_to_die < 60)
	else if (philos->time_to_eat < 60 || philos->time_to_sleep < 60)
	else if (philos->nb_of_time_eating == 0)
	return (0);
}

void	init_structure(t_philosophers *philos, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (i == 1)
			philos->nb_of_philos = ft_atoi(argv[1]);
		if (i == 2)
			philos->time_to_die = ft_atoi(argv[2]);
		if (i == 3)
			philos->time_to_eat = ft_atoi(argv[3]);
		if (i == 4)
			philos->time_to_sleep = ft_atoi(argv[4]);
		if (i == 5 && argv[5])
			philos->nb_of_time_eating = ft_atoi(argv[5]);
		i++;
	}
	ft_error(philos);
}

int	main(int argc, char **argv)
{
	t_philosophers	philos;
	int	i;

	i = 0;
	if (!(argc == 5 || argc == 6))
		printf("Wrong number of arguments\n");
	else
	{
		init_structure(&philos, argv);
		if (!ft_error(&philos))
			ft_start(&philos);
		/*int	i = 0;
		while (i < philos.nb_of_philos)
		{
			printf("%d\n", philos.philos[i]);
			i++;
		}*/
	}
}
