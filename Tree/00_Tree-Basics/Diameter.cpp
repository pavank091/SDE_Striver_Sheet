/*
LeetCode 543 - Diameter of Binary Tree

Approach:
- Use Postorder DFS because we need the height of both subtrees
  before calculating the diameter passing through the current node.
- For every node:
    - Find the left subtree height.
    - Find the right subtree height.
    - Diameter passing through this node = leftHeight + rightHeight.
    - Update the global maximum diameter.
    - Return the height of the current subtree:
          1 + max(leftHeight, rightHeight)
- The diameter is measured in number of EDGES, so we use:
      leftHeight + rightHeight
  rather than adding 1 for the current node.

Time Complexity:
- O(n) : Every tree node is visited exactly once
- O(1) : Constant work is done at each node
- Overall: O(n)

Space Complexity:
- O(h) : Recursive call stack, where h is the height of the tree
- Worst case: O(n) for a skewed tree
- Best case: O(log n) for a balanced tree
- Overall: O(h)

Revision Keywords:
- Binary Tree
- DFS
- Postorder Traversal
- Tree Height
- Tree Diameter
- Global Maximum
- Bottom-Up DFS
*/

class Solution {
public:

    int diameter(TreeNode* root, int& d) {

        if(root == NULL)
            return 0;

        // Height of left subtree
        int l = diameter(root->left, d);

        // Height of right subtree
        int r = diameter(root->right, d);

        // Diameter passing through current node
        d = max(d, l + r);

        // Return height of current subtree
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int d = 0;

        diameter(root, d);

        return d;
    }
};
