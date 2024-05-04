/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitohex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:18:18 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/14 20:38:38 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

static int	my_pow(unsigned long long int b, int exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (b);
	exp--;
	return (b * my_pow(b, exp));
}

static char	conv_dig(unsigned long long int n, int wg)
{
	int	dig;

	dig = n / (my_pow(16, wg));
	if (dig < 10)
		dig += '0' - '\0';
	if (dig > 9)
		dig += 'a' - '\0' - 10;
	return (dig);
}

// redim ptr data size & fill string
static void	ins(char *ptr, unsigned long long int n, size_t cursor, int exp)
{
	ptr[cursor] = conv_dig(n, exp);
	cursor++;
	if (exp == 0)
	{
		ptr[cursor] = '\0';
		return ;
	}
	n %= my_pow(16, exp);
	exp--;
	ins(ptr, n, cursor, exp);
}

// compute the more significave's exponent for base_10 of ABS(n)
static int	c_wg(unsigned long long int n, int exp)
{
	if (n < 16)
		return (exp);
	exp++;
	return (c_wg(n / 16, exp));
}

// put sing, count the size of work (calculatin wg, weight of digit more sig)
// and starts
char	*ft_ullitohex(unsigned long long int n)
{
	int	wg;
	char	*tor;
	size_t	l;

	wg = c_wg(n, 0);
	l = ((size_t) wg) + 4;
	tor = malloc(l);
	if (tor != NULL)
	{
		tor[0] = '0';
		tor[1] = 'x';
		l = 2;
		ins(tor, n, l, wg);
	}
	return (tor);
}
