#include "so_long.h"

int valid_map_len_lines(t_context *ctx) // checking if the map is rectangular
{
	int i = 0, j = 0, len_line = 0;

	while (i < ctx-> count_lines)
	{
		len_line = ft_strlen(ctx->map[i]);
		j = i + 1;
		while (j < ctx->count_lines)// compare with the next line
		{
			if (len_line != ft_strlen(ctx->map[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int valid_map_walls (t_context *ctx) //checking if the walls are valid
{
	int i = 0, j = 0;
	
	while (i < ctx->count_lines)
	{
		j = 0;
		ctx->len_line = ft_strlen(ctx->map[i]);
		//printf("len line --%d\n", ctx->len_line);
		while (j < ctx->len_line )
		{
			if (ctx->map[0][j] != '1' || ctx->map[i][0] != '1' || ctx->map[i][ctx->len_line - 1] != '1' || ctx->map[ctx->count_lines -1][j] != '1')
				return (0);	
			j++;
		}
		i++;
	}
	return (1);
}