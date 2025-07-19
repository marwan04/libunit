#include <string.h>

int	bus_test(void)
{
	char	*p;

	p = (char *)0xdeadbeef;
	return (strlen(p));
}
