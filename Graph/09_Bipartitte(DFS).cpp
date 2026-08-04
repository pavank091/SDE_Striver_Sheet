/*
LeetCode 785 - Is Graph Bipartite?

Approach:
- Use DFS along with the 2-Coloring technique.
- Each node is assigned one of two colors:
    - 0 (Red)
    - 1 (Blue)
- For every adjacent node:
    - If it has the same color as the current node,
      the graph is not bipartite.
    - If it is uncolored:
        - Assign the opposite color.
        - Continue DFS.
- Since the graph may be disconnected,
  start DFS from every unvisited node.
- If all connected components can be colored successfully,
  the graph is bipartite.

Time Complexity:
- O(V) : Visit every vertex once
- O(E) : Traverse every edge once
- Overall: O(V + E)

Space Complexity:
- O(V) : Color array
- O(V) : DFS recursion stack (worst case)
- Overall: O(V)

Revision Keywords:
- DFS
- Bipartite Graph
- Two Coloring
- Graph Coloring
- Opposite Color
- Connected Components
*/
