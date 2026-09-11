class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> seen;
        int n = digits.size();
        sort(digits.begin(), digits.end());
        vector<bool> used(n, false);

        for (int i = 0; i < n; i++) {
            if (used[i] || digits[i] == 0) continue;
            if (i > 0 && digits[i] == digits[i-1] && !used[i-1]) continue;
            used[i] = true;

            for (int j = 0; j < n; j++) {
                if (used[j]) continue;
                if (j > 0 && digits[j] == digits[j-1] && !used[j-1]) continue;
                used[j] = true;

                for (int k = 0; k < n; k++) {
                    if (used[k]) continue;
                    if (k > 0 && digits[k] == digits[k-1] && !used[k-1]) continue;
                    if (digits[k] % 2 != 0) continue;

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    seen.insert(num);
                }

                used[j] = false;
            }

            used[i] = false;
        }

        return seen.size();
    }
};