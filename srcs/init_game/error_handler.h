/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:49:08 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 03:10:57 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <stdbool.h>
# include <stdlib.h>

// Forward declaration
typedef struct s_game	t_game;

// Error handling functions
void			handle_error(t_game *game, char *error, char *trace);
void			handle_warning(t_game *c, char *error);

#endif
