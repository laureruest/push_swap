/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:12:34 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/05/20 13:31:18 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include "doit.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static int	errorprn(int error)
{
	if (error)
		ft_putendl_fd("Error", 2);
	return (error);
}

static void	*fillst(char **param, int counter, int nparam, int *error)
{
	t_list	*nwnode;
	int		num;

	num = ft_fatoi(param[counter - 1], error);
	if (!*error)
	{
		nwnode = malloc(sizeof(t_list));
		if (nwnode)
		{
			nwnode->value = num;
			if (counter == nparam)
				nwnode->next = NULL;
			else
				nwnode->next = fillst(param, ++counter, nparam, error);
			if (*error)
			{
				free(nwnode);
				nwnode = NULL;
			}
		}
		return (nwnode);
	}
	return (NULL);
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

	cadena = doit(a, b);
	if (cadena)
	{
		ft_printf("%s", cadena);
		free(cadena);
		return ;
	}
	*error = -1;
}

int	main(int nparam, char *param[])
{
	int		error;
	int		counter;
	t_list	*a;
	t_list	*b;

	if (nparam == 1)
		return (0);
	error = 0;
	counter = 2;
	a = fillst(param, counter, nparam, &error);
	if ((!error) && (a))
	{
		b = malloc(sizeof(t_list));
		if (b)
		{
			b->value = 0;
			b->next = NULL;
			prnresult(a, b, &error);
			freestack(b);
		}
	}
	if (a)
		freestack(a);
	return (errorprn(error));
}
