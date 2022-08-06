#include <iostream>

using namespace std;

struct binary_tree {
    int data;
    binary_tree* left;
    binary_tree* right;
};

//Inserts new node into the binary tree
binary_tree* insertNode(binary_tree* tree, int key);
//Searches through the tree to find the node with the key value
binary_tree* search(binary_tree* tree, int key);
//Destroys the tree freeing the memory associated with it
void destroyTree(binary_tree* tree);
//Removes a node from the tree
binary_tree* removeNode(binary_tree* tree, int key);
//Utility function to find the greatest value of the current tree
binary_tree* find_max(binary_tree* tree);
//Helper function to remove max node from the original tree, because it gets replaced somewhere else
binary_tree* remove_max_node(binary_tree* tree, binary_tree* max_node);
//Displays the tree in sorted order
void display(binary_tree* tree);
//Recursive algorithm to get the number of nodes in the tree
int countNodes(binary_tree* tree);

int main()
{
    int input;
    binary_tree* tree = NULL;
    cout << "Enter the number of nodes: ";
    cin >> input;
    for (int i = 0; i < input; i++)
    {
        int value;
        cout << "Value of node " << i + 1 << ": ";
        cin >> value;
        tree = insertNode(tree, value);
    }
    display(tree);
    cout << "Number of nodes: " << countNodes(tree);

    cout << "Remove value: ";
    cin >> input;
    removeNode(tree, input);
    display(tree);
    cout << "Number of nodes: " << countNodes(tree);

    cout << "Input a value: ";
    cin >> input;
    insertNode(tree, input);
    display(tree);
    cout << "Number of nodes: " << countNodes(tree);

    cout << "Destroying the tree...\n";
    destroyTree(tree);
    display(tree);
    cout << "Number of nodes: " << countNodes(tree);

    return 0;
}

binary_tree* insertNode(binary_tree* tree, int key)
{
    //Base case
    if (tree == NULL)
    {
        binary_tree* node = new binary_tree;
        node->left = NULL;
        node->right = NULL;
        node->data = key;
        return node;
    }
    //Recursive case 1
    if (key < tree->data)     
        tree->left = insertNode(tree->left, key);
    //Recursive case 2
    else
        tree->right = insertNode(tree->right, key);
    return tree;
}

binary_tree* search(binary_tree* tree, int key)
{
    //Base case 1
    if (tree == NULL)
        return NULL;
    //Base case 2
    else if (key == tree->data)
        return tree;
    //Recursive case 1
    else if (key < tree->data)
        return search(tree->left, key);
    //Recursive case 2
    else
        return search(tree->right, key);
}

void destroyTree(binary_tree* tree)
{
    //Base case condition
    if (tree != NULL)
    {
        //Recursive calls
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    }
}

binary_tree* removeNode(binary_tree* tree, int key)
{
    //Base case 1: empty tree
    if (tree == NULL)
        return NULL;
    //Base case 2: target node
    if (tree->data == key)
    {
        //Zero or one child tree case
        if (tree->left == NULL)
        {
            binary_tree* right_subtree = tree->right;
            delete tree;
            return right_subtree;
        }
        //Zero or one child tree case
        if (tree->right == NULL)
        {
            binary_tree* left_subtree = tree->left;
            delete tree;
            return left_subtree;
        }
        //Max left node guarantees to successfully fill in the gap
        binary_tree* max_node = find_max(tree->left);
        max_node->left = remove_max_node(max_node->left, max_node);
        max_node->left = tree->left;
        max_node->right = tree->right;
        delete tree;
        return max_node;
    }
    //Recursive cases
    else if (key < tree->data)
        tree->left = removeNode(tree->left, key);
    else
        tree->right = removeNode(tree->right, key);
    return tree;
}

binary_tree* find_max(binary_tree* tree)
{
    //Base case 1
    if (tree == NULL)
        return NULL;
    //Base case 2
    if (tree->right == NULL)
        return tree;
    //Recursive case
    return find_max(tree->right);
}

binary_tree* remove_max_node(binary_tree* tree, binary_tree* max_node)
{
    //Base case 1
    if (tree == NULL)
        return NULL;
    //Base case 2 - return its left children, there can not be right children because it is max node
    if (tree == max_node)
        return max_node->left;
    //Recursive call
    tree->right = remove_max_node(tree->right, max_node);
    return tree;
}

void display(binary_tree* tree)
{
    //Base case
    if (tree == NULL)
        return;
    //Recursive calls
    display(tree->left);
    cout << tree->data << " ";
    display(tree->right);
}

int countNodes(binary_tree* tree)
{
    //Base case
    if (tree == NULL)
        return 0;
    //Recursive case
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}