
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // Square every element
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        // Sort in ascending order
        sort(nums.begin(), nums.end());

        long long ans = 0;

        // Subtract the smallest n/2 squares
        for (int i = 0; i < n / 2; i++) {
            ans -= nums[i];
        }

        // Add the remaining larger squares
        for (int i = n / 2; i < n; i++) {
            ans += nums[i];
        }

        return ans;
    }
};
