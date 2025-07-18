#include <string.h>

int segv_test(void)
{
	char *s = NULL;
	return (strlen(s));
}
