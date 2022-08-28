/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 06:46:52 by aabduvak          #+#    #+#             */
/*   Updated: 2022/03/06 10:26:10 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ft_create_stack(int size)
{
	t_stack	*stack;

	if (size < 0)
		return (NULL);
	stack = (t_stack *) malloc(sizeof(t_stack));
	stack->a = malloc(sizeof(int) * (size));
	stack->b = malloc(sizeof(int) * (size)); //size + 1 sildin.
	stack->a_len = 0;
	stack->b_len = 0;
	return (stack);
}

void	init_stack(t_stack *stack, char *res)
{
	int		counter;
	char	**str;
	int		i;

	counter = ft_count_words(res, ' ');
	str = ft_split(res, ' ');
	if (!check_args(counter, str))
	{
		free(res);
		error(stack);
	}
	i = 0;
	while (i < counter)
	{
		stack->a[stack->a_len++] = new_atoi(str[counter - i - 1], stack);
		free(str[counter - i - 1]);
		i++;
	}
	free(res);
	free(str);
}
