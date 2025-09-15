/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:18:55 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 01:33:37 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_FILE_H
# define LOAD_FILE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_line
{
	char			*line;
	int				size;
	struct s_line	*next;
}					t_line;

char	*ft_strcat(char *str, char c, int size);
int		load_file(char *path, t_line **first, int size);
void	free_file(t_line **first);
int		add_line(t_line **line, char *data, int size);
int		free_ret(char *buf, t_line **first);

int		init_file_reading(char *path, char **buf);
int		process_character(char c, char **buf, int *size, t_line **first);
int		finalize_reading(char *buf, t_line **first, int size);

#endif
