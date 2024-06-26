/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:22:50 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/06/02 10:06:44 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

//return maxvalue for type int
static long int	maxvalue(void)
{
	int			num_bits;
	long int	acum;

	num_bits = 8 * sizeof(int);
	acum = 1;
	while (num_bits > 1)
	{
		acum *= 2;
		num_bits--;
	}
	acum--;
	return (acum);
}

//return minvalue for type int
static long int	minvalue(void)
{
	int			num_bits;
	long int	acum;

	num_bits = 8 * sizeof(int);
	acum = 1;
	while (num_bits > 1)
	{
		acum *= 2;
		num_bits--;
	}
	acum *= -1;
	return (acum);
}

// receives str, returns pointer to last digit or NULL when there is no number
static char	*shift_to_last(char *str)
{
	char	*ptrtoret;

	ptrtoret = NULL;
	if (*str != '\0')
	{
		ptrtoret = str;
		if ((*str == '-') || (*str == '+'))
			str++;
		while ((*str != '\0') && (ptrtoret))
		{
			if (ft_isdigit(*str))
				ptrtoret = str;
			else
				ptrtoret = NULL;
			str++;
		}
	}
	return (ptrtoret);
}

// function than calculates result with sign, and return max or min if overflow
static int	result_oflw_sg(long int acum, char *lim, char *str, int *ovflw)
{
	int	toret;

	toret = 0;
	if (str >= lim)
	{
		if (*str == '-')
			acum *= -1;
	}
	if (acum < minvalue())
	{
		toret = (int)(minvalue());
		*ovflw = -1;
	}
	if (acum > maxvalue())
	{
		toret = (int)(maxvalue());
		*ovflw = -1;
	}
	if (toret == 0)
		toret = (int) acum;
	return (toret);
}

// returns an int than there is represented in the string
int	ft_fatoi(const char *str, int *overflow)
{
	unsigned int	weighpot;
	char			*cur;
	long int		a;
	char			*left_str_ptr;

	left_str_ptr = (char *)(str);
	*overflow = -1;
	cur = shift_to_last((char *)(str));
	if (!cur)
		return (0);
	a = 0;
	*overflow = 0;
	weighpot = 1;
	while ((cur >= left_str_ptr) && (a >= minvalue()) && (a <= maxvalue()))
	{
		if ((a >= minvalue()) && (a <= maxvalue()) && (ft_isdigit(*cur)))
		{
			a += (((long int)(*(cur--) - 48)) * weighpot);
			weighpot *= 10;
		}
		if (*cur == '-')
			return (result_oflw_sg(a, left_str_ptr, cur, overflow));
	}
	cur++;
	return (result_oflw_sg(a, left_str_ptr, cur, overflow));
}
