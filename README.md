*This project has been created as part of the 42 curriculum by delroudi, erde-leo*

# push_swap

## Description

`push_swap` is an algorithmic project from the 42 curriculum focused on data sorting and complexity optimization under strict operational constraints. 

The objective of the project is to sort a random list of unique integers in ascending order using two stacks (**Stack A** and **Stack B**) and a limited set of specific stack manipulation instructions (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). The challenge lies not only in producing a valid sequence of operations that sorts the data, but using the **lowest possible number of moves**, pushing us to analyze time complexity, space management, and adaptive algorithmic strategies.

These are the movements allowed:
* **sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* **sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* **ss** : sa and sb at the same time.
* **pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* **pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* **ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* **rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* **rr** : ra and rb at the same time.
* **rra** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* **rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* **rrr** : rra and rrb at the same time.

At the end, stack b must be empty and all integers must be in stack a, sorted in ascending order.

## Instructions
### Compilation & Usage
The project is compiled using `make` via the provided `Makefile`, which compiles the source files with `cc` and the `-Wall -Wextra -Werror` flags.

```bash
# Compile the push_swap executable
make

# Remove object files
make clean

# Remove object files and the executable
make fclean

# Recompile the project from scratch
make re

## Execution

The program will output the sequence of instructions required to sort the numbers onto standard output. If no arguments are provided, it returns immediately without output. If invalid arguments are detected (non-integers, duplicates, or values exceeding INT_MIN/INT_MAX), it displays Error on the standard error output (stderr).

```c
#include ".h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    
```

### How to use it in your projects

Include the header file in your C programs:

```c
#include "push_swap.h"
```

## Libraries

The project is written in C and relies exclusively on standard libraries allowed by the 42 School subject guidelines:

* `#include <stddef.h>`
* `#include <stdint.h>`
* `#include <stdlib.h>`
* `#include <stdio.h>`
* `#include <stdarg.h>`
* `#include <unistd.h>`

# Structure
``` C
typedef struct s_stack_node
{
    int value;
    int index;
    struct s_stack_node * next;
    struct s_stack_node * prev;
}t_stack_node;

t_stack_node	*create_node(int value);
```

## Prototypes
```c
t_stack_node	*create_node(int value);

void add_node_back(t_stack_node **stack, int value);

int	get_stack_size(t_stack_node *st);

static int	swap(t_stack_node **stack);
void sa(t_stack_node **a);
void sb(t_stack_node **b);
void ss(t_stack_node **a, t_stack_node **b);

static int  push(t_stack_node **dst, t_stack_node **src);
void pa(t_stack_node **a, t_stack_node **b);
void pb(t_stack_node **b, t_stack_node **a);

static int  rotate(t_stack_node **stack);
void  ra(t_stack_node **a);
void  rb(t_stack_node **b);
void  rr(t_stack_node **a, t_stack_node **b);

static int  rev_rotate(t_stack_node **stack);
void  rra(t_stack_node **a);
void  rrb(t_stack_node **b);
void  rrr(t_stack_node **a, t_stack_node **b);
```

## Algorithms & Technical Justification

Because `push_swap` evaluates efficiency across vastly different input sizes, and because benchmark thresholds scale non-linearly relying on a single sorting algorithm leads to suboptimal instruction counts on either very small or very large datasets. 

To achieve optimal performance across all test cases, we implemented an adaptive multi-tier sorting strategy based on input size ($N$):

1. *Simple Strategy* (N <= 5): **Selection Sort (with Hardcoded Micro-Optimizations)**
How it works: For 2 or 3 elements, direct conditional checks sort Stack A in at most 2 operations. For 4 or 5 elements, our Selection Sort variant locates the minimum element(s) in Stack A, rotates them to the top via the shortest path (ra vs. rra), pushes them to Stack B (pb), sorts the remaining 3 elements in Stack A, and pushes the minimums back (pa).
Justification: Although Selection Sort has an O(n²) time complexity, asymptotic complexity is irrelevant for N <= 5. Selection Sort is deterministic, requires zero auxiliary metadata, and guarantees well under 12 operations for 5 numbers (beating the strict 42 benchmark).

2. *Medium Strategy* (5 < N <= 100): **Chunk Sort (Range / Butterfly Partitioning)** 
How it works: Before sorting, input values are normalized into their sorted indices (0 to N - 1). The index range is divided into equal-sized intervals ("chunks"). We iterate through Stack A, pushing elements belonging to the active chunk to Stack B (pb). Elements in the lower half of a chunk are rotated to the bottom of Stack B (rb), naturally creating a rough hourglass or "butterfly" distribution. Once Stack A is empty, elements are pushed back from Stack B to Stack A (pa) in descending order by always rotating the current maximum to the top via the shortest path.
Justification: Pure O(n²) algorithms exceed the 700-operation benchmark for 100 numbers, while non-comparative algorithms like Radix Sort struggle to consistently beat 700 moves at N = 100 due to fixed bitwise passes. Chunk Sort bridges this gap with an effective complexity of O(n \sqrt{n}). Pre-sorting values into structured ranges in Stack B drastically reduces the search and rotation distance during the final reconstruction phase, consistently achieving ~550–650 operations for 100 integers.

3. *Complex Strategy* (N > 100): **Radix Sort (LSD Binary)**
How it works: Using the normalized positive indices (0 to N - 1), we implement a Least Significant Digit (LSD) binary Radix Sort. For each bit position from the least significant bit ($0$) up to the highest bit required to represent $N - 1$, we inspect the top of Stack A: if the current bit is 0, the element is pushed to Stack B (pb); if the bit is 1, it is rotated to the bottom of Stack A (ra). After scanning all $N$ elements for that bit, everything in Stack B is pushed back to Stack A (pa), preserving relative order before moving to the next bit.Justification: For large datasets ($N = 500$), comparative algorithms that repeatedly search for minimums or maximums incur heavy rotation penalties. Binary Radix Sort operates in $O(n \log_2 n)$ time and completely eliminates element-to-element comparisons and reverse-rotation lookups. For $N = 500$, it requires exactly $\lceil \log_2(500) \rceil = 9$ bitwise passes, resulting in a predictable, worst-case-proof operation count of ~5,500–6,700 moves—comfortably clearing the 42 evaluation thresholds without edge-case degradation.

## Resources & AI Usage
### References and Documentation

* **Peer to Peer:** with other students in 42 Málaga and following campus learning methodologies (asking for doubts and making evaluations to others).

* **Cormen, T. H. et al.** — *Introduction to Algorithms (CLRS)*: Reference for Selection Sort, linear-time Radix Sort, and stack data structures.
* **Jamie Dawson** — [Push_swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a): Guide on index normalization and binary LSD Radix Sort.
* **A. Yigit Ogun** — [Push_swap Tutorial](https://medium.com/@ayogun/push-swap-c1f5d2d41e97): Breakdown of chunk/range partitioning and rotation cost optimization.
* **GeeksforGeeks** — [Selection Sort](https://www.geeksforgeeks.org/selection-sort/) & [Radix Sort](https://www.geeksforgeeks.org/radix-sort/): Online algorithmic references and complexity comparisons.

 ### Artificial Intelligence Usage
AI was used as a complementary learning tool during the development of this project for:

* **Conceptual Understanding:** Comparing the theoretical operation counts of Chunk Sort versus Binary Radix Sort across different input sizes (N = 100 and N = 500) and understanding bit wise manipulation for index-normalized Radix Sort.
* **Edge Cases and test generation:** Generating randomized integer permutations and boundary test cases (e.g., INT_MAX, INT_MIN, duplicate inputs, and already-sorted arrays) to stress-test our parser and sorting routines.

* *Note: All code and implementations have been individually written, verified, and tested by the authors.*