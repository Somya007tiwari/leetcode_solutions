class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long k = 1;
        while (true) {
            // threshold = 10^(3k)
            long long threshold = 1;
            bool overflow = false;
            for (int i = 0; i < 3 * k; i++) {
                if (threshold > n / 10 + 1) { overflow = true; break; }
                threshold *= 10;
            }
            if (overflow || threshold > n) break;
            total += n - threshold + 1;
            k++;
        }
        return total;
    }
};