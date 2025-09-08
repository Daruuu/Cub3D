/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/08 14:48:10 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:30:10 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 19:49:15 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_cleaner.h"
#include "../mlx/mlx.h"

void	destroy_img(t_vars *vars, t_img *img)
{
	if (img->img)
	{
		mlx_destroy_image(vars->mlx, img->img);
		img->img = NULL;
	}
}

void	clean_images(t_vars *vars)
{
	destroy_img(vars, &(vars->walls.north));
	destroy_img(vars, &(vars->walls.south));
	destroy_img(vars, &(vars->walls.west));
	destroy_img(vars, &(vars->walls.east));
	destroy_img(vars, &(vars->floor));
	destroy_img(vars, &(vars->portal));
	destroy_img(vars, &(vars->skybox));
	destroy_img(vars, &(vars->gun));
	destroy_img(vars, &(vars->dash));
	destroy_img(vars, &(vars->sprite_img));
	destroy_img(vars, &(vars->health_img));
	destroy_img(vars, &(vars->goomba_img));
	destroy_img(vars, &(vars->door_img));
	destroy_img(vars, &(vars->img));
	destroy_img(vars, &(vars->blur.dest));
	destroy_img(vars, &(vars->blur.temp));
	empty_sprites(&(vars->sprites));
}

void	clean_all(t_vars *vars)
{
	clean_images(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (LINUX)
		mlx_destroy_display(vars->mlx);
	clear_map(&(vars->map));
	clear_sounds(&(vars->sounds));
	free_file(&vars->file);
	if (vars->depth)
		free(vars->depth);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->last_path)
		free(vars->last_path);
}

void	clean_and_exit(int code, t_vars *vars)
{
	clean_all(vars);
	vars = NULL;
	exit(code);
}

int	clean_and_exit_z(t_vars *vars)
{
	clean_and_exit(0, vars);
	return (0);
}
