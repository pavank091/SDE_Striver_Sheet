/*
GFG - Detect Cycle in an Undirected Graph (BFS)

Approach:
- Convert the edge list into an adjacency list.
- Traverse every connected component using BFS.
- Store both the current node and its parent in the queue.
- For every adjacent node:
    - If it is unvisited:
        - Mark it visited and push {neighbor, currentNode}.
    - If it is already visited and is NOT the parent:
        - A cycle is detected.
- If no component contains a cycle, return false.

Time Complexity:
- O(E) : Build adjacency list
- O(V) : Visit every vertex once
- O(E) : Traverse every edge once
- Overall: O(V + E)

Space Complexity:
- O(V) : Visited array
- O(V) : BFS queue (worst case)
- O(V + E) : Adjacency list
- Overall: O(V + E)

Revision Keywords:
- Graph
- BFS
- Undirected Graph
- Parent Tracking
- Cycle Detection
- Connected Components
*/

class Solution {
public:

    bool bfs(vector<vector<int>>& adj,
             vector<bool>& visited,
             int node,
             int parent) {

        queue<pair<int, int>> q;

        q.push({node, parent});
        visited[node] = true;

        while(!q.empty()) {

            auto [node, parent] = q.front();
            q.pop();

            for(int next : adj[node]) {

                if(!visited[next]) {

                    visited[next] = true;
                    q.push({next, node});
                }
                else if(next != parent) {
                    return true;
                }
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
               bfs(adj, visited, i, -1))
                return true;
        }

        return false;
    }
};
