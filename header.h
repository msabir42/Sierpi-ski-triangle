#include "mlx/mlx.h"
#include<stdio.h>
#include<unistd.h>
#include <X11/keysym.h>
#include <stdlib.h> 
#include <math.h>

#ifndef HEIGHT
#define HEIGHT 1080
#endif

#ifndef WIDTH
#define WIDTH 1920
#endif


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;



typedef struct s_object {
    char* s;
	void *conn;
    void *win;
	t_data data;
} t_object;


void 	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void 	draw_line(t_object *mlx, int x1, int y1, int x2, int y2, int color) ;
void 	draw_triangle(t_object *mlx, int x, int y, int size, int color) ;
void 	draw_square(t_object *obj,int ax,int ay,int bx, int by,int cx,int cy,int dx,int dy);
void 	spierniski(t_object *mlx, int x, int y, int size, int color, int iter);
char*	ft_itoa(int n);
int 	calculate_triangles(int iterations);
int		ft_atoi(char *str);
char *ft_strjoin(char const *s1, char const *s2);
