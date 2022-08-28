/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:02:45 by aabduvak          #+#    #+#             */
/*   Updated: 2022/03/06 03:03:38 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_dup(int *lst, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (j != i && lst[i] == lst[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int		i;
	char	*arg;

	i = 1;
	while (i < argc)
	{
		arg = argv[i++];
		while (*arg)
		{
			if (!ft_isdigit((int)*arg) && *arg != '-')
				return (0);
			arg++;
		}
	}
	return (1);
}

int	new_atoi(const char *str, t_stack *stack)
{
	long long int	ret;
	int				sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		ret = ret * 10 + ((*str) - '0') * sign;
		if (ret > 2147483647 || ret < -2147483648)
			error(stack);
		str++;
	}
	return (ret);
}

int	get_index(int *lst, int len, int num)
{
	int	i;

	i = 0;
	while (i < len)
		if (lst[i++] == num)
			return (i - 1);
	return (-1);
}
