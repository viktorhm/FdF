

#include "../includes/fdf.h"


void init_struct(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->matrix = NULL ;
	data->zoom = 20;
	data ->bits_per_pixel = 20 ;
	data->wx = 1700 ;
	data->wy = 900 ;
	data->controlx = 50 ;
	data->controly =50 ;
	data->anglex = 0.8;
	data->angley =0.8;
	data->max = 0 ;
	data->min = 0;
}

// int free_mlx(t_data *data)
// {

// 	free(data->mlx);
// 	return (0);

// }

int	mlxClose(t_data *data)
{
	//mlx_destroy_image(data->mlx, data->img);
	//mlx_destroy_window(data->mlx, data->win);
	//mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	return (0);
}

int event(t_data *data)
{
	data->img = mlx_new_image(data->mlx , data->wx , data->wy);
	data->addr = mlx_get_data_addr(data->img , &data->bits_per_pixel ,&data->line_length , &data->endin );
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);

	return(0);
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
		data->anglex += 0.10 ;
	if(key == '[')
		data->anglex -= 0.10 ;
	if(key == ',')
		data->angley += 0.10 ;
	if(key == '.')
		data->angley -= 0.10 ;
	if(key == 65307)
		mlxClose(data);
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
	return(0);
}

int free_matrix(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->height)
		free(data->matrix[i++]);
	free(data->matrix);

return(0);
}

int	main(int argc ,char *argv[])
{
	t_data data;


	if(argc != 2)
	{
	printf("erreur\n");
	return(0);
	}

	init_struct(&data);
	read_file(argv[1] , &data);
	//etat(data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.wx, data.wy , "FDF");
	event(&data);

	mlx_hook(data.win , 2 , 1L<<0 ,control,&data);
	mlx_hook(data.win , 17 ,1L<<5 , mlxClose , &data);
	mlx_loop(data.mlx);

	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);

	free(data.mlx);
	free_matrix(&data);
	write(1,"END ?",5);

	return(0);
}