#include "so_long.h"

void free_map(t_context *ctx)
{
    int i;
    
    i = 0;
    while (i < ctx->count_lines)
    {
        free(ctx->map[i]);
        free(ctx->temp_map[i]);
        i++;
    }
    free(ctx->map);
    free(ctx->temp_map);
}

// void ft_free(t_context *ctx)
// {
//     free_map(ctx->map);
//     //free(ctx);
//     exit(1);
// }

void validate_args(int argc, char **argv) 
{
    errno = 22;
    if(argc < 2)
    {
        errno = 2;
        perror("Error:\n Map not provided");
        exit(1);
    }
    if (argc != 2)
    {
        perror("Error:\n Multiple arguments");
        exit(1);
    }
    int len = ft_strlen(argv[1]);
    if (!ft_strnstr(argv[1], ".ber", len))
    {
        perror("Error:\n The map should be in '.ber' format");
        exit(EXIT_FAILURE);
    }    
}


void valid_map(t_context *ctx)
{
    errno = 22;
	if (!valid_map_len_lines(ctx))
    {
		perror("Error:\n Map is not rectangular"); // clear the map as well
        free_map(ctx);
        exit(1);
    }
	if (!valid_map_walls(ctx))
    {
		perror("Error:\n The frame is incorrect");
        free_map(ctx);
        exit(1);
    }
	if (check_exit(ctx) != 1)
    {
		perror("Error:\n There are no valid exits");
        free_map(ctx);
        exit(1);
    }
	 if (check_nr_collectables(ctx) == 0)
    {
		perror("Error:\n There are no collectables");
        free_map(ctx);
        exit(1);
    }
	//floodFill(ctx, ctx->y, ctx->x);
	// if (ctx->collectables != 0 || ctx->exit != 1)
    // {
    //     perror("Error:\n Player can not reach to the exit or all collectable.\n");
    //     exit(1);
    //}
}


// void valid_map(t_context *ctx)
// {
// 	errno = 22;
// 	if (!valid_map_len_lines(ctx))
// 		printf("Len is not equal"); // clear the map as well
// 	if (!valid_map_walls(ctx))
// 		printf("The frame is incorrect");
// 	if (check_exit(ctx) != 1)
// 		printf("There are no valid exits ");
// 	if (check_nr_collectables(ctx) == 0)
// 		printf("There are no collectables");
// 	floodFill(ctx, ctx->y, ctx->x);
// 	if (ctx->collectables != 0 || ctx->exit != 1)
//         printf("Player can not reach to the exit or all collectable.\n");
// }