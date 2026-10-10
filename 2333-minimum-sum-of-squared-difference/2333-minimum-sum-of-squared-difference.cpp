class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        const int M = 100000;
        vector<long long> cnt(M + 2, 0);
        for (int i = 0; i < n; i++) cnt[abs(nums1[i] - nums2[i])]++;

        long long k = (long long)k1 + k2;
        for (int d = M; d >= 1 && k > 0; d--) {
            if (cnt[d] == 0) continue;
            if (k >= cnt[d]) {
                k -= cnt[d];
                cnt[d - 1] += cnt[d];
                cnt[d] = 0;
            } else {
                cnt[d] -= k;
                cnt[d - 1] += k;
                k = 0;
            }
        }
        long long ans = 0;
        for (long long d = 1; d <= M; d++) ans += cnt[d] * d * d;
        return ans;
    }
};