/*
LeetCode 236 - Lowest Common Ancestor of a Binary Tree

Approach:
- Use Postorder DFS.
- For every node, recursively search for p and q in both subtrees.
- Base case:
    - If root == NULL → return NULL.
    - If root == p or root == q → return root.
- After recursion:
    - left = result from left subtree
    - right = result from right subtree
- If both left and right are non-NULL:
    - p and q were found in different subtrees.
    - Therefore, current root is their LCA.
- If only one side is non-NULL:
    - Both nodes are located in that subtree, so return that result upward.
- If both are NULL:
    - Neither p nor q exists in this subtree.

Time Complexity:
- O(n) : Every node is visited at most once
- O(1) : Constant work at each node
- Overall: O(n)

Space Complexity:
- O(h) : Recursive DFS stack
- Worst case: O(n) for a skewed tree
- Best case: O(log n) for a balanced tree
- Overall: O(h)

Revision Keywords:
- LCA
- Binary Tree
- Postorder DFS
- Bottom-Up Recursion
- Lowest Common Ancestor
- Two Subtree Results
- left && right
*/

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                    TreeNode* p,
                                    TreeNode* q) {

        // Found p/q OR reached NULL
        if(root == NULL ||
           root == p ||
           root == q)
            return root;

        // Search both subtrees
        TreeNode* left =
            lowestCommonAncestor(root->left, p, q);

        TreeNode* right =
            lowestCommonAncestor(root->right, p, q);

        // p and q found on different sides
        if(left && right)
            return root;

        // Only left side found
        if(left)
            return left;

        // Only right side found
        return right;
    }
};
