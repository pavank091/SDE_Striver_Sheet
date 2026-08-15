/*
GFG - Top View of Binary Tree

Approach:
- Assign a Horizontal Distance (HD) to every node:
    - Root → HD = 0
    - Left child → HD - 1
    - Right child → HD + 1
- Use BFS (Level Order Traversal).
- For every horizontal distance:
    - Store only the FIRST node encountered.
    - Because BFS visits nodes level by level, the first node
      encountered at a horizontal distance is the topmost node.
- Store the nodes in a map<HD, value>.
    - map automatically keeps horizontal distances sorted.
- Finally, traverse the map from left to right to obtain the Top View.

Time Complexity:
- O(n log n) : BFS visits all n nodes, and each map insertion/search costs O(log n)
- O(n)       : Traversing the map to build the answer
- Overall: O(n log n)

Space Complexity:
- O(n) : Queue can contain O(n) nodes
- O(n) : Map can contain O(n) different horizontal distances
- Overall: O(n)

Revision Keywords:
- Binary Tree
- Top View
- BFS
- Horizontal Distance
- Level Order Traversal
- First Node at HD
- Ordered Map
- Vertical Projection
*/

class Solution {
public:

    vector<int> topView(Node* root) {

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

            // Store only the first node at this HD
            if(mp.find(hd) == mp.end())
                mp[hd] = node->data;

            if(node->left)
                q.push({node->left, hd - 1});

            if(node->right)
                q.push({node->right, hd + 1});
        }

        // map keeps HDs sorted
        for(auto& it : mp)
            ans.push_back(it.second);

        return ans;
    }
};
