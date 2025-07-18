#include <string.h>

int bus_test(void)
{
	char *p = (char *)0xdeadbeef;
	return (strlen(p));
}
