/*
GeeksforGeeks - Topological Sort (Kahn's Algorithm / BFS)

Approach:
- Represent the graph using an adjacency list.
- Compute the indegree (number of incoming edges) for every vertex.
- Push all vertices having indegree = 0 into a queue.
- Repeatedly:
    - Remove a vertex from the queue.
    - Add it to the topological ordering.
    - Reduce the indegree of all its adjacent vertices.
    - If any adjacent vertex's indegree becomes 0,
      push it into the queue.
- Continue until the queue becomes empty.
- The generated order is a valid Topological Ordering
  for a Directed Acyclic Graph (DAG).

Time Complexity:
- O(E) : Build adjacency list and indegree array
- O(V) : Initialize queue with indegree 0 vertices
- O(V + E) : BFS traversal (each vertex and edge processed once)
- Overall: O(V + E)

Space Complexity:
- O(V + E) : Adjacency list
- O(V)     : Indegree array
- O(V)     : Queue
- O(V)     : Topological order vector
- Overall: O(V + E)

Revision Keywords:
- Kahn's Algorithm
- Topological Sort
- BFS
- Indegree
- DAG
- Queue
- Directed Graph
*/

class Solution {
public:

    vector<int> bfs(vector<vector<int>>& adj,
                    vector<int>& inDegree,
                    int V) {

        queue<int> q;
        vector<int> topo;

        // Push all vertices with indegree 0
        for(int i = 0; i < V; i++) {

            if(inDegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int next : adj[node]) {

                inDegree[next]--;

                if(inDegree[next] == 0)
                    q.push(next);
            }
        }

        return topo;
    }

    vector<int> topoSort(int V,
                         vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<int> inDegree(V);

        // Build graph
        for(auto& e : edges) {

            inDegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }

        return bfs(adj, inDegree, V);
    }
};
