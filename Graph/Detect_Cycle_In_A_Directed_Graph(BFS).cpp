/*
LeetCode 207 - Course Schedule (Kahn's Algorithm / BFS)

Approach:
- Represent courses as a directed graph.
- Compute the indegree of every node.
- Push all nodes having indegree = 0 into a queue.
- Repeatedly:
    - Remove a node from the queue.
    - Count it as processed.
    - Reduce the indegree of all its neighbors.
    - If a neighbor's indegree becomes 0, push it into the queue.
- If all nodes are processed, no cycle exists and all courses
  can be completed.
- Otherwise, a cycle exists, making it impossible to finish all courses.

Time Complexity:
- O(E) : Build adjacency list and indegree array
- O(V) : Initialize queue with zero indegree nodes
- O(V + E) : BFS traversal (every node and edge processed once)
- Overall: O(V + E)

Space Complexity:
- O(V + E) : Adjacency list
- O(V)     : Indegree array
- O(V)     : Queue in the worst case
- Overall: O(V + E)

Revision Keywords:
- Kahn's Algorithm
- Topological Sort
- BFS
- Indegree
- Directed Graph
- Cycle Detection
- Course Schedule
*/

class Solution {
public:

    bool bfs(vector<vector<int>>& adj,
             vector<int>& inDegree,
             int V) {

        queue<int> q;

        // Push all nodes with indegree 0
        for(int i = 0; i < V; i++) {

            if(inDegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for(int next : adj[node]) {

                inDegree[next]--;

                if(inDegree[next] == 0)
                    q.push(next);
            }
        }

        return count == V;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        int V = numCourses;

        vector<vector<int>> adj(V);
        vector<int> inDegree(V);

        // Build graph
        for(auto& e : prerequisites) {
            inDegree[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }

        return bfs(adj, inDegree, V);
    }
};
