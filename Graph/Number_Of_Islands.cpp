/*
LeetCode 200 - Number of Islands

Approach:
- Traverse every cell of the grid.
- Whenever an unvisited land cell ('1') is found:
    - Start BFS from that cell.
    - Mark every connected land cell as visited by changing
      '1' to '0'.
- One BFS completely explores one island.
- Increase the island count after every BFS.
- Finally, return the total number of islands.

Time Complexity:
- O(m × n) : Traverse every cell of the grid
- O(m × n) : Every land cell is visited exactly once during BFS
- Overall: O(m × n)

Space Complexity:
- O(min(m, n)) : BFS queue in the worst case
- O(1) : No visited array (grid is modified in-place)
- Overall: O(min(m, n))

Revision Keywords:
- BFS
- Grid Traversal
- Number of Islands
- Multi-Source Traversal
- 4-Directional Movement
- Flood Fill
- Matrix BFS
*/

class Solution {
public:

    int m, n;

    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool check(int r, int c) {

        return r >= 0 &&
               r < m &&
               c >= 0 &&
               c < n;
    }

    void bfs(vector<vector<char>>& grid,
             int r,
             int c) {

        queue<pair<int, int>> q;

        q.push({r, c});
        grid[r][c] = '0';

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int newR = r + row[k];
                int newC = c + col[k];

                if(check(newR, newC) &&
                   grid[newR][newC] == '1') {

                    grid[newR][newC] = '0';
                    q.push({newR, newC});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int islands = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1') {

                    bfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};
