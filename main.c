/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:44:51 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/06 16:20:17 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


void player_position(t_context *ctx);
int map_lines(char **argv, t_context *ctx);

void	ft_putnr(char c)
{
	write(1, &c, 1);
}

int close_window(t_context *ctx)
{
	mlx_loop_end(ctx->mlx);
	return (0);
}

int deal_key(int key, t_context *ctx)
{
	printf("%d\n", key);
	if (key == XK_Escape)
	{
		mlx_destroy_image(ctx->mlx, ctx->img_cat);
		mlx_destroy_image(ctx->mlx, ctx->img_empty);
		mlx_destroy_window(ctx->mlx, ctx->win);
		mlx_destroy_display(ctx->mlx);
		free(ctx->mlx);
		exit(1);
	}
	if(key == XK_Up)
	{
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_empty, ctx->x, ctx->y);
		ctx-> y -= 32;
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_cat, ctx->x, ctx->y);
	}
	if(key == XK_Left)
	{
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_empty, ctx->x, ctx->y);
		ctx-> x -= 32;
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_cat, ctx->x, ctx->y);
	}
	if(key == XK_Down)
	{
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_empty, ctx->x, ctx->y);
		ctx-> y += 32;
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_cat, ctx->x, ctx->y);
	}
	if(key == XK_Right)
	{
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_empty, ctx->x, ctx->y);
		ctx-> x += 32;
		mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img_cat, ctx->x, ctx->y);
	}
	return (0);
}

void init(char **argv, t_context *ctx)
{
	ctx->mlx = NULL;
	ctx->win = NULL;
	ctx->x = 0;
	ctx->y = 0;
	ctx->len_line = 0;
	ctx->count_lines = 0;
	ctx->relative_path = "./cat/idle.xpm";
	ctx->path_empty = "./cat/empty.xpm";
	ctx->collectables = 0;
	ctx->exit = 0;
	// ctx->path_devil = "./cat/devil.xpm";
	// ctx->path_coin = "./cat/coin.xpm";
	// ctx->path_exit = "./cat/exit.xpm";
	// ctx->path_wall = "./cat/wall.xpm";
	//map_lines(argv, ctx);
	
	//ctx->img_empty = mlx_xpm_file_to_image(ctx->mlx, ctx->path_empty, &ctx->img_width, &ctx->img_height);// ading empty img to a tile
}
// check if there is a map and allocate the memory for the maps
int map_lines(char **argv, t_context *ctx)//too many lines
{
	int i;
	char  *line = NULL;

	i = -1;
	ctx->fd = open(argv[1], O_RDONLY);
	if (ctx->fd == -1)
		exit(1);
	while (1)
	{
		line = get_next_line(ctx->fd);
		if (line == NULL)
			break ;
		ctx->count_lines++;
		free(line);
	}
	close(ctx->fd);
	if (ctx->count_lines > 0)
	{
		ctx->map = (char**)malloc((sizeof(char*) * ctx->count_lines));
		ctx->temp_map = (char**)malloc((sizeof(char*) * ctx->count_lines));
		ctx->fd = open(argv[1], O_RDONLY);
		while(++i < ctx->count_lines)
		{
			ctx->map[i] = get_next_line(ctx->fd);
			ctx->temp_map[i] = (char *)malloc(1 + (sizeof(char) * ft_strlen(ctx->map[i])));
			ft_strcpy(ctx->temp_map[i], ctx->map[i]);
		}
		close(ctx->fd);
		return (ctx->count_lines);
	}
	return (0);
}

// int valid_map_len_lines(t_context *ctx) // checking if the map is rectangular
// {
// 	int i = 0, j = 0, len_line = 0;

// 	while (i < ctx-> count_lines)
// 	{
// 		len_line = ft_strlen(ctx->map[i]);
// 		j = i + 1;
// 		while (j < ctx->count_lines)// compare with the next line
// 		{
// 			if (len_line != ft_strlen(ctx->map[j]))
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int valid_map_walls (t_context *ctx) //checking if the walls are valid
// {
// 	int i = 0, j = 0;
	
// 	while (i < ctx->count_lines)
// 	{
// 		j = 0;
// 		ctx->len_line = ft_strlen(ctx->map[i]);
// 		//printf("len line --%d\n", ctx->len_line);
// 		while (j < ctx->len_line )
// 		{
// 			if (ctx->map[0][j] != '1' || ctx->map[i][0] != '1' || ctx->map[i][ctx->len_line - 1] != '1' || ctx->map[ctx->count_lines -1][j] != '1')
// 				return (0);	
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }
void player_position(t_context *ctx)
{
	int **position = NULL;
	int i = 0, j = 0;
	int counter_player = 0;
	
	while (i < ctx->count_lines)
	{
		j = 0;
		ctx->len_line = ft_strlen(ctx->map[i]);
		while (j < ctx->len_line )
		{
			if (ctx->map[i][j] == 'P')
			{
				ctx->y = i; //i * 32;
				printf("%d ", ctx->y);
				ctx->x = j; //j * 32;
				printf("%d\n", ctx->x);
			}
			j++;
		}
		i++;
	}
	//return (0);
}


int main(int argc, char **argv)
{
	t_context ctx;

	validate_args(argc, argv);
	init(argv, &ctx);
	if (argc == 2)
	{
		map_lines(argv, &ctx);//allocate memory both matrics
		valid_map(&ctx);
	}

	// player_position(&ctx);
	
	//int i = -1;
	//printf(" ------------------  \n");
	// while(++i <= ctx.count_lines)
	// {
	// 	printf("%s\n", ctx.temp_map[i]);
	// }
	// printf("nr of collectables are: %d\n", ctx.collectables);



		// fd = open(argv[1], O_RDONLY);
		// if (fd == -1)
		// 	exit(1);
		// while (1)
		// {
		// 	int j = 0;
		// 	line = get_next_line(fd);
		// 	if (line == NULL)
		// 		break ;
			

	// ctx.mlx = mlx_init();
	// if (ctx.mlx == NULL)
	// 	return (-1);
	// ctx.win = mlx_new_window(ctx.mlx, 640, 640, "Hi So_long");// creating the window
	// if (ctx.win == NULL)
	// 	return (free(ctx.mlx), -1);

	// ctx.img_cat = mlx_xpm_file_to_image(ctx.mlx, ctx.relative_path, &ctx.img_width, &ctx.img_height);// ading the player img to a tile
	// mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.img_cat, ctx.x, ctx.y); // adding the player in a specific place
	
	// ctx.img_empty = mlx_xpm_file_to_image(ctx.mlx, ctx.path_empty, &ctx.img_width, &ctx.img_height);// ading empty img to a tile
	
	// mlx_hook(ctx.win, 17, 1L << 0, close_window, &ctx);//closing window from x

	// mlx_key_hook(ctx.win, deal_key, &ctx); // moving the player on map
	
	// mlx_loop(ctx.mlx);

	// mlx_destroy_window(ctx.mlx, ctx.win);
	// mlx_destroy_display(ctx.mlx);
	// free(ctx.mlx); 
	//}
	return (1);
}
