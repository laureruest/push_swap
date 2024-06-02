/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:12:00 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/06/02 12:10:01 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include "movements.h"
#include <stdlib.h>

static int	ordered(t_list *a, t_list *b)
{
	int	num;
	int	toret;

	if (b)
		return (0);
	if (!(a->next))
		return (1);
	toret = ((a->value) < ((a->next)->value));
	if (toret)
		toret = (toret && ordered(a->next, b));
	return (toret);
}

static void	*work(char *s, t_list *a, t_list *b)
{
	char	*rets;

	if (!ordered(a, b))
		s = movements(s, a, b);
	return (s);
}

static int	tlst(t_list *a, int num)
{
	if (a == NULL)
		return (-1);
	if (a->value != num)
		return (tlst(a->next, num));
	return (0);
}

static int	l_is_correct(t_list *a)
{
	int	num;
	int	boolean;

	num = a->value;
	if (a->next)
		boolean = (l_is_correct(a->next));
	else
		boolean = 1;
	return (tlst(a->next, num) && (boolean));
}

char	*doit(t_list *a, t_list *b)
{
	char	*salida;

	salida = malloc(1);
	if ((!l_is_correct(a)) || (!salida))
	{
		if (salida)
			free(salida);
		return (NULL);
	}
	*salida = '\0';
	salida = work(salida, a, b);
	return (salida);
}
