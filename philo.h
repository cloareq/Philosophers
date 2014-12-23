#ifndef PHILO_H__
#define PHILO_H__

#include <pthread.h>

#define TRUE 1
#define FALSE 0
typedef int bool;

typedef enum etat
{
	RESTING,
	THINKING,
	EATING
}t_etat;

typedef struct s_philo
{
	pthread_t p;
	bool	hasEaten;
	bool	stickAvailable;
	t_etat	state;
	int		pos;
} t_philo;

t_philo 		philtab[7];
pthread_mutex_t chopstick[7];

void	goAction(t_philo *);
void	boutDeTable(t_philo *philosophe, int n);
void	tableFirst(t_philo *philosophe, int n);
void	tableLast(t_philo *philosophe, int n);
void	tableMiddle(t_philo *philosophe, int n);
void	init_chopstick();
void	mutex_destroy();

#endif
