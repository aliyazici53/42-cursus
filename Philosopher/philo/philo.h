/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:34:04 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 16:35:17 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

/* ************************* DEFINES ************************** */

# define MIN_ARGS			4
# define MAX_ARGS			5

# define HAS_TAKEN_A_FORK	"has taken a fork"
# define IS_EATING			"is eating"
# define IS_SLEEPING		"is sleeping"
# define IS_THINKING		"is thinking"
# define HAS_DIED			"died"

/* ************************* STRUCT ************************** */

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	TAKING,
	INITIAL,
}	t_state;

typedef struct s_philo
{
	size_t			id; //philo id numarası
	pthread_t		thread; //philo thread numarası
	pthread_mutex_t	*lfork; //philo sol çatal, mutex'li
	pthread_mutex_t	*rfork; //philo sağ çatali mutex'li 
	pthread_mutex_t	*last_eat_check; //philo en son yeme kontrolü
	pthread_mutex_t	*n_eat_check; //philo kaç tane yemek yedi
	size_t			last_eat; //son yeme
	int				n_eat; //kaç tane yedi
	t_state			state; //yeme, uyuma, düşünme, ölme, alma, yoksa başlatma mı?
	pthread_mutex_t	*state_check; //hangi state'te
	struct s_table	*table; 
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	*forks; //masadaki çatallar
	t_philo			*philo; //masadaki filozoflar
	int				count; //filozof adedi

	size_t			time_to_sleep; //uyuma süresi
	size_t			time_to_eat; //yeme süresi
	size_t			time_to_die; //ölme süresi
	int				min_to_eat; //minimum yemesi gereken sayı
	int				death; //ölü mü değil mi

	struct timeval	time; //sec, milisec
	pthread_mutex_t	*death_check; //ölü var mı yok mu
	pthread_mutex_t	is_diying; //ölüyor mu?
	pthread_mutex_t	is_printing; //yazıyor mu?
}	t_table;

/* ************************* LIBFT FUNCTIONS ************************** */

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);

/* ************************* ARG CHECKER ************************** */

int				check_negative(const char *str);
int				check_int(const char *str);
int				check_args(int argc, char **argv);

/* ************************* PARSE ************************** */

t_table			*parse_args(int argc, char **argv);

/* ************************* PRINT ************************** */

int				print_error(char *where, char *message, int error_code);
void			print(t_philo *philo, char *message);

/* ************************* TIME ************************** */

struct timeval	time_get_now(void);
size_t			time_get_millis(struct timeval time);
size_t			time_get_millis_now(void);
size_t			time_get_millis_from_start(t_table *table);
void			time_usleep(size_t	usec);

/* ************************* PHILO ************************** */

void			philo_init(t_philo *philo, t_table *table, int id);
void			philo_forks_init(t_philo *philo, t_table *table, int id);
void			*philo_routine(void *data);
void			threads_start(t_table *table);
void			threads_wait(t_table *table);

/* ************************ PHILO  CHECKER************************** */

size_t			philo_check_eat(t_table *table);
void			philo_check_death(t_table *table);

/* ************************* PHILO ACTIONS ************************** */

void			philo_use_fork(t_philo *philo,
					int (*mutex_action)(), char *message);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

/* ************************* GET ************************** */

int				get_death_value(t_table *table);
t_state			get_state(t_philo *philo);
size_t			get_last_meal(t_philo *philo);
int				get_n_eat(t_philo *philo);

/* ************************* SET ************************** */

void			set_death_value(t_table *table, int value);
void			set_n_eat(t_philo *philo, int value);
void			set_last_meal(t_philo *philo, size_t value);
void			set_state(t_philo *philo, t_state value);

#endif