#include <stdio.h>

int main(int argc, char* argv[]) {
  int areas[] = {10, 12, 13, 14, 20};
  char name[] = "Brad";
  char full_name[] = {'B', 'r', 'a', 'd', ' ', 'S', 'h',
                      'i', 'v', 'e', 'l', 'y', '\0'};

  // On some machines %ld may need to be replaced with %u
  // for unsigned ints

  printf("The size of an int: %ld\n", sizeof(int));

  // Print the size of the block of memory required to store areas
  printf("The size of areas (int[]): %ld\n", sizeof(areas));

  // Print the number of ints in areas by dividing
  // the size of areas by the size of a single int
  printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));

  printf("The 1st area is %d, the 2nd is %d.\n", areas[0], areas[1]);

  printf("The size of a char is: %ld\n", sizeof(char));
  printf("The size of name (char[]): %ld\n", sizeof(name));
  printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));

  printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
  printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));

  printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

  return 0;
}