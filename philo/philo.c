/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:03:12 by pgeeser           #+#    #+#             */
/*   Updated: 2022/09/20 20:57:20 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_dead(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&(philo->eating));
	pthread_mutex_lock(&philo->maindata->finishcheck_mutex);
	time = timenow() - philo->maindata->starttime;
	if (!philo->finished && !check_death(philo->maindata, 0) && ((timenow()
				- philo->last_eat) >= (long)(philo->maindata->time_to_die)))
	{
		check_death(philo->maindata, 1);
		pthread_mutex_lock(&(philo->maindata->write_mutex));
		printf("%ld %d died\n", time, philo->id);
		pthread_mutex_unlock(&(philo->maindata->write_mutex));
	}
	pthread_mutex_unlock(&(philo->eating));
	pthread_mutex_unlock(&philo->maindata->finishcheck_mutex);
}

static void	philo_actions(t_philo *philo)
{
	pthread_mutex_lock(&(philo->maindata->forks[philo->left_fork]));
	write_thread_msg("has taken a fork", philo);
	if (philo->left_fork == philo->right_fork)
		timesleep(philo->maindata->time_to_die * 2);
	if (philo->left_fork == philo->right_fork)
		return ;
	pthread_mutex_lock(&(philo->maindata->forks[philo->right_fork]));
	write_thread_msg("has taken a fork", philo);
	write_thread_msg("is eating", philo);
	pthread_mutex_lock(&(philo->eating));
	philo->last_eat = timenow();
	philo->nb_ate++;
	pthread_mutex_unlock(&(philo->eating));
	timesleep(philo->maindata->time_to_eat);
	pthread_mutex_unlock(&(philo->maindata->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->maindata->forks[philo->right_fork]));
	write_thread_msg("is sleeping", philo);
	timesleep(philo->maindata->time_to_sleep);
	write_thread_msg("is thinking", philo);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->maindata->start)
		usleep(10);
	if (!(philo->id % 2))
		timesleep(philo->maindata->time_to_eat);
	while (!check_death(philo->maindata, 0) && !philo->finished)
	{
		philo_actions(philo);
		if (check_must_eat(philo))
			return (NULL);
	}
	return (NULL);
}
