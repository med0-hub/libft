*This project has been created as part of the 42 curriculum by mbelarab.*

# Libft

## Description

**Libft** is my first own C library. The goal of the project is to understand how the most common standard C functions work by re-implementing them from scratch, and to build a reusable toolbox of functions that I can use in my future 42 projects.

The library is compiled into a static archive, `libft.a`, and is split into three parts:

1. **Libc functions**: re-implementations of standard functions, with the same prototypes and behaviours as the originals, prefixed with `ft_`.
2. **Additional functions**: useful functions that are either not in the libc or exist in a different form (string manipulation, number conversion, file descriptor output).
3. **Linked list functions**: a set of functions to create and manipulate singly linked lists using the `t_list` structure.

Only the mandatory part was implemented. There is no bonus.

### Library overview

**Part 1: Libc functions**

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String functions | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

**Part 2: Additional functions**

| Function | Description |
|---|---|
| `ft_substr` | Returns a new substring from a string, starting at a given index with a maximum length. |
| `ft_strjoin` | Returns a new string that is the concatenation of two strings. |
| `ft_strtrim` | Returns a copy of a string with the characters of a given set removed from the beginning and the end. |
| `ft_split` | Splits a string using a delimiter character and returns a NULL-terminated array of new strings. |
| `ft_itoa` | Converts an integer to a newly allocated string, negative numbers included. |
| `ft_strmapi` | Applies a function to each character (with its index) and returns a new string with the results. |
| `ft_striteri` | Applies a function to each character of a string (with its index), passing it by address so it can be modified. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

**Part 3: Linked list**

The list is based on the following structure, declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstsize` | Counts the number of nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstdelone` | Frees one node and its content using a given `del` function. |
| `ft_lstclear` | Deletes and frees a node and all its successors, then sets the list pointer to NULL. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Creates a new list by applying a function to the content of each node. |

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`
- `ar`

### Compilation

The library is compiled with `cc` and the flags `-Wall -Wextra -Werror`, and the archive is created with `ar`. All files are at the root of the repository.

```bash
make        # builds libft.a
make clean  # removes the object files
make fclean # removes the object files and libft.a
make re     # rebuilds everything from scratch
```

The Makefile provides the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`.

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Then compile your program and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## Technical choices

- No global variables.
- Helper functions, when needed, are declared `static` so they stay limited to their own file.
- Heap-allocated memory is freed properly, and the functions were checked for memory leaks.
- The library is built with `ar`; `libtool` is not used.

### The hardest function: `ft_strtrim`

`ft_strtrim` was the function I found the hardest. The difficulty was to find the right start and end positions of the trimmed string when the characters to remove can appear at both ends. The solution became clear once I realised that `ft_strchr` and `ft_strrchr` could help me check whether a character belongs to the given set.

## Testing

To test the library, I wrote my own test cases, which I tried to design so that they could break my functions (edge cases, empty strings, unusual values). I compared the results of my functions with the real libc functions. I also used `valgrind` to check for memory leaks and invalid memory accesses.

## What I learned

- How code works in the background: how the compiler, the CPU and the memory work together.
- How to test my own code properly.
- How Makefiles work.

## Resources

### References

- Manual pages (`man`) for the libc functions
- Stack Overflow
- YouTube videos
- Peer learning with other students on my campus

### How AI was used

I used AI only as a learning aid. When I wanted to learn a new concept that was difficult for me to understand, I used AI to simplify the information and make the concept easier to grasp. I used it only for understanding concepts, not as a replacement for my own reasoning.
