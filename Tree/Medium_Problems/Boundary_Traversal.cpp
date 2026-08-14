/*
GFG - Boundary Traversal of Binary Tree

Approach:
- Traverse the boundary in three parts:
    1. Root
    2. Left Boundary (excluding leaf nodes)
    3. All Leaf Nodes (left to right)
    4. Right Boundary (excluding leaf nodes, in reverse order)
- Handle leaf nodes separately so that they are not added twice.
- Left boundary:
    - Prefer the left child.
    - If left child doesn't exist, move to the right child.
- Leaf nodes:
    - Perform DFS and add every leaf node.
- Right boundary:
    - Prefer the right child.
    - If right child doesn't exist, move to the left child.
    - Add nodes while backtracking, which naturally reverses the order.
- The final result gives the complete boundary in anti-clockwise order.

Time Complexity:
- O(n) : Traverse every tree node at most a constant number of times
- O(1)   : Constant work at every visited node
- Overall: O(n)

Space Complexity:
- O(h) : Recursion stack, where h is the tree height
- Worst case: O(n) for a skewed tree
- Best case: O(log n) for a balanced tree
- Overall: O(h)
  (excluding output storage)

Revision Keywords:
- Binary Tree
- Boundary Traversal
- Left Boundary
- Leaf Nodes
- Right Boundary
- Anti-Clockwise Traversal
- DFS
- Backtracking
*/

class Solution {
public:

    vector<int> result;

    bool isLeaf(Node* root) {
        return root->left == NULL &&
               root->right == NULL;
    }

    void addLeftBoundary(Node* root) {

        if(!root || isLeaf(root))
            return;

        result.push_back(root->data);

        if(root->left)
            addLeftBoundary(root->left);
        else
            addLeftBoundary(root->right);
    }

    void addLeaves(Node* root) {

        if(!root)
            return;

        if(isLeaf(root)) {
            result.push_back(root->data);
            return;
        }

        addLeaves(root->left);
        addLeaves(root->right);
    }

    void addRightBoundary(Node* root) {

        if(!root || isLeaf(root))
            return;

        if(root->right)
            addRightBoundary(root->right);
        else
            addRightBoundary(root->left);

        // Backtracking automatically gives reverse order
        result.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node* root) {

        if(!root)
            return result;

        // Root is added separately only if it is not a leaf
        if(!isLeaf(root))
            result.push_back(root->data);

        addLeftBoundary(root->left);

        addLeaves(root);

        addRightBoundary(root->right);

        return result;
    }
};
