# 1337-Libft
*This project has been created as part of the 42 curriculum by ibendris.*

# Libft

## Description

Libft is the first project of the 42 Common Core. The goal is to rebuild a
personal C library containing re-implementations of standard libc functions,
plus extra utility functions (string, memory, output and linked-list helpers)
that will be reused in all later 42 projects.

The library is compiled into a static archive, `libft.a`, and follows the
42 Norm. Only the allowed functions (`malloc`, `free`, `write`) are used.

### Library content

**Part 1: libc functions (re-implemented)**

| Category | Functions |
|----------|-----------|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

**Part 2: additional functions**

| Function | Purpose |
|----------|---------|
| `ft_substr` | Returns a new string extracted from `s`, starting at `start`, of max length `len` |
| `ft_strjoin` | Returns a new string made of `s1` followed by `s2` |
| `ft_strtrim` | Returns a copy of `s1` without the characters of `set` at both ends |
| `ft_split` | Splits a string into a NULL-terminated array of words using a delimiter character |
| `ft_itoa` | Converts an integer to a newly allocated string |
| `ft_strmapi` | Applies a function to each character (with its index) and returns the new string |
| `ft_striteri` | Applies a function to each character (with its index) in place |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a char, string, string + newline, or number to a file descriptor |

**Part 3: linked lists** (`t_list`)

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`,
`ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instructions

### Compilation

The library is compiled with `cc -Wall -Wextra -Werror`.

```
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + make
```

### Usage

Include the header in your code:

```c
#include "libft.h"
```

Then compile your program against the archive:

```
cc -Wall -Wextra -Werror main.c my_program
```

### Example

```c
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	**tab;
	int		i;

	tab = ft_split("hello,world,42", ',');
	i = 0;
	while (tab && tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
```

## Resources

### References

- `man 3 <function>` for the behavior of each libc function being re-implemented
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language), Kernighan & Ritchie
- [42 Norm](https://github.com/42School/norminette), the norminette repository

### Use of AI

AI was used as a code reviewer, not as a code generator. It was used to:

- Trace functions by hand on example inputs to check the logic and the memory-freeing path.
- Point out Norm issues (for example a tab in a parameter list).

All functions were written, understood and tested by me. AI was not used to
write the implementations.
