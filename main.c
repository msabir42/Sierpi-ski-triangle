#include "header.h"

#define HEIGHT 1080
#define WIDTH 1920

int closeit(int key, void *param)
{
    t_object *obj = (t_object *)param;
    
    if (key == XK_Escape) {
        mlx_destroy_image(obj->conn, obj->data.img);
        mlx_destroy_window(obj->conn, obj->win);
        mlx_destroy_display(obj->conn);
        exit(0);
    }
    return 0;
}

int main(int argc, char** argv)
{
    if (argc == 2) {
        char *iter_input;
        char *str;
        iter_input = argv[1];
        int iter = ft_atoi(iter_input);
        if (iter < 0){
            printf("\033[1;31mError: number of iterations must be postive!\033[0m\n");
            return (0);
        }
        int n_tr = calculate_triangles(iter);

        t_object obj;
        obj.s = "Sierpinski Triangle";
        obj.conn = mlx_init();
        obj.win = mlx_new_window(obj.conn, WIDTH, HEIGHT, "Sierpinski Triangle");
        obj.data.img = mlx_new_image(obj.conn, WIDTH, HEIGHT);
        obj.data.addr = mlx_get_data_addr(obj.data.img, &obj.data.bits_per_pixel, &obj.data.line_length, &obj.data.endian);
        
        int size = 600;
        int start_x = (WIDTH - size) / 2;
        int start_y = HEIGHT - 350;

        spierniski(&obj, start_x, start_y, size, 0xFFFFFF, iter);
        char *s = ft_itoa(n_tr);
        str = ft_strjoin("Number of triangles drawn : ", s);
        mlx_put_image_to_window(obj.conn, obj.win, obj.data.img, 0, 0);
        mlx_string_put(obj.conn, obj.win, (WIDTH / 2) - 100, HEIGHT - 300, 0xFFFFFF, str);

        mlx_key_hook(obj.win, closeit, &obj);
        mlx_loop(obj.conn);

        return 0;
    }
    else {
        printf("\033[1;31mError: Wrong usage!\033[0m\n");
        printf("\033[1;33mCorrect usage:\033[0m %s <iterations>\n", argv[0]);
        printf("Where <iterations> is a positive integer representing the fractal depth.\n");
        printf("Example: %s 5\n", argv[0]);
        return 1;
    }
}