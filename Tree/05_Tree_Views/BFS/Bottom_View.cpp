/*
GFG - Bottom View of Binary Tree

Approach:
- Assign a Horizontal Distance (HD) to every node:
    - Root → HD = 0
    - Left child → HD - 1
    - Right child → HD + 1
- Use BFS (Level Order Traversal).
- For every node encountered:
    - Store its value for that horizontal distance.
    - Unlike Top View, we KEEP REPLACING the value.
- Since BFS processes nodes level by level, deeper levels are
  encountered later.
- Therefore, the final value stored for each HD represents the
  bottommost node encountered at that horizontal distance.
- Use map<HD, value> so that the final answer is automatically
  arranged from leftmost HD to rightmost HD.

Time Complexity:
- O(n log n) : BFS processes n nodes and each map operation costs O(log n)
- O(n)       : Traverse the map to construct the answer
- Overall: O(n log n)

Space Complexity:
- O(n) : Queue can contain O(n) nodes
- O(n) : Map can contain O(n) horizontal distances
- Overall: O(n)

Revision Keywords:
- Binary Tree
- Bottom View
- BFS
- Horizontal Distance
- Level Order Traversal
- Last Node at HD
- Ordered Map
- Vertical Projection
*/

class Solution {
public:

    vector<int> bottomView(Node* root) {

        vector<int> ans;

        if(!root)
            return ans;

        map<int, int> mp;

        queue<pair<Node*, int>> q;

        // Root has horizontal distance 0
        q.push({root, 0});

        while(!q.empty()) {

            auto [node, hd] = q.front();
            q.pop();

            // Keep replacing:
            // later BFS nodes are at deeper/equal levels
            mp[hd] = node->data;

            if(node->left)
                q.push({node->left, hd - 1);

            if(node->right)
                q.push({node->right, hd + 1);
        }

        // map keeps HD sorted
        for(auto& it : mp)
            ans.push_back(it.second);

        return ans;
    }
};
