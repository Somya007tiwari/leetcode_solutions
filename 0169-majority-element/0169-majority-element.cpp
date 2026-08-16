class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count = 0;
        int candidate = 0;

        // Phase 1: find a candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Phase 2 (optional, only needed if majority isn't guaranteed):
        // verify candidate actually appears > n/2 times
        return candidate; 
    }
};