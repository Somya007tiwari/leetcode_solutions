
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[j][x] = kya current cell tak XOR x se pahunch sakte hain?
        vector<vector<char>> dp(n, vector<char>(1024, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                vector<char> curr(1024, 0);

                // Starting cell
                if (i == 0 && j == 0) {
                    curr[grid[i][j]] = 1;
                } 
                else {
                    for (int x = 0; x < 1024; x++) {

                        // Upar se ya left se pahunchna possible hai
                        if (dp[j][x] || (j > 0 && dp[j - 1][x])) {

                            // Current cell ki value XOR karo
                            curr[x ^ grid[i][j]] = 1;
                        }
                    }
                }

                // Current cell ke possible XOR values store karo
                dp[j] = curr;
            }
        }

        // Destination par minimum reachable XOR find karo
        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
