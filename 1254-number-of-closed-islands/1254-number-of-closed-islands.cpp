class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) return false; // escaped the grid
        if (g[i][j] == 1) return true;                         // water, safe
        g[i][j] = 1;                                           // mark visited

        bool a = dfs(g, i + 1, j);
        bool b = dfs(g, i - 1, j);
        bool c = dfs(g, i, j + 1);
        bool d = dfs(g, i, j - 1);
        return a && b && c && d;  // don't short-circuit, the whole island must be visited
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0 && dfs(grid, i, j)) count++;
        return count;
    }
};