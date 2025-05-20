# include "testing.h"

void	init_environment_testing(void)
{
	extern char	**environ;

	g_parser = init_struct_parser();
	TEST_ASSERT_NOT_NULL(g_parser);
}

void	clean_environment_testing(void)
{
	free_parser_struct(g_parser);
}

