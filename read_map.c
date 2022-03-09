#include "so_long.h"

char	**read_map(t_game *game, char *path)
{
	int		fd;
	char	*line;
	char	*keep_map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	keep_map = ft_strdup("");
	line = get_next_line(fd);
	if (!line || *line != '1')
	{
		ft_printf("invalid map!!");
		exit(0);
	}
	else
		keep_map = ft_strjoin(keep_map, line);
	while ((line = get_next_line(fd)))
	{
		keep_map = ft_strjoin(keep_map, line);
		free(line);
	}
	return (game->map = map_allo(game, keep_map), free(keep_map), close(fd), game->map);
}

void map_printer(t_game *game)
{
	int i;

	i = 0;
	while (game->map[i])
	{
		ft_putstr(game->map[i]);
		write(1,"\n",1);
		i++;
	}
}

int map_correct_form(t_game *game)
{
	int i;

	i = 0;
	while (game->map[i] != '\0')
		i++;
	if (i < 3)
		return(ft_printf("the map is invalid!!"), 0);
	return (1);
}
