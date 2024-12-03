#include "binary_trees.h"

/**
 * binary_tree_size_c - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree
 */
static size_t binary_tree_size_c(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size_c(tree->left) + binary_tree_size_c(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @size: Number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
static int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
    if (tree == NULL)
        return (1);

    if (index >= size)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, size) &&
            is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t size;

    if (tree == NULL)
        return (0);

    size = binary_tree_size_c(tree);
    return (is_complete(tree, 0, size));
}