/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:48:28 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 01:42:18 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_FILE_MAP_H
# define CHECK_FILE_MAP_H

# include <stdbool.h>
# include "string_utils.h"

// File validation and operations
bool			check_iscub(char *file);
void			*make_closedmap(int size);

#endif
