class Solution {
public:
    using ll = long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 911382323;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<ll> p1(n + 1, 1), p2(n + 1, 1);
        vector<ll> h1(n + 1, 0), h2(n + 1, 0);

        // Precompute powers and prefix hashes
        for (int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;

            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;
        }

        // Check whether a unique subarray exists
        auto check = [&](int len) {
            unordered_map<ll, int> freq;

            for (int i = 0; i + len <= n; i++) {
                int j = i + len;

                ll hash1 = (h1[j] -
                    h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

                ll hash2 = (h2[j] -
                    h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

                ll hash = hash1 * MOD2 + hash2;

                freq[hash]++;
            }

            for (auto &it : freq) {
                if (it.second == 1)
                    return true;
            }

            return false;
        };

        // Binary Search
        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};