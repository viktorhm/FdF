

#include "includes/fdf.h"

void init_struct(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->matrix = 0 ;
	data->zoom = 20;
	data->color =  0xffffff;
	data->wx = 1000 ;
	data->wy = 500 ;
	data->controlx = 50 ;
	data->controly =50 ;
	data->angle = 0.8;
}


int	mlxClose(int keycode, t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int event(t_data *data)
{
	data->img = mlx_new_image(data->mlx , data->wx , data->wy);
	data->addr = mlx_get_data_addr(data->img , &data->bits_per_pixel ,&data->line_length , &data->endin );
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	write(1,"e",1);
}

int control(int key , t_data *data)
{
	if(key == 'w')
		data->controly -= 10;
	if(key == 'a' )//gauche
		data->controlx -= 10;
	if(key == 's' )// down
		data->controly += 10;
	if(key == 'd')//droit
		data->controlx += 10;
	if(key == '-')
		data->zoom -= 2 ;
	if(key == '=')
		data->zoom += 2 ;
	if(key == ']')
		data->angle += 1 ;
	if(key == '[')
		data->angle -= 1 ;
	if(key == 65307)
		mlx_destroy_window(data->mlx, data->win);
	else
		event(data);
	return(0);
}

int etat(t_data data)
{
	int i;
	int j;

	printf("\nwidth : %d\n", data.width);
	printf("height : %d \n" , data.height);
	printf("color min : %d , max : %d \n" , data.min , data.max);

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
}

int	main(int argc ,char *argv[])
{
	t_data data;

	if(argc != 2)
	{
	printf("erreur");
	return(0);
	}

	init_struct(&data);

	read_file(argv[1] , &data);

	etat(data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.wx, data.wy , "FDF");
	event(&data);
	mlx_hook(data.win , 2 , 1L<<0 ,control,&data );
	mlx_hook(data.win , 17 ,1L<<5 , mlxClose , &data);
	mlx_loop(data.mlx);

	printf("END ?");

	return(0);
}

