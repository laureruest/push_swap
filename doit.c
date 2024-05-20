/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:12:00 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/05/20 08:13:02 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include "libft.h"

char	*doit(t_list *a, t_list *b, int *error)
{
	char	*salida;

	salida = malloc(sizeof(char));
	if (salida)
		*salida = '\0';
	return (salida);
}
