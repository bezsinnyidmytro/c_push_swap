/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnext_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezsinn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:23:45 by dbezsinn          #+#    #+#             */
/*   Updated: 2017/04/10 14:27:53 by dbezsinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_read_file(t_file *file)
{
	char			*str_buff;
	int				bytes_read;
	char			*tmp;

	if (!(file->buff))
	{
		file->buff = ft_strnew(GNL_BUFF_SIZE);
		bytes_read = read(file->fd, file->buff, GNL_BUFF_SIZE);
	}
	str_buff = ft_strnew(GNL_BUFF_SIZE);
	while (!ft_strchr(file->buff, '\n') && (bytes_read =
		read(file->fd, str_buff, GNL_BUFF_SIZE)))
	{
		tmp = file->buff;
		file->buff = ft_strjoin(file->buff, str_buff);
		free(tmp);
		ft_strclr(str_buff);
	}
	free(str_buff);
	return (bytes_read);
}

static void			ft_elem_init(t_file *file_i, int fd)
{
	file_i->fd = fd;
	file_i->buff = NULL;
	file_i->next = NULL;
	return ;
}

static t_file		*ft_getf_data(int const fd, t_file **list)
{
	t_file			*file_i;
	t_file			*file_last;
	char			*check;

	check = ft_strnew(0);
	if (fd < 0 || read(fd, check, 0) == -1)
		return (NULL);
	free(check);
	file_i = *list;
	file_last = NULL;
	while (file_i != NULL)
	{
		if (file_i->fd == fd)
			return (file_i);
		file_last = file_i;
		file_i = file_i->next;
	}
	if (!(file_i = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	ft_elem_init(file_i, fd);
	if (file_last == NULL)
		*list = file_i;
	else
		file_last->next = file_i;
	return (file_i);
}

static void			ft_parse_line(char *after_nl, char **line, t_file *file)
{
	int				line_len;

	if (!after_nl)
	{
		*line = ft_strdup(file->buff);
		ft_strclr(file->buff);
	}
	else
	{
		after_nl = ft_strsub(after_nl, 1, ft_strlen(after_nl) - 1);
		line_len = ft_strlen(file->buff) - ft_strlen(after_nl) - 1;
		*line = ft_strsub(file->buff, 0, line_len);
		free(file->buff);
		file->buff = ft_strdup(after_nl);
		free(after_nl);
	}
	return ;
}

int					get_next_line(int const fd, char **line)
{
	static t_file	*file_list;
	t_file			*file;
	char			*after_nl;
	size_t			bytes_read;

	bytes_read = GNL_BUFF_SIZE;
	after_nl = NULL;
	file = ft_getf_data(fd, &file_list);
	if (file)
	{
		if (file->buff)
			after_nl = ft_strchr(file->buff, '\n');
		while (!after_nl && (bytes_read = ft_read_file(file)) > 0)
			after_nl = ft_strchr(file->buff, '\n');
		if (bytes_read == 0 && !(file->buff[0]))
			return (0);
		ft_parse_line(after_nl, line, file);
		if (!(*line))
			return (-1);
		else
			return (1);
	}
	return (-1);
}
