/*
GFG - Detect Cycle in an Undirected Graph (DFS)

Approach:
- Convert the edge list into an adjacency list.
- Traverse every connected component using DFS.
- Mark the current node as visited.
- For every adjacent node:
    - If it is unvisited:
        - Recursively perform DFS with the current node as its parent.
        - If any recursive call detects a cycle, return true.
    - If it is already visited and is NOT the parent:
        - A cycle is detected.
- If all components are traversed without finding a cycle, return false.

Time Complexity:
- O(E) : Build adjacency list
- O(V) : Visit every vertex once
- O(E) : Traverse every edge once
- Overall: O(V + E)

Space Complexity:
- O(V) : Visited array
- O(V) : DFS recursion stack (worst case)
- O(V + E) : Adjacency list
- Overall: O(V + E)

Revision Keywords:
- Graph
- DFS
- Undirected Graph
- Parent Tracking
- Cycle Detection
- Connected Components
*/

class Solution {
public:

    bool dfs(vector<vector<int>>& adj,
             vector<bool>& visited,
             int node,
             int parent) {

        visited[node] = true;

        for(int next : adj[node]) {

            if(!visited[next]) {

                if(dfs(adj, visited, next, node))
                    return true;
            }
            else if(parent != next) {

                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // Build adjacency list
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);

        // Handle disconnected components
        for(int i = 0; i < V; i++) {

            if(!visited[i] &&
               dfs(adj, visited, i, -1))
                return true;
        }

        return false;
    }
};
