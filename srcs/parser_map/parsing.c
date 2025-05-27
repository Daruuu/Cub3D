
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
	// TODO: copy the map and validate if exists a island 
	// or empty positions inside the map
	// check how manage tabs inside de file.cub ???
	print_parser_struct(parser);
}
