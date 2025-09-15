/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:48:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 23:42:45 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

# include <stdlib.h>

// String manipulation functions
int				stringlen(char *string);
void			truncate_str(char *s);
int				bad_strncmp(const char *s1, const char *s2, size_t n);

#endif
