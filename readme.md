# get_next_line

## Overview
`get_next_line` is a project from the 42 network aimed at implementing a function that reads a single line from a file descriptor. This project helps you grasp file handling, buffer management, and dynamic memory allocation in C.

## Project Goals
- Implement the `get_next_line` function to read lines from a file descriptor one at a time.
- Understand and utilize static variables in C.
- Develop a solution that can handle different buffer sizes and multiple file descriptors.

## Core Functionality
The `get_next_line` function reads and returns a line from a file descriptor, handling end-of-file and errors. It should work for both file input and standard input.

### Function Prototype
```c
char *get_next_line(int fd);
