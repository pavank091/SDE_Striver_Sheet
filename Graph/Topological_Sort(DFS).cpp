/*
GeeksforGeeks - Topological Sort (DFS)

Approach:
- Represent the graph using an adjacency list.
- Perform DFS from every unvisited vertex.
- During DFS:
    - Visit all adjacent vertices first.
    - After exploring all descendants, push the current node
      onto a stack.
- This follows the Postorder DFS property:
    - A node is pushed only after all its dependencies are processed.
- Finally, pop all elements from the stack to obtain the
  Topological Ordering.

Time Complexity:
- O(E) : Build adjacency list
- O(V) : Visit every vertex once
- O(E) : Traverse every edge once during DFS
- O(V) : Pop all vertices from the stack
- Overall: O(V + E)

Space Complexity:
- O(V + E) : Adjacency list
- O(V)     : Visited array
- O(V)     : DFS recursion stack (worst case)
- O(V)     : Stack storing topological order
- Overall: O(V + E)

Revision Keywords:
- DFS
- Topological Sort
- Postorder DFS
- Stack
- DAG
- Directed Graph
- Finish Time
*/

class Solution {
public:

    void dfs(vector<vector<int>>& adj,
             vector<bool>& visited,
             int node,
             stack<int>& st) {

        visited[node] = true;

        for(int next : adj[node]) {

            if(!visited[next])
                dfs(adj, visited, next, st);
        }

        // Push after visiting all neighbors
        st.push(node);
    }

    vector<int> topoSort(int V,
                         vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // Build graph
        for(auto& e : edges)
            adj[e[0]].push_back(e[1]);

        vector<bool> visited(V, false);

        stack<int> st;

        // Handle disconnected components
        for(int i = 0; i < V; i++) {

            if(!visited[i])
                dfs(adj, visited, i, st);
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
