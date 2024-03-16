#include "so_long.h"

int check_nr_collectables(t_context *ctx)
{
    int i;
    int j;

    i = 0;
    while (i < ctx->count_lines)
    {
        j = 0;
        while(j < ctx->len_line)
        {
            if (ctx->map[i][j] == 'C')
                ++ctx->collectables;
            ++j;
        }
        ++i;
    }
    return (ctx->collectables);
}
int check_exit(t_context *ctx)
{
    int i;
    int j;
    int exit;

    i = 0;
    exit = 0;
    while (i < ctx->count_lines)
    {
        j = 0;
        while(j < ctx->len_line)
        {
            if ( ctx->map[i][j] == 'E')
                ++exit;
            ++j;
        }
        ++i;
    }
    return (exit);
}


// Function to check if a cell is valid
static bool isValid(t_context *ctx, int row, int col)
{
    return (row >= 0 && row  < ctx->count_lines && col >= 0 && col < ctx->len_line && ctx->temp_map[row][col] != '1');
}

// Flood fill algorithm
bool floodFill(t_context *ctx, int row, int col)
{
    int i = 0;
    int exit = 0;
    int dirRow[4] = {-1, 0, 1, 0};
	int dirCol[4] = {0, 1, 0, -1};

    if (ctx->temp_map[row][col]== 'E')
    {
        //printf("Found the exit\n");
        ctx->exit++;
    }
    if (ctx->temp_map[row][col] == 'C')
    {
        ctx->collectables--;
        printf("nr of collectables are: %d\n", ctx->collectables);
        // if (ctx->collectables == 0 && exit == 1)
        //     return true;
    }
    

    ctx->temp_map[row][col] = 'V'; // visited
    //Recursively checking neighboring cells
    while (i < 4)
    {
        int newRow = row + dirRow[i];
        int newCol = col + dirCol[i];
        if (isValid(ctx, newRow, newCol) && ctx->temp_map[newRow][newCol] != 'V')
        {
             if (floodFill(ctx, newRow, newCol))
                return true;
        }
        i++;
   } 
    return false;     
}

