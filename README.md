*This project has been created as part of the 42 curriculum by molaoui.*

---

## Description

**ft_printf** is the second project in the 42 core curriculum (usually following *libft*). The goal of this project is to recode a simplified version of the standard C library's `printf()` function.

By building our own `ft_printf()`, we dive deep into **variadic functions** in C (`stdarg.h`), mastering how to handle an arbitrary number of arguments of varying types using macros like `va_start`, `va_arg`, `va_copy`, and `va_end`.

### Features & Conversions

The library handles the following conversion specifiers:

* **`%c`**: Prints a single character.
* **`%s`**: Prints a null-terminated string.
* **`%p`**: Prints a `void *` pointer in hexadecimal format (with `0x` prefix).
* **`%d`**: Prints a signed decimal integer (base 10).
* **`%i`**: Prints an integer in base 10.
* **`%u`**: Prints an unsigned decimal integer (base 10).
* **`%x`**: Prints a number in hexadecimal lowercase format (base 16).
* **`%X`**: Prints a number in hexadecimal uppercase format (base 16).
* **`%%`**: Prints a literal percent sign (`%`).

---

## Algorithm & Data Structure

### 1. Parsing & Flow Control

The core algorithm of `ft_printf` iterates through the format string character by character:

* If the current character is **not** a `%`, it is written directly to the standard output using a helper function, and the total printed character count is incremented.
* If a `%` is encountered, the function looks at the immediately following character to identify the **conversion specifier**.
* Once the specifier is recognized, the corresponding argument is fetched from the variadic list via `va_arg()` and passed to a dedicated printing/formatting helper function.

### 2. Handling Numeric Bases (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`)

For numeric conversions, recursion or iterative division is used to extract digits:

* **Base 10 (`%d`, `%i`, `%u`)**: Numbers are divided by 10. Negative numbers (`%d`/`%i`) are handled by printing a `-` sign first and converting the value to a positive `long` to prevent integer overflow edge cases (specifically with `INT_MIN`).
* **Base 16 (`%x`, `%X`, `%p`)**: Numbers are divided by 16, mapping remainders `0-15` to characters using a digit lookup string (`"0123456789abcdef"` or `"0123456789ABCDEF"`). Pointers (`%p`) explicitly prepend `0x` before printing the hexadecimal memory address.

### 3. Why This Approach?

* **Simplicity and Modularity**: Breaking each conversion type into its own dedicated function keeps the codebase clean, readable, and easy to debug.
* **No Buffer Management**: As per project requirements, buffer management is omitted, meaning characters and strings are written directly using system write calls (via a wrapper or `write(1, ...)`), avoiding complex memory buffers while keeping the logic straightforward.

---

## Instructions

### Compilation

The project comes with a standard `Makefile` that compiles the source files into a static library named `libftprintf.a`.

* **Compile the library:**
```bash
make

```


* **Clean object files:**
```bash
make clean

```


* **Clean object files and the library (`libftprintf.a`):**
```bash
make fclean

```


* **Rebuild the project from scratch:**
```bash
make re

```



### Usage

To use `ft_printf` in your own C programs, include the header file and link `libftprintf.a` during compilation:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! The answer is %d.\n", "World", 42);
    return (0);
}

```

Compile your program with:

```bash
gcc main.c libftprintf.a -o test_printf

```

---

## Resources & AI Usage

### Classic References

* [Man page for printf](https://man7.org/linux/man-pages/man3/printf.3.html)
* [C Variable Argument Lists (`stdarg.h`) Documentation](https://en.cppreference.com/w/c/variadic)
* 42 Subject PDF (`ft_printf.pdf`)

### AI Usage Declaration

AI tools were used during this project strictly as a supportive learning and debugging aid:

* **Concept Clarification**: Explaining how variadic macros (`va_start`, `va_arg`, etc.) work under the hood in C.
* **Edge Case Brainstorming**: Discussing how to handle edge cases like `INT_MIN` for signed decimal conversions and null-pointer edge cases for `%s`.