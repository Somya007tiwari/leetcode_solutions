class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Step 1: Check karo string already sorted hai ya nahi
        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }

        // Agar already sorted hai, koi operation nahi chahiye
        if (sorted) return 0;

        // Length 2 mein poori string ko sort nahi kar sakte
        if (n == 2) return -1;

        // Step 2: Minimum aur maximum character find karo
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Step 3: Minimum first ya maximum last par hai
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Step 4: Minimum ya maximum middle mein present hai
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // Step 5: Baaki cases mein 3 operations lagenge
        return 3;
    }
};
