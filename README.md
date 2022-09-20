# Binary trees in C++
Pointers enable structuring data in lots of sophisticated ways, and binary trees is just one of the applications of pointer-based data structures in C++. A single node consists of a 'data' variable and pointers to other nodes: a left node, with values smaller than the parent node, and a right node, with values greater than in the parent node.

Binary trees are naturally recursive due to pointing to other, smaller trees, which we can take advantage of implementing functions for working with its data recursively, which is done in this repository. Binary trees are fast in searching, as the number of options to search from decreases approximately by half with each iteration, given the tree is properly balanced.

Functions implemented in this repository: insertion of nodes, searching for nodes, deleting a whole tree, deleting separate nodes, display whole tree, count the number of nodes in a tree.

Display and countNodes functions are to be changed soon! They are not stable at the moment.
