class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        // dp[i][j][0] = ways to reach (i,j) moving right
        // dp[i][j][1] = ways to reach (i,j) moving down
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, 0))
        );

        // Start from (0,0)
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Handle starting cell separately
                if (i == 0 && j == 0) {
                    if (j + 1 < n) {
                        dp[i][j + 1][0] = 1;
                    }

                    if (i + 1 < m) {
                        dp[i + 1][j][1] = 1;
                    }

                    continue;
                }

                // Number of ways to enter this cell
                int right = dp[i][j][0];
                int down = dp[i][j][1];

                if (grid[i][j] == 1) {

                    // Mirror: right -> down
                    if (right > 0 && i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + right) % MOD;
                    }

                    // Mirror: down -> right
                    if (down > 0 && j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + down) % MOD;
                    }
                }
                else {

                    // Empty cell: move right
                    if (j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + right + down) % MOD;
                    }

                    // Empty cell: move down
                    if (i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + right + down) % MOD;
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
    }
};