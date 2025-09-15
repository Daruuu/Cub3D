/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/XX XX:XX:XX by dasalaza          #+#    #+#             */
/*   Updated: 2025/01/XX XX:XX:XX by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ===================== SYSTEM INCLUDES ===================== //
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include "mlx/mlx.h"

// ===================== PROJECT INCLUDES ===================== //
# include "types.h"
# include "constants.h"
# include "errors.h"

// ===================== MODULE INCLUDES ===================== //
# include "modules/math.h"
# include "modules/graphics.h"
# include "modules/game.h"
# include "modules/parser.h"
# include "modules/render.h"
# include "modules/input.h"

// ===================== FUNCTION DECLARATIONS ===================== //
int		render_next_frame(t_game *game);
int		get_delay(bool startnow, int min, bool mac);
void	set_bonus(bool *bonus);

#endif // CUB3D_H
