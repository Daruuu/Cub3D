# include "testing.h"

t_parser	*g_parser;

/**
 * @brief Inicializa el entorno global antes de cada prueba.
 *
 * Prepara `g_minishell` y su lista de entorno para evitar problemas de
 * estado compartido entre pruebas.
 */
void	setUp(void)
{
	init_environment_testing();
}

/**
 * @brief Limpia los recursos utilizados después de cada prueba.
 *
 * Libera los nodos de `g_minishell->env` y la estructura global
 * para prevenir fugas de memoria.
 */
void	tearDown(void)
{
	clean_environment_testing();
}

/*
 * heap: cuando usamos malloc, calloc, realloc, strdup, etc.
 * stack o pila: cuando declaramos variables locales.
 */
int	main(void)
{
	UNITY_BEGIN();
	char *path = "../maps_and_textures/correct_maps/matrix.cub";
	char	*file_map1d;
	g_parser = init_struct_parser();
	file_map1d = read_file_content(path, count_file_size(path));
	g_parser->file_map = ft_split(file_map1d, '\n');
	extract_map_from_file_map(g_parser);

	printf("\nHERE WE ARE TESTING PARSING MAP\n");
	RUN_TEST(test_copy_map_to_new_matrix_map);

	return (UNITY_END());
}
/*
void	test_check_double_simple_dollar_case_02(void)
{
	int	i;
	int	result;

	struct s_test_int	edge_cases[] =
	{
	{"\"  '   $HOME case not work' \"", TRUE},
	{"\"    $HOME case not work ' \"", TRUE},
	{"\"  '   $HOME case not work  \"", TRUE},
	{"\"'hello world'\"", FALSE},
	{"\"$HOME'case'\"", FALSE}
	};

	i = 0;
	int	len = sizeof(edge_cases) / sizeof(edge_cases[0]);
	while (i < len)
	{
		result = check_dquote_squote_dollar_case(edge_cases[i].input);
		char	message[256];

		snprintf(message, sizeof(message), "Failed on case %d: input='%s'", i + 1, edge_cases[i].input);
		TEST_ASSERT_EQUAL_MESSAGE(edge_cases[i].expected, result, message);
//		TEST_ASSERT_EQUAL(edge_cases[i].expected, result);
		i++;
	}
}*/

/**
 * @brief Prueba la expansión de una variable válida.
 *
 * Cuando se pasa una variable válida, debe reemplazarla con el valor
 * correspondiente dentro de una cadena con comillas simples.
 * @see replace_dollar_variable_skip_s_quote
 */

/*
void	test_replace_dollar_var_when_valid_var_should_expand_correctly_version_01(void)
{
	char	*token_rm_d_quote = ft_strdup("'$USER hello world'");
	char	*expected = ft_strdup("'daruuu hello world'");
	char	*result = replace_dollar_variable_skip_s_quote(token_rm_d_quote, g_minishell->env);

	TEST_ASSERT_EQUAL_STRING(expected, result);
	free(token_rm_d_quote);
	free(expected);
	free(result);
}
*/
/*
void	test_expand_vars_with_quotes_cases(void)
{
	int		i;
	char	*result;

	struct s_test_str	matrix_cases[] =
	{
	// Entrada con comillas simples y variable válida
	{"\"   '   $USER hello world'\"", "\"   '   daruuu hello world'\""},
			// Entrada con variable inexistente
	{"\"'$NON_EXISTENT_VAR hello'\"", "\"' hello'\""},
			// Entrada con múltiples variables
	{"\"'hello $USER and $NON_EXISTENT_VAR world'\"", "\"'hello daruuu and  world'\""},
			// Entrada con repetición de variables
	{"\"'$USER$USER$USER'\"", "\"'daruuudaruuudaruuu'\""},
			// Entrada con variable SHLVL
	{"\"'$SHLVL test $NON_EXISTENT_VAR'\"", "\"'0 test '\""}
	};

	i = 0;
	int	len = sizeof(matrix_cases) / sizeof(matrix_cases[0]);
	while (i < len)
	{
		// result = replace_dollar_variable_skip_s_quote(matrix_cases[i].input, g_minishell->env);

		TEST_ASSERT_EQUAL_STRING(matrix_cases[i].expected, result);
		free(result);
		i++;
	}
}*/
/*
void	test_sumar_a_mas_b(void)
{
	int	a = 5;
	int	b = 10;
	int result;

	result = sumar_a_b(a, b);

	TEST_ASSERT_EQUAL_INT(19, result);
}*/

/*
void	test_clean_consecutives_quotes(void)
{
	int		i;
	char	*result;

	struct s_test_str	matrix_cases[] =
			{
//					// Caso 3: Combinación de comillas dobles y simples consecutivas
					{"\"\'\'hello\"", "\"\'\'hello\""},
					// Caso 1: Comillas dobles consecutivas al inicio
					{"\"\"hello0\'a\'", "hello0\'a\'"},
					// Caso 2: Comillas simples consecutivas al inicio
					{"\'\'hello", "hello"},
					// Caso 4: Comillas consecutivas al final
					{"hello\"\"", "hello"},
					// Caso 5: Comillas consecutivas en medio del texto
					{"he\"\"llo", "hello"},
					// Caso 6: Comillas simples consecutivas en medio del texto
					{"he''llo", "hello"},
					// Caso 7: Texto solo con dobles y simples consecutivas mezcladas
					{"\"''\"''", ""},
					// Caso 8: Comillas dobles y dentro comillas simples (no eliminar simples)
					{"\"\'\'hello\"", "\"\'\'hello\""},
					// Caso 9: Texto solo con comillas dobles consecutivas
					{"\"\"\"\"", ""},
					// Caso 10: Texto mixto con comillas consecutivas y palabras
					{"\"hello\"'' world\"\"", "hello world"}#1#
			};

	i = 0;
	int	len = sizeof(matrix_cases) / sizeof(matrix_cases[0]);
	char message[256];
	while (i < len)
	{

		snprintf(message, sizeof(message), "Failed on case %d: input='%s'", i + 1, matrix_cases[i].input);
		result = clean_consecutive_quotes(matrix_cases[i].input);

		TEST_ASSERT_EQUAL_STRING(matrix_cases[i].expected, result);
		free(result);
		i++;
	}
}

void	test_extract_var_name(void)
{
	struct s_test_str	t_matrix_cases[] =
	{
//			{"   $USER", "USER"},
			{"      $HOME   ", "HOME"},
			{"           $NON        ", "NON"},
//			{"$USER$NON_EXISTENT_VAR", ""},
	};

	int		i = 0;
	char	*result;
	char	message[256];
	int		len = sizeof(t_matrix_cases) / sizeof(t_matrix_cases[0]);

	while (i < len)
	{
		result = extract_var_name(t_matrix_cases[i].input);

		snprintf(message, sizeof(message), "Failed on case %d: input='%s'", i + 1, t_matrix_cases[i].input);
		TEST_ASSERT_EQUAL_STRING(t_matrix_cases[i].expected, result);
		free(result);
		i++;
	}
}
*/

/*
 * @see get_and_
 */
/*
void	test_get_and_reconstruct_token(void)
{
	struct s_test_str	t_matrix_cases[] =
			{
//			{"   $USER", "USER"},
					{"  $USER    ", "  daruuu    "},
//			{"$USER$NON_EXISTENT_VAR", ""},
			};

	int		i = 0;
	char	*result;
	char	message[256];
	int		len = sizeof(t_matrix_cases) / sizeof(t_matrix_cases[0]);

	while (i < len)
	{
		result = get_and_reconstruct_token(t_matrix_cases[i].input, "daruuu");

		snprintf(message, sizeof(message), "Failed on case %d: input='%s'", i + 1, t_matrix_cases[i].input);
		TEST_ASSERT_EQUAL_STRING(t_matrix_cases[i].expected, result);
		free(result);
		i++;
	}
}
*/

/*
void	test_has_string_before_dollar(void)
{
	struct s_test_int	t_matrix_cases[] =
	{
		// Casos que retornan TRUE
		{"hello$HOME", TRUE},       // Precedido por 'o'
		{"var$USER", TRUE},         // Precedido por 'r'
		{"my_var$PATH", TRUE},      // Precedido por 'r'

		// Casos que retornan FALSE
		{"", FALSE},                // Cadena vacía
		{NULL, FALSE},              // Cadena nula
		{"$HOME", FALSE},           // Nada antes del $
		{"123$VAR", FALSE},         // Precedido por un número
		{"!$HOME", FALSE},          // Precedido por un símbolo
		{"var!$USER", FALSE},       // Precedido por símbolo '!'
		{"hello world", FALSE},     // No hay ningún $
	};

	int		i = 0;
	int		result;
	char	message[256];
	int		len = sizeof(t_matrix_cases) / sizeof(t_matrix_cases[0]);

	while (i < len)
	{
		result = has_string_before_dollar(t_matrix_cases[i].input);

		snprintf(message, sizeof(message), "Failed on case %d: input='%s'", i + 1,
		         t_matrix_cases[i].input ? t_matrix_cases[i].input : "NULL");
		TEST_ASSERT_EQUAL_INT(t_matrix_cases[i].expected, result);
		i++;
	}
}
*/

/*
void	test_has_more_than_one_dollar_without_spaces_in_token(void)
{
	struct s_test_int	t_matrix_cases[] =
	{
		// Casos que retornan TRUE
		{"hello$HOME", TRUE},       // Precedido por 'o'
		{"var$USER", TRUE},         // Precedido por 'r'
		{"my_var$PATH", TRUE},      // Precedido por 'r'
		{"my_var$PATH$USER", TRUE},

		// Casos que retornan FALSE
		{"", FALSE},                // Cadena vacía
		{NULL, FALSE},              // Cadena nula
		{"$HOME", FALSE},           // Nada antes del $
		{"123$VAR", FALSE},         // Precedido por un número
		{"!$HOME", FALSE},          // Precedido por un símbolo
		{"var!$USER", FALSE},       // Precedido por símbolo '!'
		{"hello world", FALSE},     // No hay ningún $
	};

	int		i = 0;
	int		result;
	char	message[256];
	int		len = sizeof(t_matrix_cases) / sizeof(t_matrix_cases[0]);

	while (i < len)
	{
		result = has_more_than_one_dollar_without_spaces_in_token(t_matrix_cases[i].input);

		snprintf(message, sizeof(message), "Failed on case %d: input='%s'", i + 1,
		         t_matrix_cases[i].input ? t_matrix_cases[i].input : "NULL");
		TEST_ASSERT_EQUAL_INT(t_matrix_cases[i].expected, result);
		i++;
	}
}
*/

/**
 * @brief Prueba la detección de variables de entorno consecutivas.
 * @see has_consecutives_dollars_in_token
 *
 */

/*
void	test_has_consecutices_dollars_in_token(void)
{
	struct s_test_int	t_matrix_cases[] =
	{
		// Casos que retornan TRUE
		// {"hello$HOME", TRUE},       // Precedido por 'o'
		// {"var$USER", TRUE},         // Precedido por 'r'
		// {"my_var helllo $PATH", TRUE},      // Precedido por 'r'

		{" abcd    $PATH$HOME", TRUE},
		{"my_var$PATH$USER", TRUE},
		{"$HOME abcd $USER", TRUE},
		// {"123$VAR", TRUE},         // Precedido por un número
		{"hello world", FALSE},     // No hay ningún $
		
		{"", FALSE},                // Cadena vacía
		// Casos que retornan FALSE
		{"!$HOME", FALSE},          // Precedido por un símbolo
		{"var!$USER", FALSE},       // Precedido por símbolo '!'
	};

	int		i = 0;
	int		result;
	char	message[256];
	int		len = sizeof(t_matrix_cases) / sizeof(t_matrix_cases[0]);

	while (i < len)
	{
		t_tokens	*token = malloc(sizeof(t_tokens));
		if (t_matrix_cases[i].input)
		{
			token->str = ft_strdup(t_matrix_cases[i].input);
		}
		else
			token->str = NULL;

		result = has_consecutives_env_variables_in_token(token);

		snprintf(message, sizeof(message), "Failed on case %d: input='%s'", 
         i + 1, t_matrix_cases[i].input ? t_matrix_cases[i].input : "(NULL)");


		TEST_ASSERT_EQUAL_INT_MESSAGE(t_matrix_cases[i].expected, result, message);
		free(token->str);
		free(token);
		i ++;
	}
}
*/
/*
void	test_ft_strjoin(void)
{
	struct s_test_str_str	t_matrix_cases[] =
	{
		{"USER", "ab","USER ab"},
	};

	int		i = 0;
	char	*result;
	char	message[256];
	int		len = sizeof(t_matrix_cases) / sizeof(t_matrix_cases[0]);

	while (i < len)
	{
		result = ft_strjoin(t_matrix_cases[i].input_a, t_matrix_cases[i].input_b);

		// snprintf(message, sizeof(message), "Failed on case %d: input='%s'", i + 1, t_matrix_cases[i].input);
		TEST_ASSERT_EQUAL_STRING(t_matrix_cases[i].expected, result);
		free(result);
		i++;
	}

}
	*/

	/*
	RUN_TEST(test_clean_consecutives_quotes);
	RUN_TEST(test_extract_var_name);
	RUN_TEST(test_get_and_reconstruct_token);
	RUN_TEST(test_count_words);
	RUN_TEST(test_find_matching_quote);
	RUN_TEST(test_has_string_before_dollar);
	*/
	/*
	RUN_TEST(test_expand_vars_with_quotes_cases);
	RUN_TEST(test_check_double_simple_dollar_case_01);
	RUN_TEST(test_check_double_simple_dollar_case_02);
	RUN_TEST(test_01_remove_quotes_literals);
	RUN_TEST(test_02_remove_quotes_general);
	RUN_TEST(test_03_remove_quotes_backslash);
	RUN_TEST(test_04_remove_quotes_spaces);
	RUN_TEST(test_05_remove_quotes_no_expand);
	RUN_TEST(test_06_remove_quotes_empty_cases);
	RUN_TEST(test_sumar_a_mas_b);
	 */

//	RUN_TEST(test01_double_quotes_keyboard_basic);

	// RUN_TEST(test01_check_double_simple_dollar_case_int);

	/**
	 * @file test_double_quotes.c
	 * @brief Testing en la detección del patron: [" ' $VAR ' "]
	 * removing the double quotes and expanding the variables.
	 */
/*
	RUN_TEST(test02_remove_quotes_str_valid_basic);
	RUN_TEST(test02_remove_quotes_str_valid_special_chars);
	RUN_TEST(test02_remove_quotes_str_valid_format);
	RUN_TEST(test02_remove_quotes_str_invalid_quotes);
*/
	/**
	 * @file test_double_quotes.c
	 * @brief Testing en la detección del patron: [" ' $VAR ' "]
	 * removing the double quotes and expanding the variables.
	 */
	// RUN_TEST(test_replace_dollar_variable_skip_s_quote_01);

	/*
	RUN_TEST(test_check_dollar_with_space_in_s_quotes);

	RUN_TEST(test_handle_special_quotes);
	*/
