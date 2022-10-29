/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:49:27 by                   #+#    #+#             */
/*   Updated: 2022/10/29 11:57:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	ft_init_cub3d(t_engine *engine);

int	main(int argc, char **argv)
{
	t_engine	cub3d;

	ft_init_cub3d(&cub3d);
	if (argc != 2)
		return (ft_error_arguments());
	cub3d.screen = ft_read_input_map(argv[1]);
	ft_engine_init(&cub3d);
	cub3d.file = (char *) malloc(ft_strlen(argv[1]) + 1);
	if (!cub3d.file)
		return (ft_error_malloc("main", "cub.file", ft_strlen(argv[1]) + 1));
	ft_copy(cub3d.file, argv[1], 0);
	mlx_hook(cub3d.window, 17, 0, &ft_engine_destroy, &cub3d);
	mlx_hook(cub3d.window, 2, (1L << 0), &ft_key, &cub3d);
	mlx_loop_hook(cub3d.mlx, &ft_render_frame, &cub3d);
	mlx_loop(cub3d.mlx);
}

static void	ft_init_cub3d(t_engine *engine)
{
	engine->mlx = NULL;
	engine->window = NULL;
	ft_memset((void *) &engine->img0, '\0', sizeof(engine->img0));
	ft_memset((void *) &engine->img1, '\0', sizeof(engine->img1));
	ft_memset((void *) &engine->no_tex, '\0', sizeof(engine->no_tex));
	ft_memset((void *) &engine->so_tex, '\0', sizeof(engine->so_tex));
	ft_memset((void *) &engine->we_tex, '\0', sizeof(engine->we_tex));
	ft_memset((void *) &engine->ea_tex, '\0', sizeof(engine->ea_tex));
	engine->img = NULL;
	engine->file = NULL;
	engine->screen = NULL;
	engine->offset.x = 0;
	engine->offset.y = 0;
	engine->max_line_h = 640;
	engine->max_rays = (int)(FOV / STEP_ANGLE);
	engine->max_line_w = (engine->max_rays * 2) - 1;
}
