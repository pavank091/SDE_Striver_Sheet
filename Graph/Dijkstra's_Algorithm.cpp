/*
Dijkstra's Algorithm - Single Source Shortest Path

Approach:
- Build/use a weighted adjacency list.
- Initialize all distances as INT_MAX and the source distance as 0.
- Use a min-heap to always process the node with the smallest
  currently known distance.
- For every edge from the current node:
    - Try to relax the edge.
    - If a shorter distance is found, update dist[next]
      and push the updated pair into the priority queue.
- Skip outdated heap entries using:
      if(d > dist[node]) continue;
- Finally, return the shortest distance from the source to every node.

Time Complexity:
- O(V log V) : Priority queue operations for vertices
- O(E log V) : Relaxation of edges and heap insertions
- Overall: O((V + E) log V)

Space Complexity:
- O(V)     : Distance array
- O(E)     : Priority queue can contain multiple entries
- Overall: O(V + E)

Revision Keywords:
- Dijkstra
- Single Source Shortest Path
- Weighted Graph
- Min Heap
- Relaxation
- Distance Array
- Outdated Entry
*/

class Solution {
public:

    vector<int> dijkstra(vector<vector<pair<int,int>>>& adj,
                         int src,
                         int V) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(V, INT_MAX);

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if(d > dist[node])
                continue;

            for(auto& [next, wt] : adj[node]) {

                // Relaxation
                if(dist[node] + wt < dist[next]) {

                    dist[next] = dist[node] + wt;

                    pq.push({dist[next], next});
                }
            }
        }

        return dist;
    }
};
