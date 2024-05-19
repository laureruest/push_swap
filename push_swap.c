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

#include "t_list.h"
#include "doit.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
static int	errorprn(void)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}

static void	fillst(t_list *a, char **param, int counter, int nparam, int *error)
{
	t_list	*nwnode;
	int		num;

	num = ft_fatoi(param[counter - 1], error);
	if (!*error)
	{
		a->value = num;
		if (counter == nparam)
			a->next = NULL;
		else
		{
			nwnode = malloc(sizeof(t_list));
			if (nwnode)
			{
				a->next = nwnode;
				fillst(nwnode, param, ++counter, nparam, error);
			}
			else
				a->next = nwnode;
		}
	}
	else
		a->next = NULL;
}

static void	freestack(t_list *ptr)
{
	if (ptr)
	{
		if (ptr->next)
			freestack(ptr->next);
		free(ptr);
	}
}

static void	prnresult(t_list *a, t_list *b, int *error)
{
	char	*cadena;
	
	cadena = doit(a, b, error);
	if (cadena)
	{
		ft_printf("%s", cadena);
		free(cadena);
	}
}

int	main(int nparam, char *param[])
{
	int		error;
	int		counter;
	t_list		*a;
	t_list		*b;

	if (nparam == 1)
		return (0);
	error = 0;
	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if ((a) && (b))
	{
		b->next = NULL;
		counter = 2;
		fillst(a, param, counter, nparam, &error);
		if (error)
			{
				freestack(a);
				freestack(b);
				return (errorprn());
			}
		prnresult(a, b, &error);
		freestack(a);
		freestack(b);
		if (!error)
			return (0);
	}
	return (errorprn());
}
