/*
LeetCode 101 - Symmetric Tree

Approach:
- A binary tree is symmetric if its left and right subtrees are
  mirror images of each other.
- Compare two nodes simultaneously:
    - Both NULL → symmetric at this position.
    - One NULL → structure is different.
    - Values different → not symmetric.
    - Otherwise:
        left subtree of node1  ↔ right subtree of node2
        right subtree of node1 ↔ left subtree of node2
- This is a "mirror comparison" rather than a normal
  same-tree comparison.

Time Complexity:
- O(n) : Every node is visited at most once
- O(1) : Constant comparison at each node
- Overall: O(n)

Space Complexity:
- O(h) : Recursive call stack
- Worst case: O(n) for a skewed tree
- Best case: O(log n) for a balanced tree
- Overall: O(h)

Revision Keywords:
- Symmetric Tree
- Mirror Tree
- DFS
- Recursion
- Two-Tree Comparison
- Mirror Comparison
- Left ↔ Right
*/

class Solution {
public:

    bool checkMirror(TreeNode* node1,
                     TreeNode* node2) {

        // Both sides are empty
        if(!node1 && !node2)
            return true;

        // Only one side is empty
        if(!node1 || !node2)
            return false;

        // Values must match
        if(node1->val != node2->val)
            return false;

        // Mirror comparison
        return checkMirror(node1->left, node2->right) &&
               checkMirror(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {

        if(!root)
            return true;

        return checkMirror(root->left, root->right);
    }
};
