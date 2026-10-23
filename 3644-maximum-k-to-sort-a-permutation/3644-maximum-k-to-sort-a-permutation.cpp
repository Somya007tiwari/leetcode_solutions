
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;

        for (int i = 0; i < nums.size(); i++) {
            // Agar element apni correct position par nahi hai
            if (nums[i] != i) {
                // Sabhi misplaced elements ka bitwise AND
                ans &= nums[i];
            }
        }

        // Agar array already sorted hai
        return max(ans, 0);
    }
};
