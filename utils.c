
#include "header.h"




void my_mlx_pixel_put(t_data *data, int x, int y, int color) {

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

void draw_line(t_object *mlx, int x1, int y1, int x2, int y2, int color) {
    int dx, dy, sx, sy, err, e2;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (x1 < x2) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (y1 < y2) {
        sy = 1;
    } else {
        sy = -1;
    }
    err = dx - dy;

    while (1) {
        my_mlx_pixel_put(&mlx->data, x1, y1, color);  
        if (x1 == x2 && y1 == y2)
            break;
        e2 = err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}



int calculate_triangles(int iterations) {
    return pow(3, iterations);
}


static int	get_len(int n)
{
    int len = 0;
    long num = n;
    
    if (num <= 0)
        len = 1;
    while (num != 0)
    {
        num /= 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int n)
{
    char	*str;
    int		len;
    long	num;
    
    len = get_len(n);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    
    str[len--] = '\0';
    num = n;
    
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    
    if (num == 0)
        str[0] = '0';
        
    while (num > 0)
    {
        str[len--] = (num % 10) + '0';
        num /= 10;
    }
    
    return (str);
}

int	ft_atoi(char *str)
{
	int neg;
	int num;
	int i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

static size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return len;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *result;
    size_t i;
    size_t j;
    size_t len1;
    size_t len2;
    
    if (!s1 || !s2)
        return NULL;
    
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    
    result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    if (!result)
        return NULL;
    
    i = 0;
    while (i < len1)
    {
        result[i] = s1[i];
        i++;
    }
    
    j = 0;
    while (j < len2)
    {
        result[i + j] = s2[j];
        j++;
    }
    
    result[i + j] = '\0';
    return result;
}