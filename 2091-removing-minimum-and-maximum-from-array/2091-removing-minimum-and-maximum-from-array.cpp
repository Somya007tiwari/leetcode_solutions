class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);
        
        // Option 1: remove both from the front
        int fromFront = j + 1;
        
        // Option 2: remove both from the back
        int fromBack = n - i;
        
        // Option 3: remove one from front (the earlier one) and one from back (the later one)
        int both = (i + 1) + (n - j);
        
        return min({fromFront, fromBack, both});
    }
};