/*
GeeksforGeeks - Bellman-Ford Algorithm

Approach:
- Use Bellman-Ford to find the shortest distance from a source
  to all vertices in a weighted directed graph.
- Initialize all distances as INT_MAX and dist[src] = 0.
- Relax every edge V - 1 times.
- Why V - 1 times?
    - A shortest simple path can contain at most V - 1 edges.
- Use an early stopping optimization:
    - If no distance is updated during an iteration, the shortest
      distances are already finalized, so return early.
- After V - 1 relaxations, perform one additional relaxation pass:
    - If any distance can still be reduced, a negative weight cycle
      exists.
    - Return {-1}.
- Otherwise, return the shortest distance array.

Time Complexity:
- O(V × E) : Relax all E edges for V - 1 iterations
- O(E)     : One additional pass for negative cycle detection
- Overall: O(V × E)

Space Complexity:
- O(V) : Distance array
- O(1) : Extra variables
- Overall: O(V)

Revision Keywords:
- Bellman-Ford
- Single Source Shortest Path
- Edge Relaxation
- V - 1 Relaxations
- Negative Weight Edges
- Negative Cycle Detection
- Early Stopping
*/

class Solution {
public:

    vector<int> bellmanFord(int V,
                            vector<vector<int>>& edges,
                            int src) {

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;

        // Relax all edges V - 1 times
        for(int i = 0; i < V - 1; i++) {

            bool path = false;

            for(auto& e : edges) {

                int node = e[0];
                int next = e[1];
                int w = e[2];

                // Source node is unreachable
                if(dist[node] == INT_MAX)
                    continue;

                // Relaxation
                if(dist[node] + w < dist[next]) {

                    dist[next] = dist[node] + w;
                    path = true;
                }
            }

            // No update → shortest paths are finalized
            if(!path)
                return dist;
        }

        // Check for negative weight cycle
        for(auto& e : edges) {

            int node = e[0];
            int next = e[1];
            int w = e[2];

            if(dist[node] == INT_MAX)
                continue;

            if(dist[node] + w < dist[next])
                return {-1};
        }

        return dist;
    }
};
