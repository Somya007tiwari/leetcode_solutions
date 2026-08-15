class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        int xr = 0;
        int countZero = 0;

        for(int x : nums) {
            xr ^= x;

            if(x == 0)
                countZero++;
        }

        if(xr != 0)
            return n;

        if(countZero == n)
            return 0;

        return n - 1;
    }
};