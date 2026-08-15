/*
LeetCode 199 - Binary Tree Right Side View

Approach:
- Use BFS (Level Order Traversal).
- Process the tree one level at a time.
- The queue always stores nodes level by level.
- For every level, the LAST node processed is the rightmost
  node of that level.
- Add that node to the answer.
- Continue until all levels are processed.

Time Complexity:
- O(n) : Every node is visited exactly once
- O(1) : Constant work is done for each node
- Overall: O(n)

Space Complexity:
- O(n) : Queue can contain O(n) nodes at the widest level
- Overall: O(n)

Revision Keywords:
- Binary Tree
- BFS
- Level Order Traversal
- Right Side View
- Rightmost Node
- Last Node of Level
- Queue
*/

class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size();

            for(int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Last node of current level
                // is visible from the right side
                if(i == n - 1)
                    ans.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};
