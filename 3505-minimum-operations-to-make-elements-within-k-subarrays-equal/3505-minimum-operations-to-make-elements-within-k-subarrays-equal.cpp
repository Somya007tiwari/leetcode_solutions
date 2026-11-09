
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;

        // Balance two halves
        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();

                left.erase(left.find(val));
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while (left.size() < right.size()) {
                int val = *right.begin();

                right.erase(right.find(val));
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }
        };

        // Insert element
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }

            balance();
        };

        // Remove element
        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }

            balance();
        };

        // Cost to make current window equal
        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * left.size() - sumLeft
                 + sumRight - median * right.size();
        };

        // Calculate cost of every window
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();

                remove(nums[i - x + 1]);
            }
        }

        // DP: dp[i][j] = minimum cost using first i elements
        // and selecting j non-overlapping subarrays

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {

                // Skip current element
                dp[i][j] = dp[i - 1][j];

                // Select window ending at i-1
                if (j > 0 && i >= x) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};

