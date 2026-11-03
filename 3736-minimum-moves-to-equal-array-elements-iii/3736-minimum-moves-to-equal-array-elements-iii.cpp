class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the maximum element
        int maxi = *max_element(nums.begin(), nums.end());

        // Step 2: Calculate total operations
        int ans = 0;

        for (int num : nums) {
            ans += maxi - num;
        }

        return ans;
    }
};