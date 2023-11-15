#This project touches on sorting algorithms and Big O notation

# Big O Notation and Bubble Sort

## Big O Notation

**Big O Notation** is a mathematical notation used in computer science to describe the performance or complexity of an algorithm in terms of time or space. It provides an upper bound on the growth rate of a function, representing the worst-case scenario.

Common Big O notations include:

- **O(1):** Constant time complexity.
- **O(log n):** Logarithmic time complexity.
- **O(n):** Linear time complexity.
- **O(n log n):** Linearithmic time complexity.
- **O(n^2):** Quadratic time complexity.
- **O(2^n):** Exponential time complexity.
- **O(n!):** Factorial time complexity.

## Bubble Sort

**Bubble Sort** is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

### Algorithm:

1. Start at the beginning of the list.
2. Compare the first two elements.
3. Swap them if they are in the wrong order.
4. Move to the next pair of elements.
5. Continue this process until the end of the list is reached.
6. Repeat the process for each element in the list.

### Time Complexity:

The time complexity of Bubble Sort is O(n^2) in the worst and average cases, and O(n) in the best case when the list is already sorted. It is not an efficient algorithm for large datasets, but its simplicity makes it useful for educational purposes and small datasets.

### Usage:

Bubble Sort is mainly used for educational purposes or for sorting small datasets where its simplicity is an advantage. In practice, more efficient sorting algorithms such as Quick Sort or Merge Sort are preferred for larger datasets.
