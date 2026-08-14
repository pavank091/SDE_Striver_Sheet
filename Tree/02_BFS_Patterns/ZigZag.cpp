/*
LeetCode 103 - Binary Tree Zigzag Level Order Traversal

Approach:
- Use BFS (Level Order Traversal) with a queue.
- Process the tree level by level.
- For every level:
    - Store all node values in a temporary vector.
    - If the current direction is left-to-right, keep the level as it is.
    - If the direction is right-to-left, reverse the level.
- Toggle the direction after processing every level.
- This creates the required zigzag pattern.

Time Complexity:
- O(n) : Every tree node is visited once
- O(n) : Reversing levels takes O(level size); across all levels, total O(n)
- Overall: O(n)

Space Complexity:
- O(n) : Queue can contain O(n) nodes at the widest level
- O(n) : Answer + temporary level vector
- Overall: O(n)

Revision Keywords:
- Binary Tree
- BFS
- Level Order Traversal
- Zigzag Traversal
- Queue
- Level-by-Level Processing
- Direction Toggle
*/

class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()) {

            int n = q.size();
            vector<int> level;

            // Process one complete level
            for(int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            // Reverse alternate levels
            if(!leftToRight)
                reverse(level.begin(), level.end());

            ans.push_back(level);

            // Change direction
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
