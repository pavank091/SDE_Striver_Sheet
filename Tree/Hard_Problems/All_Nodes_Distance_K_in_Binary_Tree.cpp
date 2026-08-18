/*
LeetCode 863 - All Nodes Distance K in Binary Tree

Approach:
- A binary tree normally allows movement only:
      parent → child
- For Distance K, we need to move in ALL directions:
      left child, right child, parent
- Convert the tree conceptually into an undirected graph by storing:
      child → parent
  using an unordered_map.
- Start BFS from the target node.
- Each BFS level represents one distance from the target.
- Use a visited map because after adding parent links, the structure
  behaves like an undirected graph and we must avoid visiting nodes
  repeatedly.
- Stop BFS when the current level becomes K.
- All nodes remaining in the queue are exactly K distance away.

Time Complexity:
- O(n) : mapParent() visits every tree node once
- O(n) : BFS can visit every node once
- O(n) : Building the answer from the queue
- Overall: O(n)

Space Complexity:
- O(n) : Parent map
- O(n) : Visited map
- O(n) : BFS queue in the worst case
- Overall: O(n)

Revision Keywords:
- Binary Tree
- BFS
- Distance K
- Parent Mapping
- Tree → Undirected Graph
- Level Order
- Visited
- Multi-Directional Traversal
*/

class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> mp;

    void mapParent(TreeNode* root) {

        if(!root)
            return;

        if(root->left)
            mp[root->left] = root;

        mapParent(root->left);

        if(root->right)
            mp[root->right] = root;

        mapParent(root->right);
    }

    vector<int> distanceK(TreeNode* root,
                          TreeNode* target,
                          int k) {

        // Create child → parent mapping
        mapParent(root);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int lvl = 0;

        while(!q.empty()) {

            int n = q.size();

            // Queue now contains nodes at distance lvl
            if(lvl == k)
                break;

            for(int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                TreeNode* left = node->left;
                TreeNode* right = node->right;
                TreeNode* parent = mp[node];

                // Move to left child
                if(left && !visited[left]) {
                    q.push(left);
                    visited[left] = true;
                }

                // Move to right child
                if(right && !visited[right]) {
                    q.push(right);
                    visited[right] = true;
                }

                // Move to parent
                if(parent && !visited[parent]) {
                    q.push(parent);
                    visited[parent] = true;
                }
            }

            lvl++;
        }

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
