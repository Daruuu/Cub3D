/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:03:25 by dasalaza          #+#    #+#             */
/*   Updated: 2025/06/04 21:29:58 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H 
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "parser.h"
# include "init.h"
# include "cub3d_utils.h"

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_assets
{
	int no;
	int so;
	int we;
	int ea;
	int f;
	int c;
}	t_assets;

typedef struct s_parser
{
	char		**file_map;		//not modify in the parsing part, extract lines
	char		**original_map;
	char		**validation_map;
	int			items_map;
	char		player;
	int			rows;
	int			columns;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	char		*ceiling;
	int			rgb_floor[3];
	int			rgb_ceil[3];
	t_position	position_player;
}	t_parser;

typedef struct s_image
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*xmp_ptr;
	int			bit_per_pixel;
	int			len_line;
}	t_image;

typedef struct s_map
{
	t_parser	*parser;
}	t_map;

typedef struct s_game
{
	t_parser	*paser;
}	t_game;

#endif
