/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_node_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:45:04 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:05:05 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_NODE_HELPER_H
#define CUB_NODE_HELPER_H

typedef struct s_node	t_node;

void		insert_node_in_list(t_node **begin_list, t_node *prev,
				t_node *node, t_node *last);

#endif //CUB_NODE_HELPER_H