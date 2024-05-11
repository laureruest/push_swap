/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:12:34 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/05/11 11:46:43 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errorprn(void)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}

int	fillst(char **param, t_list *lst, int nparam)
{
	t_list		*nwnode;
	int			error;
	int			ovflw;
	long int	num;

	error = 0;
	ovflw = 0;
	if (nparam == 1)
		return (0);
	error = fillst(param, lst, --nparam);
	if (error)
		return (error);
	nwnode = malloc(1);
	if (!nwnode)
		return (-1);
	nwnode.next = lst;
	num = ft_fatoi(param[nparam], &ovflw);
	if (ovflw)
		return (-1);
	nwnode.value = num;
	lst = nwnode;
	return (0);
}

void	freestack(t_list *ptr)
{
	if (ptr->next)
		freestack(ptr->next);
	free(ptr);
}

void	prnresult(t_list *lst)
{
	ft_printf("%i", lst->value);
	if (lst->next)
		prnresult(lst->next);
}

int	main(int nparam, char **param)
{
	int		error;
	t_list	*a;

	error = 0;
	a = NULL;
	if (nparam == 1)
		return (0);
	error = fillst(param, a, nparam);
	if (error)
	{
		freestack(a);
		return (errorprn());
	}
	prnresult(a);
}
