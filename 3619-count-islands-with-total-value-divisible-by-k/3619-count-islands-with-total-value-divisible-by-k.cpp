class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = 0;
                    queue<pair<int,int>> q;

                    sum += grid[i][j];
                    grid[i][j] = 0;          // visited mark
                    q.push({i, j});

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d], ny = y + dy[d];
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] > 0) {
                                sum += grid[nx][ny];
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }
                    if (sum % k == 0) count++;
                }
            }
        }
        return count;
    }
};