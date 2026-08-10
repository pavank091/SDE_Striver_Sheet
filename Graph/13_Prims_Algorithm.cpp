/*
GFG - Minimum Spanning Tree (Prim's Algorithm)

Approach:
- Build an undirected weighted adjacency list from the given edges.
- Use Prim's Algorithm with a min-heap.
- The priority queue stores:
      {edgeWeight, {currentNode, parentNode}}
- Start from node 0 with cost 0.
- At every step:
    - Pick the minimum-weight edge from the priority queue.
    - If the node is already visited, skip it.
    - Otherwise:
        - Mark it visited.
        - Add the edge cost to the MST sum.
        - Store its parent.
        - Push all unvisited neighboring nodes into the heap.
- Since the graph is connected, once all V vertices are selected,
  the accumulated sum is the MST weight.

Time Complexity:
- O(E log E) : At most O(E) edges can enter the priority queue
- O(V)       : Each vertex is finalized once
- Overall: O(E log E)
  Often written as O(E log V) for a simple connected graph.

Space Complexity:
- O(V + E) : Adjacency list
- O(V)     : Visited array
- O(V)     : Parent array
- O(E)     : Priority queue in the worst case
- Overall: O(V + E)

Revision Keywords:
- Prim's Algorithm
- Minimum Spanning Tree
- MST
- Min Heap
- Greedy Algorithm
- Edge Weight
- Parent Tracking
- Undirected Weighted Graph
*/

class Solution {
public:

    int primsAlgo(vector<vector<pair<int,int>>>& adj,
                  int V) {

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<bool> visited(V, false);
        vector<int> path(V, -1);

        // {cost, {currentNode, parentNode}}
        pq.push({0, {0, -1}});

        int sum = 0;

        while(!pq.empty()) {

            int cost = pq.top().first;

            auto [node, parent] = pq.top().second;

            pq.pop();

            // Already part of MST
            if(visited[node])
                continue;

            visited[node] = true;

            sum += cost;
            path[node] = parent;

            // Add possible edges to the heap
            for(auto& [next, wt] : adj[node]) {

                if(!visited[next]) {

                    pq.push({
                        wt,
                        {next, node}
                    });
                }
            }
        }

        return sum;
    }

    int spanningTree(int V,
                     vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        // Build undirected adjacency list
        for(auto& e : edges) {

            adj[e[0]].push_back({
                e[1],
                e[2]
            });

            adj[e[1]].push_back({
                e[0],
                e[2]
            });
        }

        return primsAlgo(adj, V);
    }
};
