#include <stdio.h>

int main(int argc, char* argv[]) {
  int numbers[4] = {0};
  char name[5] = {'a'};

  // first, print them out raw
  printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2],
         numbers[3]);

  printf("name each: %c %c %c %c %c\n", name[0], name[1], name[2], name[3],
         name[4]);

  printf("name: %s", name);

  // setup the numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  // setup the name
  name[0] = 'B';
  name[1] = 'r';
  name[2] = 'a';
  name[3] = 'd';
  name[4] = '\0';

  // print them now that they're initialized
  printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2],
         numbers[3]);

  printf("name each: %c %c %c %c %c\n", name[0], name[1], name[2], name[3],
         name[4]);

  printf("name: %s\n", name);

  // Another way to create a string
  char* anotherName = "Brad";
  printf("%s\n", anotherName);

  // you can still print each char separately
  printf("%c %c %c %c %c\n", anotherName[0], anotherName[1], anotherName[2],
         anotherName[3], anotherName[4]);

  return 0;
}