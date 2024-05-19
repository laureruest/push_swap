/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:12:34 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/05/19 15:26:36 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errorprn(void)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}

void	fillst(t_list *a, char **param, int counter, int nparam, int *error)
{
	t_list	*nwnode;
	int		num;

	num = ft_fatoi(param[counter - 1], error);
	if (!error)
	{
		nwnode = malloc(sizeof(t_list));
		if (nwnode)
		{
			if (counter == nparam)
			{
				a->next = NULL;
				return;
			}
			a->value = num;
			a->next = nwnode;
			fillst(nwnode, param, ++counter, nparam, error);
			return;
		}
	}
}

void	freestack(t_list *ptr)
{
	if (ptr)
	{
		if (ptr->next)
			freestack(ptr->next);
		free(ptr);
	}
}

void	prnresult(t_list *lst)
{
	int	num;

	if (lst)
	{
		ft_printf("%s", "Value: ");
		ft_printf("%i \n", lst->value);
		if (lst->next)
			prnresult(lst->next);
	}
}

int	main(int nparam, char *param[])
{
	int		error;
	int		counter;
	t_list	*a;

//	ft_printf("Numero parametros: %d", nparam);
//	ft_printf("%c", '\n');
	if (nparam == 1)
		return (0);
	a = malloc(sizeof(t_list));
	if (a)
	{
		counter = 2;
		fillst(a, param, counter, nparam, &error);
		if (error)
			{
				freestack(a);
				return (errorprn());
			}
		prnresult(a);
		freestack(a);
		return (0);
	}
	return (errorprn());
}
