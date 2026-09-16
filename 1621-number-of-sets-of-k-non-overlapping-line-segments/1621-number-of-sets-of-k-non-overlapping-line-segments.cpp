class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        
        // dp[j][0] = j segments done, current point NOT in open segment
        // dp[j][1] = j segments done, current point IS right end of open segment
        vector<long long> cur0(k + 1, 0), cur1(k + 1, 0);
        cur0[0] = 1; // point 0, 0 segments, not in any segment
        
        for (int i = 1; i < n; i++) {
            vector<long long> nxt0(k + 1, 0), nxt1(k + 1, 0);
            for (int j = 0; j <= k; j++) {
                // nxt0[j]: close/skip — was open(close it) or was closed(stay)
                nxt0[j] = (cur0[j] + cur1[j]) % MOD;
                
                // nxt1[j]: point i is right end of segment j
                // Case 1: extend existing open segment (was in state 1 with j segs)
                nxt1[j] = cur1[j];
                // Case 2: start new segment ending at i
                //   previous point was NOT in segment (state 0, j-1 segs done)
                //   OR previous point WAS closing a segment (state 1, j-1 segs)
                //   → both allowed because segments can share endpoints!
                if (j > 0) {
                    nxt1[j] = (nxt1[j] + cur0[j-1] + cur1[j-1]) % MOD;
                    //                   ^^^^^^^^^^^   ^^^^^^^^^^^
                    //                   fresh start   shared endpoint start
                }
            }
            cur0 = nxt0;
            cur1 = nxt1;
        }
        
        return (cur0[k] + cur1[k]) % MOD;
    }
};