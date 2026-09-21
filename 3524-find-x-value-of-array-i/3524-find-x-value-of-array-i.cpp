class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0), cnt(k, 0);

        for (int x : nums) {
            int v = x % k;
            vector<long long> nxt(k, 0);

            for (int r = 0; r < k; r++) {
                if (cnt[r]) nxt[(r * v) % k] += cnt[r];
            }
            nxt[v]++;               // naya subarray [x]

            for (int r = 0; r < k; r++) res[r] += nxt[r];
            cnt = nxt;
        }
        return res;
    }
};