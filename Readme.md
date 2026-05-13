# ft_printf

[![42 Project](https://img.shields.io/badge/42-Project-blue)](https://www.42.fr/)
[![Language](https://img.shields.io/badge/Language-C-green.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/Norminette-passing-success)](https://github.com/42School/norminette)

A custom implementation of the standard C library function `printf()`. This project is part of the 42 school curriculum and teaches about variadic functions, string formatting, and output management.

## 📋 Table of Contents

- [About](#about)
- [Supported Conversions](#supported-conversions)
- [Function Prototype](#function-prototype)
- [Compilation](#compilation)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [Project Structure](#project-structure)
- [Testing](#testing)

## 🎯 About

**ft_printf** recreates the behavior of the original `printf()` function from the C standard library. It handles various format specifiers and converts arguments to formatted output strings.

### Key Features

- ✅ Variadic function implementation
- ✅ Multiple format specifier support
- ✅ Return value: number of characters printed
- ✅ Buffer management for efficient output

## 🔤 Supported Conversions

<details>
<summary><b>Character and String Conversions</b></summary>

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | String | `ft_printf("%s", "Hello")` → `Hello` |
| `%%` | Percent sign | `ft_printf("%%")` → `%` |

</details>

<details>
<summary><b>Integer Conversions</b></summary>

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%d` | Signed decimal integer | `ft_printf("%d", -42)` → `-42` |
| `%i` | Signed decimal integer | `ft_printf("%i", 42)` → `42` |
| `%u` | Unsigned decimal integer | `ft_printf("%u", 42)` → `42` |

</details>

<details>
<summary><b>Hexadecimal and Pointer Conversions</b></summary>

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%x` | Hexadecimal (lowercase) | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadecimal (uppercase) | `ft_printf("%X", 255)` → `FF` |
| `%p` | Pointer address | `ft_printf("%p", ptr)` → `0x7fff5fbff7a0` |

</details>

## 📝 Function Prototype

```c
int ft_printf(const char *format, ...);
```

### Parameters
- `format`: Format string containing text and format specifiers
- `...`: Variable number of arguments matching the format specifiers

### Return Value
- Returns the total number of characters printed (excluding the null terminator)
- Returns `-1` on error

## 🔨 Compilation

<details>
<summary><b>Using the Makefile</b></summary>

```bash
# Compile the library
make

# Clean object files
make clean

# Clean everything (objects + library)
make fclean

# Recompile everything
make re
```

</details>

<details>
<summary><b>Manual Compilation</b></summary>

```bash
# Compile all source files
gcc -Wall -Wextra -Werror -c ft_printf.c ft_printf_utils.c [other files]

# Create the library
ar rcs libftprintf.a *.o

# Compile your program with the library
gcc -Wall -Wextra -Werror main.c -L. -lftprintf
```

</details>

## 💻 Usage

<details>
<summary><b>Basic Examples</b></summary>

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    // Print a string
    ft_printf("Hello, World!\n");

    // Print integers
    ft_printf("Number: %d\n", 42);
    ft_printf("Unsigned: %u\n", 42);

    // Print in hexadecimal
    ft_printf("Hex (lowercase): %x\n", 255);
    ft_printf("Hex (uppercase): %X\n", 255);

    // Print a character
    ft_printf("Character: %c\n", 'A');

    // Print a pointer
    int x = 42;
    ft_printf("Address: %p\n", &x);

    // Get return value
    count = ft_printf("Counting chars: %d\n", 123);
    ft_printf("Printed %d characters\n", count);

    return (0);
}
```

Output:
```
Hello, World!
Number: 42
Unsigned: 42
Hex (lowercase): ff
Hex (uppercase): FF
Character: A
Address: 0x7fff5fbff7a0
Counting chars: 123
Printed 20 characters
```

</details>

<details>
<summary><b>Advanced Usage</b></summary>

```c
#include "ft_printf.h"

int main(void)
{
    // Multiple format specifiers
    ft_printf("Name: %s, Age: %d, ID: %x\n", "Alice", 25, 0xABC);

    // Mixed types
    ft_printf("String: %s | Number: %d | Hex: %x\n", "Item", 100, 255);
    ft_printf("Char: %c | Pointer: %p | Percent: %%\n", 'A', &main);

    // Error handling
    int ret = ft_printf("%s %d %x", "Test", 42, 255);
    ft_printf("\nReturned: %d characters\n", ret);

    return (0);
}
```

Output:
```
Name: Alice, Age: 25, ID: abc
String: Item | Number: 100 | Hex: ff
Char: A | Pointer: 0x... | Percent: %
Returned: XX characters
```

</details>

## 🔍 Implementation Details

<details>
<summary><b>Variadic Functions</b></summary>

The project uses `va_list`, `va_start`, `va_arg`, and `va_end` from `<stdarg.h>` to handle variable numbers of arguments.

```c
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    
    va_start(args, format);
    // Process format string and arguments
    va_end(args);
    
    return (count);
}
```

</details>

<details>
<summary><b>Format String Parsing</b></summary>

The implementation:
1. Scans the format string character by character
2. Identifies format specifiers starting with `%`
3. Parses flags, width, and precision
4. Dispatches to appropriate conversion function
5. Tracks total characters printed

```
Format: "%+010.5d"
         │││││ │
         ││││└─ specifier (d)
         │││└── precision (5)
         ││└─── width (10)
         │└──── flag (0)
         └───── flag (+)
```

</details>

<details>
<summary><b>Conversion Functions</b></summary>

Each specifier has a dedicated handler:
- `ft_print_char()` - handles `%c`
- `ft_print_string()` - handles `%s`
- `ft_print_decimal()` - handles `%d` and `%i`
- `ft_print_unsigned()` - handles `%u`
- `ft_print_hex()` - handles `%x` and `%X`
- `ft_print_pointer()` - handles `%p`

</details>

<details>
<summary><b>Memory Management</b></summary>

- Dynamic allocation for building formatted strings
- Proper cleanup of allocated memory
- No memory leaks
- Efficient buffer usage

</details>

## 📁 Project Structure

```
Printf/
├── printf/
│   ├── ft_printf.c              # Main function
│   ├── ft_printf.h              # Header file
│   ├── ft_printf_char.c         # Character conversions
│   ├── ft_printf_string.c       # String conversions
│   ├── ft_printf_decimal.c      # Integer conversions
│   ├── ft_printf_unsigned.c     # Unsigned conversions
│   ├── ft_printf_hex.c          # Hexadecimal conversions
│   ├── ft_printf_pointer.c      # Pointer conversions
│   ├── ft_printf_utils.c        # Utility functions
│   └── Makefile                 # Build automation
├── en.subject.pdf               # Project subject
└── README.md
```

## 🧪 Testing

<details>
<summary><b>Comparison with Original printf</b></summary>

Create a test file to compare outputs:

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    printf("=== Testing %%d ===\n");
    ret1 = printf("Real: [%d]\n", 42);
    ret2 = ft_printf("Mine: [%d]\n", 42);
    printf("Real ret: %d, Mine ret: %d\n\n", ret1, ret2);

    printf("=== Testing %%x ===\n");
    ret1 = printf("Real: [%x]\n", 255);
    ret2 = ft_printf("Mine: [%x]\n", 255);
    printf("Real ret: %d, Mine ret: %d\n\n", ret1, ret2);

    printf("=== Testing %%s ===\n");
    ret1 = printf("Real: [%s]\n", "Hello");
    ret2 = ft_printf("Mine: [%s]\n", "Hello");
    printf("Real ret: %d, Mine ret: %d\n\n", ret1, ret2);

    return (0);
}
```

</details>

<details>
<summary><b>Automated Testers</b></summary>

Use community testers to verify your implementation:

```bash
# Tripouille's ft_printf tester
git clone https://github.com/Tripouille/printfTester.git
cd printfTester
make

# Paulo Santana's tester
git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester
make test
```

</details>

<details>
<summary><b>Memory Leak Testing</b></summary>

```bash
# Compile with debug symbols
gcc -g -Wall -Wextra -Werror main.c -L. -lftprintf

# Run with valgrind
valgrind --leak-check=full --show-leak-kinds=all ./a.out

# Check for leaks
valgrind --leak-check=full --track-origins=yes ./a.out
```

</details>

<details>
<summary><b>Edge Cases to Test</b></summary>

- NULL string: `ft_printf("%s", NULL)`
- Zero values: `ft_printf("%d", 0)`
- Negative numbers: `ft_printf("%d", -2147483648)`
- NULL pointer: `ft_printf("%p", NULL)`
- Empty string: `ft_printf("%s", "")`
- Multiple conversions: `ft_printf("%d %s %x", 42, "test", 255)`
- Only percent: `ft_printf("%%")`
- Width larger than content: `ft_printf("%20d", 42)`
- Precision with zero: `ft_printf("%.0d", 0)`

</details>

## License

This project is part of the 42 school curriculum. Feel free to use it for educational purposes.
