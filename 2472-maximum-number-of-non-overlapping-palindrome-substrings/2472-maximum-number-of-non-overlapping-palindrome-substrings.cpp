class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            
            // odd length palindromes centered at i
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break; // greedy: take the shortest valid palindrome first
                }
                l--; r++;
            }
            
            // even length palindromes centered between i, i+1
            l = i; r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break;
                }
                l--; r++;
            }
        }
        
        return dp[n];
    }
};