class Solution {
public:
    long long countCommas(int n) {
        long long total = 0;
        string s = to_string(n);
        int len = s.size();
        for (int digits = 4; digits <= len; digits++) {
            long long lower = 1;
            for (int i = 0; i < digits - 1; i++) lower *= 10;
            long long upper = min((long long)n, lower * 10 - 1);
            long long countNumbers = upper - lower + 1;
            if (countNumbers <= 0) continue;
            long long commasPerNumber = (digits - 1) / 3;
            total += countNumbers * commasPerNumber;
        }
        return total;
    }
};