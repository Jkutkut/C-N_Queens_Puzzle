# N Queens puzzle:

This repository contains logic to calculate and visualice the [N Queens problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle). It features the use of recursive backtracking to find the solutions and a customizable visualization style.

    ┼───────┼───────┼───────┼───────┼
    │       │·······│       │·······│
    │       │·······│   ♛   │·······│
    │       │·······│       │·······│
    ┼───────┼───────┼───────┼───────┼
    │·······│       │·······│       │
    │·· ♛ ··│       │·······│       │
    │·······│       │·······│       │
    ┼───────┼───────┼───────┼───────┼
    │       │·······│       │·······│
    │       │·······│       │·· ♛ ··│
    │       │·······│       │·······│
    ┼───────┼───────┼───────┼───────┼
    │·······│       │·······│       │
    │·······│   ♛   │·······│       │
    │·······│       │·······│       │
    ┼───────┼───────┼───────┼───────┼

## Use:

To use the code, you can type on the root of the repository:

    make fclean
    make

Why? To compile the code, there's a Makefile to automate the installation. For a basic install, use:

    make fclean

to clean the binaries and repository, followed by

    make
or

    make all
or

    make XXXXX

To install the alternative style where **XXXXX** is the desired style. See [how to create a custom style](#Create-custom-styles) to create your own.

Once compiled, you can execute the program using:
    
    ./representation X
where **X** is the size of the desired grid (If none given, the default is 8)

## Create custom styles:
Imagine you want to create a style called YYYY. Here are the steps:
- Go to ./src/style/
- Copy any of the already defined styles and renamed it following the same syntax (**YYYY**_chess_style.h)

        cp classic_chess_style.h YYYYY_chess_style.h
- Edit and save the file to your linking.
- Go to the Makefile in the root directory of the repo and add the following line (there's a comment on the spot for you to use :D):

        YYYY: YYYY_chess_style.h $(EXE_NAME)
- That's it! Just recompile using the new style!


# Considerations
- Due to the inefficiency of printing on the screen each solution, for a grid greater than 13-14 the output becomes too great. However, the code is designed so you can just use the part to find the solutions with a bit of modification.
- The total number of solutions is stored on a int variable to count them. If you want to track the number for bigger sizes, remember to use a variable big enough.