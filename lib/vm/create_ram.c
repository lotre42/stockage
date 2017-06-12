
#include "../../includes/vm.h"

static void		cpyinram(unsigned char *ram, t_player *players, int i)
{
	unsigned int x;

	x = 0;
	while (x < players->header->prog_size)
	{
		ram[i] = players->instruction[x];
		x++;
		i++;
	}
}

static int 	size_prog(unsigned int size, unsigned int x)
{
	if (size > x)
	{
		ft_putstr("Le programme est trop grand pour s'inserer dans la ram");
		return (0);
	}
	return (1);
}

unsigned char		*create_ram(t_player *players, int nb, t_process *process)
{
	unsigned char *ram;
	unsigned int  x;
	int i;

	i = 1;
	if (nb > MAX_PLAYERS)
	{
		ft_putstr("Le nombre de player est trop important\n");
		return (0);
	}
	x = MEM_SIZE / nb;
	ram = (unsigned char *)ft_strnew(MEM_SIZE);
	cpyinram(ram, players, 0);
	nb--;
	while (nb > 0)
	{
		players = players->next;
		process = process->next;
		if (!size_prog(players->header->prog_size, x))
			return (0);
		cpyinram(ram, players, x * i);
		process->pc = x * i;
		i++;
		nb--;
	}
	i = 0;
	x = 0;
	return (ram);
}