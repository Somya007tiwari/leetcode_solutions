class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        vector<vector<bitset<102>>> dp(m, vector<bitset<102>>(n));
        dp[0][0][1] = 1;                       // '(' ke baad balance = 1

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                bitset<102> cur;
                if (i > 0) cur |= dp[i-1][j];
                if (j > 0) cur |= dp[i][j-1];
                dp[i][j] = (grid[i][j] == '(') ? (cur << 1) : (cur >> 1);
            }
        }
        return dp[m-1][n-1][0];
    }
};