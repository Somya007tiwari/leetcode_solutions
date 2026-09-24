class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sum = 0;

            while (num > 0) {
                sum += num % 10;   // last digit add karo
                num /= 10;         // last digit hata do
            }

            if (sum == i) return i;
        }
        return -1;
    }
};