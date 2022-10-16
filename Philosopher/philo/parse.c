/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 01:17:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 16:42:47 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*parse_args(int argc, char **argv)
{
	t_table	*table;

	if (!check_args(argc, argv)) //int, negatif, sayı mı?
		return (NULL);
	table = (t_table *) malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->count = ft_atoi(argv[1]); //kaç tane philosopher var
	table->time_to_die = ft_atoi(argv[2]); //bu kadar süre yemek yemezse philo ölür
	table->time_to_eat = ft_atoi(argv[3]); //bir philo bu kadar sürede yemek yer
	table->time_to_sleep = ft_atoi(argv[4]); //bir philo bu kadar süre uyur
	if (argc - 1 == 5)
		table->min_to_eat = ft_atoi(argv[5]); //bir philo eğer dahilse en az yemesi gereken yemek.
	else
		table->min_to_eat = -1;
	table->death = 0; //masada ölü varsa 1 olucak.
	table->philo = malloc(sizeof(t_philo) * (table->count + 1)); //dinamik bellekten şu kadar philo ayır.
	table->forks = malloc(sizeof(pthread_mutex_t) * (table->count + 1)); //dinamik bellekten şu kadar çatal ayır.
	table->time = time_get_now(); //1970'ten beri gelen saniye ve milisaniyeler
	table->death_check = malloc(sizeof(pthread_mutex_t)); //philo öldü mü check'i
	pthread_mutex_init(&table->is_diying, NULL);
	pthread_mutex_init(&table->is_printing, NULL);
	pthread_mutex_init(table->death_check, NULL);
	return (table);
}
