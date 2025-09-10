/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_node_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:04:43 by anamedin         ###   ########.fr       */
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
