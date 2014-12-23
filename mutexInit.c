#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

void	init_chopstick()
{
	int	i;

	i = 0;
	while (i < 7) {
		if ((pthread_mutex_init(&chopstick[i], NULL)) == -1) {
			printf("Mutex initialization failed\n");
			exit(1);
		}
		i++;
	}
}

void	mutex_destroy()
{
	int	i;

	i = 0;
	while (i < 7) {
		if ((pthread_mutex_destroy(&chopstick[i])) != 0) {
			printf("\n Mutex Destroyed \n");
			exit(1);
		}
		i++;
	}
}
