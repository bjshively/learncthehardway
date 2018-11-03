#include <stdio.h>


int main(int argc, char *argv[])
{
	int age = 31;
	double height = 72.5;

	printf("I am %d years old.\n", age);

	// %.Nf shows N places after the decimal
	printf("I am %.1f inches tall.\n", height);

	return 0;
}
 