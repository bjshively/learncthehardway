#include <stdio.h>

int main(int argc, char *argv[]) {
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  for (i = 0; i < count; i++) {
    printf("%s is %d years old.\n", names[i], ages[i]);
  }
  printf("----\n");

  // Set up the pointers to the start of the arrays
  int *cur_age = ages;  // Create a pointer to an integer
  /* 
    Create a pointer to a pointer to char, because this is a multidimensional
    array
    char * is just a string. We need char **. This is a pointer to a pointer.
  */
  char **cur_name = names;

  // second way of using pointers
  for (i = 0; i < count; i++) {
    printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
  }
  printf("---\n");

  // third way, pointers are just arrays
  for (i = 0; i < count; i++) {
    printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
  }
  printf("---\n");

  // fourth way, stupid and complex
  for (cur_name = names, cur_age = ages; (cur_age - ages) < count;
       cur_name++, cur_age++) {
    printf("%s has lived %d years so far.\n", *cur_name, *cur_age);
  }

  return 0;
}