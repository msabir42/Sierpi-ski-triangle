#include "header.h"

void draw_triangle(t_object *mlx, int x, int y, int size, int color) {
    int x1 = x, y1 = y;
    int x2 = x + size, y2 = y;
    int x3 = x + size / 2, y3 = y - (int)(size * sqrt(3) / 2);

    draw_line(mlx ,x1, y1, x2, y2, color);
    draw_line(mlx,x2, y2, x3, y3, color);
    draw_line(mlx, x3, y3, x1, y1, color);
}


void spierniski(t_object *mlx, int x, int y, int size, int color, int iter) {
    if (iter == 0) {
        draw_triangle(mlx, x, y, size, color);
        return;
    }

    int new_size = size / 2;
    spierniski(mlx, x, y, new_size, color, iter - 1); 
    spierniski(mlx, x + new_size, y, new_size, color, iter - 1);  
    spierniski(mlx, x + new_size / 2, y - (int)(new_size * sqrt(3) / 2), new_size, color, iter - 1);  
}
