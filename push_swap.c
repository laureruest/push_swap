/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:12:34 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/05/19 11:05:22 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errorprn(void)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}

t_list	*fillst(char **param, t_list *lst, int nparam, int *error)
{
	t_list		*nwnode;
	long int	num;

	nwnode = NULL;
	if (nparam == 1)
		return (nwnode);
	lst = fillst(param, lst, --nparam, error);
	num = ft_fatoi(param[nparam], error);
	if (*error)
		return (nwnode);
	nwnode = malloc(sizeof(t_list));
	if (!nwnode)
	{
		*error = -1;
		return (nwnode);
	}
	nwnode->next = lst;
	nwnode->value = num;
	return (nwnode);
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
	if (lst)
	{
		ft_printf("%s", "Value: ");
		ft_printf("%i", lst->value);
		if (lst->next)
			prnresult(lst->next);
	}
}

int	main(int nparam, char **param)
{
	int		*error;
	t_list	*a;

	if (nparam == 1)
		return (0);
	error = malloc(sizeof(int));
	if (error)
	{
		*error = 0;
		a = NULL;
		a = fillst(param, a, nparam, error);
		if (*error)
		{
			freestack(a);
			return (errorprn());
		}
		prnresult(a);
		freestack(a);
		free(error);
		return (0);
	}
	return (-1);
}
