
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // 0 ki position find karo
        int zero = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        // Check karo ki 0 se given direction mein
        // elements increasing order mein hain ya nahi
        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        // Case 1: 0 se right direction mein increasing
        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        // Case 2: 0 se left direction mein increasing
        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        // Agar koi valid arrangement nahi hai
        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};
