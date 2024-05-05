/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:12:34 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/05/05 10:32:25 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

typedef s_list	t_list;

int errorprn(void)
{
	ft_puntendl_fd("Error", 2);
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
	{
		lst->prev = NULL;
		return (0);
	}
	error = fillst(char **param, lst, --nparam);
	if (error)
		return (error);
	nwnode = malloc(1);
	if (!nwnode)
		return (-1);
	nwnode->next = lst;
	num = ft_fatoi(&param[nparam], &ovflw);
	if (ovflw)
		return (-1);
	nwnode->value = num;
// continuemos por aqui
	
}
	int	main(int nparam, char **param)
{
	int		error;
	t_list	lst;

	error = 0;
	lst = NULL;
	if (nparam == 1)
		return (0);
	error = fillst(param, lst, nparam);
	if (error)
	{
		freestack(lst);
		return (errorprn());
	}
}

		
