/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:28:11 by anamedin          #+#    #+#             */
/*   Updated: 2025/05/04 19:05:38 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>

/* ************************************************************************** */
/*                                 MEMORY                                     */
/* ************************************************************************** */

// void			ft_bzero(void *s, size_t n);
// void			*ft_calloc(size_t count, size_t size);

/* ************************************************************************** */
/*                                 STRING                                     */
/* ************************************************************************** */

// char			*ft_itoa(int n);
// char			**ft_split(const char *s, char c);
// size_t			ft_strlen(char const *str);


/* ************************************************************************** */
/*                                 LIBFT_ALL*/
/* ************************************************************************** */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *dest, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
/*PART TWO PROJECT*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* OTHERS FUNCTIONS */
int			ft_strcmp(const char *s1, const char *s2);

/* ************************************************************************** */
/*                                 PRINTF                                     */
/* ************************************************************************** */

int				ft_printf(char const *format, ...);
int				ft_putchar(char c);
int				ft_putnbr(long n);
int				ft_print_string(char *str);
int				ft_hex(unsigned long nbr, const char str);
unsigned int	ft_unsignedint(unsigned int n);

/*---------------------------------GETNEXTLINE--------------------------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

#endif
