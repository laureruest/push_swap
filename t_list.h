/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:21:04 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/05/11 10:21:03 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;
# define T_LIST_H
#endif
