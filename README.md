# Binary Trees

This project implements various binary tree operations in C.

## Data Structures

The following data structures are used for binary trees:

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
```

## Functions Implemented

1. `binary_tree_node`: Creates a new binary tree node
2. `binary_tree_insert_left`: Inserts a node as the left-child
3. `binary_tree_insert_right`: Inserts a node as the right-child
4. `binary_tree_delete`: Deletes an entire binary tree

## Compilation

All files will be compiled on Ubuntu 20.04 LTS using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```