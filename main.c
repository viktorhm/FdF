

#include "includes/fdf.h"

void init_struct(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->matrix = 0 ;
	data->zoom = 10;
	data->color =  0xffffff;
}


// typedef struct	s_mlx {
// 	void	*mlx;
// 	void	*win;
// }				t_mlx;



int	mlxClose(int keycode, t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}




int	main(int argc ,char *argv[])
{
	t_data data;

	if(argc != 2)
	{
	write(1,"erreur",6);
	return(0);
	}

	init_struct(&data);
	read_file(argv[1] , &data);

	printf("\nwidth : %d\n", data.width);
	printf("height : %d \n" , data.height);

	int i;
	int j;

	j = 0;
	while(j < data.height)
	{
		i = 0;
		while(i < data.width)
		{
			printf("%d ",data.matrix[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "FDF");
	data.img = mlx_new_image(data.mlx , 1920 , 1080);
	data.addr = mlx_get_data_addr(data.img , &data.bits_per_pixel ,&data.line_length , &data.endin );

	draw(&data);

	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 17, mlxClose, &data);
	mlx_loop(data.mlx);

	return(0);
}

