/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:12:00 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/05/20 13:26:57 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include "libft.h"

static void	*work(char *s, t_list *a, t_list *b)
{
	int		longit;
	char	*rets;

	rets = ft_strjoin(s, "Preparado para empezar el meollo");
	free(s);
	s = rets;
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
