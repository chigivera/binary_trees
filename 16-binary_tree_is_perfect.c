#include "binary_trees.h"

/**
 * binary_tree_height_p - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree
 */
static size_t binary_tree_height_p(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (tree == NULL)
        return (0);

    left_height = tree->left ? 1 + binary_tree_height_p(tree->left) : 0;
    right_height = tree->right ? 1 + binary_tree_height_p(tree->right) : 0;

    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size_p - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree
 */
static size_t binary_tree_size_p(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_size_p(tree->left) + binary_tree_size_p(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, size;
    size_t perfect_size;

    if (tree == NULL)
        return (0);

    height = binary_tree_height_p(tree);
    size = binary_tree_size_p(tree);

    /* Perfect binary tree has 2^(h+1) - 1 nodes */
    perfect_size = (1 << (height + 1)) - 1;

    return (size == perfect_size);
}