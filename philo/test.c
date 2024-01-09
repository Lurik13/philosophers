/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:34:45 by lribette          #+#    #+#             */
/*   Updated: 2024/01/09 23:20:47 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

# define RESET	"\e[0m"
# define BLUE	"\x1b[38;2;74;194;255m"

void	*test(void *data)
{
	(void)data;
	pthread_t	id;
	int	*count;
	int	i;

	id = pthread_self();
	count = (int *)data;
	i = 0;
	while (i < 10000)
	{
		(*count)++;
		i++;
	}
	printf("count = %d, i = %d", *count, i);
	return (NULL);
}

int main(void)
{
	pthread_t	obi_wan;
	pthread_t	grievous;

	pthread_create(&obi_wan, NULL, test, NULL);
	pthread_create(&grievous, NULL, test, NULL);
	pthread_join(obi_wan, NULL);
	pthread_join(grievous, NULL);
	/*struct timeval	start;
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