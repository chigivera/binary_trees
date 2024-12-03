#include "binary_trees.h"

/**
 * binary_tree_height_l - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree
 */
static size_t binary_tree_height_l(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (tree == NULL)
        return (0);

    left_height = tree->left ? 1 + binary_tree_height_l(tree->left) : 0;
    right_height = tree->right ? 1 + binary_tree_height_l(tree->right) : 0;

    return (left_height > right_height ? left_height : right_height);
}

/**
 * print_level - Prints nodes at a given level
 * @tree: Pointer to the root node
 * @level: Level to print
 * @func: Pointer to a function to call for each node
 */
static void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
    if (tree == NULL)
        return;

    if (level == 0)
        func(tree->n);
    else
    {
        print_level(tree->left, level - 1, func);
        print_level(tree->right, level - 1, func);
    }
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, i;

    if (tree == NULL || func == NULL)
        return;

    height = binary_tree_height_l(tree);

    for (i = 0; i <= height; i++)
        print_level(tree, i, func);
}