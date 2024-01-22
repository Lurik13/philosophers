/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:37:55 by lribette          #+#    #+#             */
/*   Updated: 2024/01/22 16:32:03 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start(t_struct *main)
{
	int	i;

	i = 0;
	main->philos = malloc(main->nb_of_philos * sizeof(t_philos));
	if (!main->philos)
		return (0);
	while (i < main->nb_of_philos)
	{
		main->philos[i].num = i + 1;
		/*printf("[%ld] ", get_time(main));
		if (i % 6 == 0)
			printf("%s", RED);
		if (i % 6 == 1)
			printf("%s", ORANGE);
		if (i % 6 == 2)
			printf("%s", YELLOW);
		if (i % 6 == 3)
			printf("%s", GREEN);
		if (i % 6 == 4)
			printf("%s", BLUE);
		if (i % 6 == 5)
			printf("%s", PURPLE);
		printf("%d%s", main->philos[i].num, RESET);
		if (i % 3 == 0)
			printf("%s", EATING);
		if (i % 3 == 1)
			printf("%s", SLEEPING);
		if (i % 3 == 2)
			printf("%s", THINKING);
		usleep(100);*/
		i++;
	}
	return (1);
}

int	ft_error(t_struct *main, int argc)
{
	if (!main->nb_of_philos || main->nb_of_philos > 200)
		printf("%sWrong number of philosophers%s\n", RED_ERROR, RESET);
	else if (!main->time_to_die)
		printf("%sWrong time to die%s\n", RED_ERROR, RESET);
	else if (!main->time_to_eat)
		printf("%sWrong time to eat%s\n", RED_ERROR, RESET);
	else if (!main->time_to_sleep)
		printf("%sWrong time to sleep%s\n", RED_ERROR, RESET);
	else if (argc == 6 && !main->nb_of_time_eating)
		printf("%sWrong number of times eating%s\n", RED_ERROR, RESET);
	else
		return (0);
	return (1);
}

void	init_params(t_struct *main, char **argv)
{
	main->nb_of_philos = ft_atoi(argv[1]);
	main->time_to_die = ft_atoi(argv[2]);
	main->time_to_eat = ft_atoi(argv[3]);
	main->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		main->nb_of_time_eating = ft_atoi(argv[5]);
	gettimeofday(&main->start, NULL);
	//printf("time = %ld", main->start.tv_sec * 1000 + main->start.tv_usec / 1000);
}

int	main(int argc, char **argv)
{
	t_struct	main;
	int	i;

	i = 0;
	if (!(argc == 5 || argc == 6))
		printf("Wrong number of arguments\n");
	else
	{
		init_params(&main, argv);
		if (!ft_error(&main, argc))
			ft_start(&main);
		/*int	i = 0;
		while (i < philos.nb_of_philos)
		{
			printf("%d\n", philos.philos[i]);
			i++;
		}*/
	}
}
