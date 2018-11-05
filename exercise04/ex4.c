#include <stdio.h>


int main(int argc, char *argv[])
{
	int age = 31;
	double height = 72.5;

	printf("I am %d years old.\n", age);

	age = 20;

	// %.Nf shows N places after the decimal
	printf("I am %.1f inches tall.\n", height);

	age = 5;

	return 0;
}
 