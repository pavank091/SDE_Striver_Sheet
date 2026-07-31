/*
LeetCode 207 - Course Schedule( Detect Cycle In A Directed Graph)

Approach:
- Represent courses as a directed graph.
- An edge u → v means u must be completed before v.
- Use DFS to detect a cycle in the directed graph.
- Maintain two arrays:
    - visited[] : Node has been explored before.
    - path[]    : Node is currently in the DFS recursion stack.
- For every adjacent node:
    - If it is unvisited:
        - Perform DFS.
        - If a cycle is found, return false.
    - If it is already in the current recursion path:
        - A back edge is found, indicating a cycle.
- Remove the current node from the recursion path while backtracking.
- If no cycle exists, all courses can be completed.

Time Complexity:
- O(E) : Build adjacency list
- O(V) : Visit every vertex once
- O(E) : Traverse every edge once
- Overall: O(V + E)

Space Complexity:
- O(V) : Visited array
- O(V) : Recursion path array
- O(V) : DFS recursion stack
- O(V + E) : Adjacency list
- Overall: O(V + E)

Revision Keywords:
- Directed Graph
- DFS
- Cycle Detection
- Recursion Stack
- Path Visited
- Back Edge
- Topological Sort
*/

class Solution {
public:

    bool dfs(vector<vector<int>>& adj,
             vector<bool>& visited,
             int node,
             vector<bool>& path) {

        visited[node] = true;
        path[node] = true;

        for(int next : adj[node]) {

            if(!visited[next]) {

                if(!dfs(adj, visited, next, path))
                    return false;
            }

            // Back edge found
            else if(path[next]) {

                return false;
            }
        }

        // Backtracking
        path[node] = false;

        return true;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        int V = numCourses;

        vector<vector<int>> adj(V);

        // Build directed graph
        for(auto& e : prerequisites)
            adj[e[1]].push_back(e[0]);

        vector<bool> visited(V, false);
        vector<bool> path(V, false);

        // Handle disconnected components
        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                if(!dfs(adj, visited, i, path))
                    return false;
            }
        }

        return true;
    }
};
