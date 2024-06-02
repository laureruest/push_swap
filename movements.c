/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:58:06 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/06/02 12:10:07 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include "libft.h"

char	*movements(char *s, t_list *a, t_list *b)
{
	char	*salida;

	salida = ft_strjoin(s, "Hay que ordenarlos");
	free(s);
	s = salida;
	return (salida);
}
