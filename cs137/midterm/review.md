# Separate compilation why? MOdularize design and reduce compile time

file.h:
  - #ifdef xxxx -> avoid duplicated definition
  - declare functions
  - Types (struct fraction)
  - Constants

file.c:
  - Preprocessing directives (ex. #include <stdio.h>)
  - #include "file.h"
  - "Secret" function declarations and definitions
  - Pre-declared function definition


### Compiling together
  - gcc a.out lmao.c main.c

### Separate compilation
  - gcc -c lmao.c
  - gcc -c main.c
  - gcc -o a.out lmao.o main.o

# Function pointers
* Functions can be passed as arguments
* Function identifiers/names are labels for the memory location where function

# Page Rank
- Determines a page's rank from the pages that "point" to it.
