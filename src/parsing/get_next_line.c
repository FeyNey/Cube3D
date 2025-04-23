/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:07:05 by acoste            #+#    #+#             */
/*   Updated: 2025/04/23 15:22:31 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*stock;
	int		i;
	int		j;

	i = ft_strlen(stash) + ft_strlen(buffer);
	stock = ft_malloc_char(i);
	i = -1;
	while (stash[++i])
		stock[i] = stash[i];
	j = -1;
	while (buffer[++j])
		stock[i + j] = buffer[j];
	if (stash)
		free(stash);
	return (stock);
}

static char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		i;
	int		j;

	if (!stash)
		stash = ft_malloc_char(0);
	buffer = ft_malloc_char(BUFFER_SIZE);
	j = read(fd, buffer, BUFFER_SIZE);
	if (j == -1)
		return (free(buffer), NULL);
	buffer[j] = '\0';
	i = -1;
	while (j > 0 && i == -1)
	{
		i = ft_search(buffer, '\n');
		stash = ft_strjoin(stash, buffer);
		if (i > -1)
			break ;
		j = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (stash);
}

static char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_next_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	line = ft_malloc_char(ft_strlen(stash) - i);
	i++;
	j = 0;
	while (stash[i])
	{
		line[j] = stash[i];
		i++;
		j++;
	}
	line[j] = '\0';
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (free(stash), stash = NULL, NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_next_line(stash);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	str = "q";
	fd = open("test.cub", O_RDONLY);
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("result = %s", str);
	}
	if (str)
		free(str);
//	str = get_next_line(fd);
//	printf("result = %s", str);
//	if (str)
//		free(str);
	return (0);
}
*/