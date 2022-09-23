## Binary Tree

Binary Tree is defined as a Tree data structure with at most 2 children. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.

### Classes

#### Node

Binary Tree node contains the following parts:

* Data
* Pointer to left child
* Pointer to right child

``` python
class node:
    # Constructor
    def __init__(self, val):
        self.value = val
        self.left = None
        self.right = None
```

<img src="./practice82.png" >

#### Tree

A full Binary tree is a special type of binary tree in which every parent node/internal node has either two or no children.

``` python
class Binary_Tree:
    # Constructor
    def __init__(self):
        self.root = None
```

The binary tree class has the following methods:

<ul>
    <li><code>add_node</code>: Add a node to the tree.</li>
    <li><code>in_order</code>: .</li>
    <li><code>pre_order</code>: </li>
    <li><code>post_order</code>: </li>
    <li><code>search</code>: </li>
    <li><code>minimum</code>: </li>
    <li><code>maximum</code>: </li>
    <li><code>print_tree</code>: </li>
    <li><code>breadth</code>: </li>
</ul>

For more details of the code you can check the [practice8.py](./practice8.py) file.