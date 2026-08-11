/*
GFG - Minimum Spanning Tree (Kruskal's Algorithm)

Approach:
- Sort all edges in increasing order of their weights.
- Use Disjoint Set Union (DSU / Union-Find) to keep track of
  which vertices already belong to the same connected component.
- For every edge:
    - Find the ultimate parent of both endpoints.
    - If both endpoints already have the same parent, adding this
      edge would create a cycle, so skip it.
    - Otherwise, union the two components and add the edge weight
      to the MST sum.
- Use:
    - Path Compression in findParent()
    - Union by Rank in Union()
- Continue until all required MST edges are selected.

Time Complexity:
- O(E log E) : Sort all edges by weight
- O(E × α(V)) : DSU operations for all edges
- Overall: O(E log E)

Space Complexity:
- O(V) : Parent array
- O(V) : Rank array
- Overall: O(V)

Revision Keywords:
- Kruskal's Algorithm
- Minimum Spanning Tree
- MST
- DSU
- Disjoint Set Union
- Union-Find
- Path Compression
- Union by Rank
- Cycle Detection
- Greedy Algorithm
*/

class Solution {
public:

    int findParent(int i, vector<int>& parent) {

        if(i == parent[i])
            return i;

        // Path Compression
        return parent[i] = findParent(parent[i], parent);
    }

    bool Union(int x,
               int y,
               vector<int>& parent,
               vector<int>& rank) {

        int xp = findParent(x, parent);
        int yp = findParent(y, parent);

        // Same component -> adding edge creates cycle
        if(xp == yp)
            return false;

        // Union by Rank
        if(rank[xp] > rank[yp])
            parent[yp] = xp;

        else if(rank[xp] < rank[yp])
            parent[xp] = yp;

        else {
            parent[yp] = xp;
            rank[xp]++;
        }

        return true;
    }

    int kruskal(vector<vector<int>>& edges,
                int V) {

        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Initially every node is its own component
        for(int i = 0; i < V; i++)
            parent[i] = i;

        int sum = 0;

        for(auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            // Add edge only if it doesn't form a cycle
            if(Union(u, v, parent, rank))
                sum += wt;
        }

        return sum;
    }

    int spanningTree(int V,
                     vector<vector<int>>& edges) {

        // Sort edges by weight
        auto comp = [&](vector<int>& a,
                        vector<int>& b) {

            return a[2] < b[2];
        };

        sort(edges.begin(),
             edges.end(),
             comp);

        return kruskal(edges, V);
    }
};
