
#include "../includes/cub3d.h"

// TODO: call all the validations here about parser_file and parser_map
void    parsing(char **argv, t_parser *parser)
{
	(void) argv;
	if (!parser->file_map)
		return ;
	fill_parser_info(parser);
	extract_map_from_file_map(parser);
	if (!parser->map)
	{
		printf("Fail extract map\n");
		return ;
	}
	print_parser_struct(parser);

}
