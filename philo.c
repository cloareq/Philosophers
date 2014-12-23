#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "philo.h"

void*	startResting(void *arg)
{
	t_philo *philosophe;
	philosophe = (t_philo *)arg;
	philosophe->state = RESTING;
	philosophe->stickAvailable = TRUE;
	philosophe->hasEaten = FALSE;
	printf("Philosopher %d is resting\n", philosophe->pos + 1);
	goAction(philosophe);
	return NULL;
}

int	create_philosophes(t_philo *philosophe, int i)
{
	philosophe->pos = i;
	if (pthread_create(&(philosophe->p), NULL, startResting, philosophe) != 0)
		return (-1);
	return (0);
}

void	init_philo()
{
	int	i;

	i = 0;
	while (i < 7) {
		if (create_philosophes(&(philtab[i]), i) == -1) {
			printf("pthread_create ERROR\n");
			exit(1);
		}
		usleep(500000);
		i++;
	}
}

void	join_philo()
{
	int	i;

	i = 0;
	while (i < 7) {
		pthread_join(philtab[i].p, NULL);
		i++;
	}
}

int main()
{
	printf("%s\n", "Dinner is ready !\n-----------");
	init_chopstick();
	init_philo();
	join_philo();
	mutex_destroy();
	printf("%s\n", "-----------\nThe dinner is over.");
	return 0;
}
