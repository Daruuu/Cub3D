/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:30:50 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:30:50 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ERROR_H
# define CUB_ERROR_H

# include "../cub3D.h"
# include "cub_cleaner.h"

void	handle_error(t_vars *vars, char *error, char *trace);
void	handle_warning(t_vars *vars, char *error);

#endif
