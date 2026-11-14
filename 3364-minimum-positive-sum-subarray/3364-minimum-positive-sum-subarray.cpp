
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int ans = INT_MAX;

        // Try every possible window size from l to r
        for (int len = l; len <= r; len++) {

            int sum = 0;

            // Calculate sum of first window
            for (int i = 0; i < len; i++) {
                sum += nums[i];
            }

            // Check if sum is positive
            if (sum > 0) {
                ans = min(ans, sum);
            }

            // Slide the window
            for (int i = len; i < n; i++) {

                // Remove previous element
                // Add new element
                sum += nums[i] - nums[i - len];

                // Update minimum positive sum
                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        // If no positive sum is found
        return ans == INT_MAX ? -1 : ans;
    }
};
