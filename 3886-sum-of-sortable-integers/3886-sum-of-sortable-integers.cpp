
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // Prefix maximum
        vector<int> prefMax(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // Suffix minimum
        vector<int> suffMin(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // Prefix count of descending adjacent pairs
        vector<int> prefDrop(n, 0);
        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        // Check whether block size k is sortable
        auto check = [&](int k) -> bool {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                // Block ke andar descending pairs count karo
                int drops = prefDrop[end] - prefDrop[start];

                // Circular boundary bhi check karo
                if (nums[end] > nums[start]) {
                    drops++;
                }

                // Ek se zyada circular descents hain
                if (drops > 1) {
                    return false;
                }

                // Adjacent blocks ke beech order check karo
                if (start > 0 && prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int ans = 0;

        // Sirf n ke divisors check karne hain
        for (int d = 1; d <= n / d; d++) {
            if (n % d == 0) {
                // Chhota divisor
                if (check(d)) {
                    ans += d;
                }

                // Bada divisor
                int other = n / d;

                if (other != d && check(other)) {
                    ans += other;
                }
            }
        }

        return ans;
    }
};
