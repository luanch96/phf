/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luissanchez <luissanchez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:47:16 by luisanch          #+#    #+#             */
/*   Updated: 2024/08/22 18:26:10 by luissanchez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void think(t_philo *philo)
{
    print_text("is thinking", philo, philo->id);
}


void dream(t_philo *philo)
{
    print_text("is sleeping", philo, philo->id);
    ft_usleep(philo->time_to_sleep);
    return ;
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print_text("has taken fork", philo, philo->id);
    if(philo->num_philosophers == 1)
    {
        ft_usleep(philo->time_to_die);
        pthread_mutex_unlock(philo->right_fork);
        return ;
    }
    pthread_mutex_lock(philo->left_fork);
    print_text("has taken a fork", philo, philo->id);
    philo->eaters = TRUE;
    print_text("Philosopher is eating", philo, philo->id);
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = get_time();
    philo->meals++;
    pthread_mutex_unlock(philo->meal_lock);
    ft_usleep(philo->time_to_eat);
    philo->eaters = FALSE;
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    return ;
}

    