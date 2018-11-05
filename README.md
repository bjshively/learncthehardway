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