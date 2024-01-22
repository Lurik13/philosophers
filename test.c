/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:34:45 by lribette          #+#    #+#             */
/*   Updated: 2024/01/22 13:38:27 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

# define RESET	"\e[0m"
# define BLUE	"\x1b[38;2;74;194;255m"

typedef struct s_counter
{
	pthread_mutex_t	count_mutex;
	int				count;
}	t_counter;

void	*test(void *data)
{
	pthread_t	id;
	t_counter	*count;
	int	i;

	id = pthread_self();
	count = (t_counter *)data;
	i = 0;
	while (i < 10000)
	{
		pthread_mutex_lock(&count->count_mutex);
		count->count++;
		i++;
		pthread_mutex_unlock(&count->count_mutex);
	}
	pthread_mutex_lock(&count->count_mutex);
	printf("[%ld]count = %d, i = %d\n", id, count->count, i);
	pthread_mutex_unlock(&count->count_mutex);
	return (NULL);
}

int main(void)
{
	pthread_t	obi_wan;
	pthread_t	grievous;
	t_counter	count;

	count.count = 0;
	pthread_mutex_init(&count.count_mutex, NULL);
	pthread_create(&obi_wan, NULL, test, &count);
	pthread_create(&grievous, NULL, test, &count);
	pthread_join(obi_wan, NULL);
	pthread_join(grievous, NULL);
	pthread_mutex_destroy(&count.count_mutex);
	struct timeval	start;
	struct timeval	end;
	long long	diff;
	gettimeofday(&start, NULL);
	loop();
	gettimeofday(&end, NULL);
	diff = (end.tv_usec - start.tv_usec) * 1000; // pour le vrai calcul : / 1000
	printf("Time : %lld", diff);*/

	/*char	str[5] = "salut";
	memset(str, 'o', 4);
	printf("%s", str);*/
}