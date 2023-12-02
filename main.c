
#include <mlx.h>
#include "includes/fdf.h"

void init_struct(fdf *data)
{
	data->height = 0;
	data->width = 0;
	data->matrix = 0 ;

}


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	mlxClose(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(int argc ,char *argv[])
{
	fdf data;
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
			printf("-%d-",data.matrix[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	// t_vars	vars;
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// mlx_loop(vars.mlx);



}

