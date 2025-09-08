/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_reader.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:32:32 by yamir             #+#    #+#             */
/*   Updated: 2025/06/01 02:19:28 by cpujades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_LINE_READER_H
# define CUB_LINE_READER_H

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
