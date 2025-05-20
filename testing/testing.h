/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:24 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/20 14:04:55 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H

# define UNITY_OUTPUT_COLOR
# include "unity.h"
# include "../includes/cub3d.h"


#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"

extern t_parser *g_parser;

typedef struct s_test_int
{
    char    *input;     // Entrada del caso de prueba
    int     expected;   // Resultado esperado (entero)
}   t_test_int;

typedef struct s_test_str
{
    char    *input;     // Entrada del caso de prueba
    char    *expected;  // Resultado esperado (cadena)
}   t_test_str;

typedef struct s_test_str_str
{
    char    *input_a;     // Entrada del caso de prueba
    char    *input_b;     // Entrada del caso de prueba
    char    *expected;  // Resultado esperado (cadena)
}   t_test_str_str;

// Funciones de configuración del entorno de testing
void    init_environment_testing(void);  // Inicializa el entorno para pruebas
void    clean_environment_testing(void); // Limpia el entorno de pruebas

#endif
