/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 05:34:53 by aabduvak          #+#    #+#             */
/*   Updated: 2022/03/06 04:59:24 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	error(t_stack *stack)
{
	ft_printf("Error\n");
	free_stack(stack);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

void	free_char(char **str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(str[i++]);
	free(str);
}
