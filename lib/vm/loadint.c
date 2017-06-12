





#include "../../includes/vm.h"

unsigned int	loadint(unsigned char *ram, int pc)
{
	unsigned int ret;

	ret = (ram[pc] << 24)
		| ((ram[pc + 1] << 16) & 0x00ffffff)
		| ((ram[pc + 2] << 8) & 0x0000ffff)
		| (ram[pc + 3] & 0x000000ff);
	return (ret);
}
