/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:46:05 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 16:39:53 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_length(const char *s, int *x)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_isdigit(s[i]) == 0)
			++i;
		if (ft_isdigit(s[i]))
			++nb;
		while (s[i] != '\0' && s[i] != ' ')
			++i;
	}
	if (*x == 0)
		*x = nb;
	else
		*x = (*x == nb ? nb : -1);
}

static int	first_read(t_data *data, const char *file, int *y, int *x)
{
	char	*line;
	int		fd;
	int		ret;

	*y = 0;
	*x = 0;
	if ((fd = (open(file, O_RDONLY))) == -1)
	{
		ft_putendl("open(2) error : argument specified does not exist.");
		return (-1);
	}
	while (*x != -1 && (ret = get_next_line(fd, &line)) == 1)
	{
		++(*y);
		check_length(line, x);
		free(line);
	}
	close(fd);
	if (ret == -1 || *x == -1 || (ret == 0 && *x == 0))
	{
		ft_putendl("error : invalid file.");
		return (-1);
	}
	data->var->xmax = *x;
	return (0);
}

static void	fill_arr(int *arr, const char *str, const int x)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < x)
	{
		while (str[i] && (ft_isdigit(str[i]) == 0 && str[i] != '-'))
			++i;
		if (ft_isdigit(str[i]) || str[i] == '-')
			arr[j] = ft_atoi(str + i);
		while (str[i] && str[i] != ' ')
			++i;
		++j;
	}
	arr[x] = -1;
}

static int	second_read(int **arr, const int fd, const int x)
{
	char	*line;
	int		y;

	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(arr[y] = (int *)malloc(sizeof(int) * (x + 1))))
		{
			free(line);
			ft_putendl("malloc(3) error : could not allocate demanded memory.");
			return (-1);
		}
		fill_arr(arr[y], line, x);
		free(line);
		++y;
	}
	return (0);
}

int			**arr_init(t_data *data, const char *file)
{
	int		**arr;
	int		fd;
	int		x;
	int		y;

	if (first_read(data, file, &y, &x))
		return (NULL);
	fd = (open(file, O_RDONLY));
	if (!(arr = (int **)malloc(sizeof(int *) * (y + 1))))
	{
		ft_putendl("malloc(3) error : could not allocate demanded memory.");
		return (NULL);
	}
	arr[y] = NULL;
	if (second_read(arr, fd, x))
		return (NULL);
	close(fd);
	return (arr);
}
