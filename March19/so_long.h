#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "lib/libft.h"
# include <stdbool.h>
# include <errno.h>
# include "get_next_line.h"

typedef struct s_context
{
	void *mlx;
	void *win;
	void *img_cat;
	void *img_empty;
	void *img_devil;
	void *img_coin;
	void *img_wall;
	void *img_exit;
	int img_width;
	int img_height;
	char	*relative_path;
	char	*path_empty;
	char 	*path_devil;
	char 	*path_coin;
	char	*path_wall;
	char	*path_exit;
	int keyhook;
	int x;
	int y;
	int collectables;
	int exit;

	int fd;
	char *line;
	char **map;
	char **temp_map;
	int len_line;
	int count_lines;
} t_context;


void	ft_strcpy(char *dst, char *src);
void	validate_args(int argc, char **argv);
int		map_lines(char **argv, t_context *ctx);
int		valid_map_len_lines(t_context *ctx);
int		valid_map_walls (t_context *ctx);
int		check_nr_collectables(t_context *ctx);
int		check_exit(t_context *ctx);
//int		check_player(t_context *ctx);
void	valid_map(t_context *ctx);

bool	floodFill(t_context *ctx, int row, int col);
void	collectables_or_exit_in_reach(t_context *ctx);
//int		ft_strlen(char *str);


//void ft_error(int argc, char **argv);


void	ft_putnr(char c);
int 	close_window(t_context *ctx);
int 	deal_key(int key, t_context *ctx);
void	init(char **argv, t_context *ctx);


void	player_position(t_context *ctx);
void	ft_free(t_context *ctx);


#endif