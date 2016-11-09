/**
 * file name: strcmp_t.cpp
 *
 * strcmp test
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	printf("Hello Sky.\n");
	const char *pName = "Serial";

	if (argc > 1)
	{
		int ret = strcmp(pName, argv[1]);
		printf("strcmp(%s, %s) value = %d\n", pName, argv[1], ret);

		if (!ret) {
			printf("Param is Serial.\n");
		}
		else {
			printf("Param is not Serial; is %s.\n", argv[1]);
		}
	}

	return 0;
}
