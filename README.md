# learn c the hard way

Working through Zed Shaw's Learn C the Hard Way. Doing exercises and jotting some notes as I go.

---

## Exercise 00: Setup

For linux, `sudo apt−get install build−essential`. For OS X, install/update XCode.

`cc --version` to check your c compiler & version

Type the code, use little/no IDE features, try to type things from memory rather than side-by-side copying out of the text. Forces you to hold it in your memory and actually obsorb it.


## Exercise 01: Dust Off That Compiler


```
#include <stdio.h>

/* Multiline comment */

int main(int argc, char *argv[])
{
	int distance = 100;

	// single line comment
	printf("You are %d miles away.\n", distance);

	return 0;
}
```

`CFLAGS="-Wall -g" make ex1` to compile ex1.c

`-Wall` Enable all compiler warning messages

`-g` Geneate debug information (to be used with `gdb`)

## Exercise 02: Using `Makefiles` to build

`make ex1` uses a bunch of historical lore/magic and assumptions to build, i.e. looks for an `ex1.c`

A simple `Makefile`:

```
CFLAGS=-Wall -g

all: clean ex1

clean:
	rm -f ex1

```

- Specify some CFLAGS to pass to the compiler

- Define `all` target, which is default and will be used when you run just `make` without args

- `all` depends on clean and ex1. Will run clean, and then build.

- `clean` is an example target running arbitrary commands. Cleans up past build outputs (deletes ex1 binary)

## Exercise 03: Formatted Printing

`printf("I am %d years old.\n", age);`: Format as int

`printf("I am %.1f feet tall.\n", height);`: Format as float with 1 decimal place

Lots of format strings. Refer to the docs.

Common ways to break this program: Fail to set value of variable or fail to specify value to be substitued in `printf` call.

## Exercise 04: Using a Debugger

- On Linux, use `gdb`. `lldb` on Mac.

`gdb --batch --ex r --ex bt --ex q --args`: Runs the program so that if it bombs you get a backtrace

**Sample usage of gdb:**

`gdb ex4`: run ex4 under gdb

`break main`: Set a breakpoint at `main` function

`run`: Begin running/stepping through ex4

`next`: Step to next line

`print x`: Print value of x at current point in the program

`bt`: print a backtrace of current calling stack

`attach 123`: attach to process with pid 123 for debugging

## Exercise 05: Memorizing C Operators

Once you already know a language or two, memorization is an efficient way to pick up a new language, as opposed to learning through osmosis / typing in random code you aren't familiar with.

## Exercise 06: Memorizing C Syntax

*keywords* - augment the symbols of a language so it reads well

*lexical analysis* - processing the symbols and keywords of a language. A single symbol/word is a *lexeme*

## Exercise 07: Variables & Types

Strings are declared as character arrays: `char first_name[] = "Brad"`

`%ld` to print "long decimal" values (won't necessarily have a decimal point, called this for historical reasons)

`%e` to print with scientific notation for very small (or large) values

`\0` is just zero, and represents the `null byte` character, used to terminate strings stored as arrays

`char`s are just integers to C, and it will allow you to do math on them (for better or worse..)

You can read past the end of a string by overwriting the null byte terminator. ex:
```
char initial = 'J';
char first_name[] = "Brad";
char last_name[] = "Shively";
first_name[4] = 'Q';
/* 
At this point what you get from printing first_name
is totally random and depends on what's stored next in RAM
*/
printf("Who knows what this will print: %s.\n", first_name);

```

You can make `long`s 2x larger by making them `unsigned`. `long`s go from -N to +N. `unsigned long`s go from 0 to 2N.

## Exercise 08: If, Else-If, Else

No boolean type. `0` is false, everything else is true

`argc > 1` evaluates to 1 or 0, not true or false

`argv[0]` is the name of the program itself

```
if(blah) {
	do a thing;
} else if (blahblah) {
	do something else;
} else {
	as a last resort, do this thing;
}
```

## Exercise 09: While Loops

```
int i = 0;
while (i < 10) {
	// do a thing and increment
	i++;
}
```

## Exercise 10: Switch Statement

A switch statement in C is really a _jump table_. Can only use integers, not expressions (i.e `case x > 5` is invalid)

Because switch only accepts integers, it can sometimes be faster than an if statement in C

The program will jump to the location in memory indicated by case 'A' ('A' distance ahead) and relies on break statment to stop. If the distance is too far (i.e. not a defined value) it will go to the default statement.

Always include a `default` and don't forget to include the `break` after each case, unless you really intend for it to "fall through" to the next case

## Exercise 11: Arrays & Strings

Similarity between arrays and strings

Main difference is with a character array (string) you need to include the null byte terminator `\0` as the last slot

Use `char *name = "Brad"` instead of array syntax for just strings (not a character buffers.)

Many C bugs come from incorrect use of C strings i.e. dropping the null byte

## Exercise 12: Sizes and Arrays

`sizeof()` returns the number of bytes necessary to store a given type (or the type of a variable given as an arg, such as an array)

```
printf("%ld", sizeof(int)); // prints 4

```

Array is one contiguous block of memory in C. sizeof will tell you how big the block is.

When using `char *name`, sizeof will give you the size of the pointer, not of the array.

## Exercise 13: For Loops and Array of Strings

```
for(INITIALIZER; TEST; INCREMENTER) {
	CODE;
}
```

Make an array of character strings:
```
char *states[] = {"Texas", "Pennsylvania", "Ohio"}; 
```

## Exercise 14: Functions

Use forward declarations to specify functions without having to define them yet. Prevents the compiler from complaining about undefined functions (C99 warning) by declaring the signature ahead of time

Forward declarations allow you to define functions out of order (i.e. B calls A, but A is located after B in the src file) or deal with cycles in order in which functions are called

```
void print_letters(char arg[]);

...

void print_letters(char arg[]) {
  int i = 0;
  for (i = 0; arg[i] != '\0'; ++i) {
    char ch = arg[i];

    if (isalpha(ch) || isblank(ch)) {
      printf("'%c' == %d ", ch, ch);
    }
  }

  printf("\n");
}
```

A header file is basically just a collection of forward declarations

## Exercise 15: Pointers

When you access an array element with an index (i.e. `ages[i]`) you can also think of the index as an address: I want the age at address i.

So, what's `ages`? It's also an address in memory. The address of the first age in ages.

"C thinks your whole computer is just one big array of bytes."

- Create a block of memory in your computer (`ages[]`)
- Point the name `ages` at the beginning of that block
- Indexing into the block by taking the base address and getting the element `i` away from there
- Converting the address at `ages+i` into a valid int of the right size so indexing works correctly i.e. the int at index i

Indexing: Take a base address (`ages`) and add another address (`i`) to point to a new address.

Pointer: Something that points right at this location all the time.

A pointer is simply an address pointing somewhere inside memory, with a type specifier so you get the right size of data with it. Its like `ages` and `i` rolled int one thing.

C knows where pointers are pointing and what kind of data types they point to, the size of those types, and how to get the data for you.

Pointer lets you manually index data into blocks or memory when an array won't do it correctly. Often, you just want to use an array. Sometimes, you have to use a pointer. Pointer gives you raw, direct access to a block of memory so you can manipulate it.

`char *names[]` is an _array of character pointers_. The names are not in one contiguous block of memory.

### Some practical things you can do with pointers

- Ask the OS for a chunk of memory and work with it (strings, structs)
- Pass large blocks of memory (i.e. large structs) to functions with a pointer
- Take the address of a function to use as a dynamic callback
- Scan complex chunks of memory, converting bytes off of a network socket into data structures or parsing files

For nearly everything else, you should probably be using arrays instead of pointers

Used to make sense to use pointers for performance, but modern compilers use the same machine code and optimize the same way. Use arrays where you can, only optimize with pointers when you have to.

### Pointer lexicon

`type *ptr` A pointer of type named ptr

`*ptr` The value of whatever ptr is pointed at

`*(ptr + i)` The value of (whatever ptr is pointed at plus i)

`&thing` The address of thing

`type *ptr = &thing` A pointer of type named ptr set to the address of thing

`ptr++` increment where ptr points

---

Pointers aren't just arrays. They aren't the same thing, even though C lets you interact with them in many of the same ways. An example of them not working the same is you can't get the size of an entire array by doing `sizeof(ptr)`. That will give you the size of the pointer, not what it points at.

`*ptr` "dereferences" the pointer: go get the value of what ptr is pointing at.

