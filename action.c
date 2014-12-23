#include <unistd.h>
#include <stdio.h>
#include "philo.h"

void	tableFirst(t_philo *philosophe, int n)
{
	if (philtab[6].state == RESTING
		&& philtab[0].stickAvailable == TRUE) {
		pthread_mutex_lock(&chopstick[n]);
		pthread_mutex_lock(&chopstick[6]);
		philtab[6].stickAvailable = FALSE;
		philtab[n].stickAvailable = FALSE;
		philtab[n].state = EATING;
		printf("Philosopher %d is eating ---> miam miam\n", n + 1);
		sleep(2);
		philtab[6].stickAvailable = TRUE;
		philtab[n].stickAvailable = TRUE;
		philtab[n].hasEaten = TRUE;
		philtab[n].state = RESTING;
		pthread_mutex_unlock(&chopstick[n]);
		pthread_mutex_unlock(&chopstick[6]);
	} else if (philtab[6].state != RESTING
		&& philtab[0].stickAvailable == TRUE) {
		pthread_mutex_lock(&chopstick[n]);
		philtab[n].stickAvailable = FALSE;
		philtab[n].state = THINKING;
		printf("Philosopher %d is thinking\n", n + 1);
		sleep(2);
		philtab[n].stickAvailable = TRUE;
		pthread_mutex_unlock(&chopstick[n]);
		goAction(philosophe);
	}
}

void	tableLast(t_philo *philosophe, int n)
{
	if (philtab[0].state == RESTING
		&& philtab[6].stickAvailable == TRUE) {
		pthread_mutex_lock(&chopstick[n]);
		pthread_mutex_lock(&chopstick[0]);
		philtab[0].stickAvailable = FALSE;
		philtab[n].stickAvailable = FALSE;
		philtab[n].state = EATING;
		printf("Philosopher %d is eating ---> miam miam\n", n + 1);
		sleep(2);
		philtab[0].stickAvailable = TRUE;
		philtab[n].stickAvailable = TRUE;
		philtab[n].hasEaten = TRUE;
		philtab[n].state = RESTING;
		pthread_mutex_unlock(&chopstick[n]);
		pthread_mutex_unlock(&chopstick[0]);
	} else if (philtab[0].state != RESTING
		&& philtab[6].stickAvailable == TRUE) {
		pthread_mutex_lock(&chopstick[n]);
		philtab[n].stickAvailable = FALSE;
		philtab[n].state = THINKING;
		printf("Philosopher %d is thinking\n", n + 1);
		sleep(2);
		philtab[n].stickAvailable = TRUE;
		pthread_mutex_unlock(&chopstick[n]);
		goAction(philosophe);
	}
}

void	boutDeTable(t_philo *philosophe, int n)
{
	if (n == 0) {
		tableFirst(philosophe, n);
	} else {
		tableLast(philosophe, n);
	}
}

void	tableMiddle(t_philo *philosophe, int n)
{
	if (philtab[n - 1].state == RESTING
		&& philtab[n].stickAvailable == TRUE) {
		pthread_mutex_lock(&chopstick[n]);
		pthread_mutex_lock(&chopstick[n - 1]);
		philtab[n - 1].stickAvailable = FALSE;
		philtab[n].stickAvailable = FALSE;
		philtab[n].state = EATING;
		printf("Philosopher %d is eating ---> miam miam\n", n + 1);
		sleep(2);
		philtab[n - 1].stickAvailable = TRUE;
		philtab[n].stickAvailable = TRUE;
		philtab[n].hasEaten = TRUE;
		philtab[n].state = RESTING;
		pthread_mutex_unlock(&chopstick[n]);
		pthread_mutex_unlock(&chopstick[n - 1]);
	} else if (philtab[n - 1].state != RESTING
		&& philtab[n].stickAvailable == TRUE) {
		pthread_mutex_lock(&chopstick[n]);
		philtab[n].stickAvailable = FALSE;
		philtab[n].state = THINKING;
		printf("Philosopher %d is thinking\n", n + 1);
		sleep(2);
		philtab[n].stickAvailable = TRUE;
		pthread_mutex_unlock(&chopstick[n]);
		goAction(philosophe);
	}
}

void	goAction(t_philo *philosophe)
{
	int	n;

	n = philosophe->pos;
	if (philosophe->hasEaten == FALSE) {
		if (n >= 1 && n <= 5) {
			tableMiddle(philosophe, n);
		} else if (n == 0 || n == 6) {
			boutDeTable(philosophe, n);
		}
	}
}
