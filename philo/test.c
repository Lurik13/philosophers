/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:34:45 by lribette          #+#    #+#             */
/*   Updated: 2024/01/09 19:08:29 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void	loop(void)
{
	int	i;

	i = 0;
	while (i < 1000)
		i++;
}

int main(void)
{
	struct timeval	start;
	struct timeval	end;
	long long	diff;
	
	gettimeofday(&start, NULL);
	loop();
	gettimeofday(&end, NULL);
	diff = (end.tv_usec - start.tv_usec) * 1000; // pour le vrai calcul : / 1000
	printf("Time : %lld", diff);
	/*char	str[5] = "salut";
	memset(str, 'o', 4);
	printf("%s", str);*/
}