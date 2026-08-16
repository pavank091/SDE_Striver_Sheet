/*
LeetCode 987 - Vertical Order Traversal of a Binary Tree

Approach:
- Use BFS (Level Order Traversal).
- Assign coordinates to every node:
    - Root       → (row = 0, col = 0)
    - Left child → (row + 1, col - 1)
    - Right child→ (row + 1, col + 1)
- Store nodes using:
      map<column, map<row, multiset<value>>>
- Why this structure?
    1. map by column:
       → gives columns from left to right.
    2. map by row:
       → gives nodes from top to bottom.
    3. multiset by value:
       → when nodes have the same row AND same column,
         values must be sorted.
- BFS also ensures nodes are processed level by level.
- Finally, traverse the maps in sorted order and collect
  all values belonging to each vertical column.

Time Complexity:
- O(n log n) : Every node is inserted into a map/multiset
- O(n log n) : Ordered traversal/insertion across coordinate maps
- Overall: O(n log n)

Space Complexity:
- O(n) : Queue stores nodes
- O(n) : map + multiset stores every node
- Overall: O(n)

Revision Keywords:
- Vertical Traversal
- BFS
- Level Order
- Horizontal Distance
- Row / Column Coordinates
- Ordered Map
- Multiset
- Same Row + Same Column
- Coordinate Mapping
*/

class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // node, {column, row}
        queue<pair<TreeNode*, pair<int,int>>> q;

        // column → row → sorted values
        map<int, map<int, multiset<int>>> dp;

        q.push({root, {0, 0}});

        while(!q.empty()) {

            auto [node, coord] = q.front();
            auto [col, row] = coord;
            q.pop();

            // Store value at (column, row)
            dp[col][row].insert(node->val);

            if(node->left)
                q.push({
                    node->left,
                    {col - 1, row + 1}
                });

            if(node->right)
                q.push({
                    node->right,
                    {col + 1, row + 1}
                });
        }

        vector<vector<int>> result;

        // Columns → left to right
        for(auto& column : dp) {

            vector<int> temp;

            // Rows → top to bottom
            for(auto& row : column.second) {

                // Same row + same column → sorted values
                temp.insert(
                    temp.end(),
                    row.second.begin(),
                    row.second.end()
                );
            }

            result.push_back(temp);
        }

        return result;
    }
};
