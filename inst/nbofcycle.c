



#include "../includes/corewar.h"

void		nbofcycle(t_player *player)
{
	if (player->stok->ram[player->stok->pc] == 0x01)
		player->stok->cycle = 5;
	else if (player->stok->ram[player->stok->pc] == 0x02)
		player->stok->cycle = 5;
	else if (player->stok->ram[player->stok->pc] == 0x03)
		player->stok->cycle = 5;
	else if (player->stok->ram[player->stok->pc] == 0x04)
		player->stok->cycle = 10;
	else if (player->stok->ram[player->stok->pc] == 0x05)
		player->stok->cycle = 10;
	else if (player->stok->ram[player->stok->pc] == 0x06)
		player->stok->cycle = 6;
	else if (player->stok->ram[player->stok->pc] == 0x07)
		player->stok->cycle = 6;
	else if (player->stok->ram[player->stok->pc] == 0x08)
		player->stok->cycle = 6;
	else if (player->stok->ram[player->stok->pc] == 0x09)
		player->stok->cycle = 20;
	else if (player->stok->ram[player->stok->pc] == 0x0a)
		player->stok->cycle = 25;
	else if (player->stok->ram[player->stok->pc] == 0x0b)
		player->stok->cycle = 25;
	else if (player->stok->ram[player->stok->pc] == 0x0d)
		player->stok->cycle = 10;
	else if (player->stok->ram[player->stok->pc] == 0x0e)
		player->stok->cycle = 50;
	else
		player->stok->cycle = 0;
}
