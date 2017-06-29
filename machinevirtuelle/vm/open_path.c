/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:13:51 by srabah            #+#    #+#             */
/*   Updated: 2017/06/15 05:01:59 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int					checksize(int sizetotal)
{
	if (sizetotal < (COMMENT_LENGTH + PROG_NAME_LENGTH + 12))
	{
		ft_putstr("La taille du joueur n'est pas");
		ft_putstr("adequate pour participer à la partie\n");
		return (0);
	}
	return (1);
}

static inline unsigned int	swap(unsigned int x)
{
	x = (x >> (unsigned int)24) |
		((x << (unsigned int)8) & 0x00FF0000) |
		((x >> (unsigned int)8) & 0x0000FF00) |
		(x << (unsigned int)24);
	return (x);
}

static inline int			open_check(char *pathplayer)
{
	int fd;

	if ((fd = open(pathplayer, O_RDONLY)) == -1)
	{
		ft_putstr("Erreur : chemin introuvable\n");
		return (-1);
	}
	return (fd);
}

int							open_path(char *pathplayer, t_player *player,
unsigned int x)
{
	int			fd;
	size_t		res;
	char		*buf;
	size_t		size;
	t_header	*head;

	if ((fd = open_check(pathplayer)) == -1)
		exit(0);
	size = lseek(fd, (size_t)0, SEEK_END);
	lseek(fd, (size_t)0, SEEK_SET);
	if (!(buf = ft_memalloc((size))) || (!checksize(size)))
	{
		close(fd);
		exit(0);
	}
	res = read(fd, buf, size);
	head = (void *)buf;
	head->prog_size = swap(head->prog_size);
	head->magic = swap(head->magic);
	player->header = head;
	player->instruction = (void *)(head + 1);
	player->data_file = buf;
	player->nbplayer = x;
	close(fd);
	return (1);
}
