/*
LeetCode 100 - Same Tree

Approach:
- Use Recursive DFS to compare both binary trees simultaneously.
- At every pair of nodes:
    - If both nodes are NULL:
        - Both subtrees are empty → same.
    - If only one node is NULL:
        - Tree structures are different → false.
    - If their values are different:
        - Trees are different → false.
    - Otherwise:
        - Recursively compare the left subtrees.
        - Recursively compare the right subtrees.
- Both left and right subtrees must be identical.

Time Complexity:
- O(n) : Visit each corresponding node once
- O(1) : Constant comparison at each node
- Overall: O(n)

Space Complexity:
- O(h) : Recursive DFS stack
- Worst case: O(n) for a skewed tree
- Best case: O(log n) for a balanced tree
- Overall: O(h)

Revision Keywords:
- Binary Tree
- DFS
- Recursion
- Structural Comparison
- Tree Matching
- Same Tree
- Base Cases
*/

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both nodes are NULL
        if(!p && !q)
            return true;

        // One node is NULL
        if(!p || !q)
            return false;

        // Values are different
        if(p->val != q->val)
            return false;

        // Compare both subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
