/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_node_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:29:03 by cpujades          #+#    #+#             */
/*   Updated: 2025/05/31 22:30:19 by cpujades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_node.h"

void	insert_node_in_list(t_node **begin_list, t_node *prev,
		t_node *node, t_node *last)
{
	if (prev)
		prev->next = node;
	else
		*begin_list = node;
	node->next = last;
}
