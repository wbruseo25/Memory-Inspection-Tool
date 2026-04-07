# Memory Inspection Tool

## What this is
This is a C program I wrote for my systems class that explores how command-line arguments (`argv`) are stored in memory.

The program prints out the memory contents of `argv`, the array of pointers, and the actual argument strings in a format similar to what you’d see using a debugger like `gdb`.

## What it does
- Shows the memory address stored in `argv`
- Prints the addresses of each argument (`argv[0]`, `argv[1]`, etc.)
- Displays the raw memory of the argument strings in hexadecimal
- Also shows the character representation of each byte when possible

## How to run it

Compile:

gcc examine.c -o examine
