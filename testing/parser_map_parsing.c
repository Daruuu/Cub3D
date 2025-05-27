# include "testing.h"

/*
* ✅ Estructura de un test unitario (AAA pattern: Arrange, Act, Assert)
* Arrange (Preparar)
	* Inicializas los datos y estructuras necesarias.
	* Configuras el entorno del test.
	* Estableces valores esperados.
* Act (Actuar)
	* Llamas a la función que estás testeando.
* Assert (Afirmar)
	* Verificas que los resultados coincidan con lo esperado.
*/
void	test_copy_map_to_new_matrix_map(void)
{
	// Arrange
	char	**result_matrix = NULL;

	// Act
	result_matrix = duplicate_map_matrix(g_parser);

	// Assert
	TEST_ASSERT_NOT_NULL(result_matrix);
	TEST_ASSERT_NOT_NULL(result_matrix[0]);

	// Comprobamos que las líneas son iguales (mínimo con una)
	// TEST_ASSERT_EQUAL_STRING(g_parser->map[0], result_matrix[0]);
	// TEST_ASSERT_EQUAL_STRING(g_parser->map[1], result_matrix[1]);

	// Libera memoria si corresponde
	// free_matrix(result_matrix);
}
