class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // Step 1: Array ko sort karo
        sort(nums.begin(), nums.end());

        // Step 2: Median find karo
        int n = nums.size();
        int median = nums[n / 2];

        // Step 3: Sabhi elements ko median ke equal karne ke moves
        int moves = 0;

        for (int i = 0; i < n; i++) {
            moves += abs(nums[i] - median);
        }

        return moves;
    }
};