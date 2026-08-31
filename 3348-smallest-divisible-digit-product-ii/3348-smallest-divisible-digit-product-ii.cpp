class Solution {
public:
    unordered_map<long long, int> memoSteps;

    long long encode(int a2, int a3, int a5, int a7) {
        return (((long long)a2 * 60 + a3) * 40 + a5) * 30 + a7;
    }

    int minSteps(int a2, int a3, int a5, int a7) {
        if (a2 <= 0 && a3 <= 0 && a5 <= 0 && a7 <= 0) return 0;
        long long key = encode(max(a2,0), max(a3,0), max(a5,0), max(a7,0));
        auto it = memoSteps.find(key);
        if (it != memoSteps.end()) return it->second;
        memoSteps[key] = INT_MAX; // guard against reentry
        int best = INT_MAX;
        for (int d = 2; d <= 9; d++) {
            int nd = d, na2 = a2, na3 = a3, na5 = a5, na7 = a7;
            while (na2 > 0 && nd % 2 == 0) { nd /= 2; na2--; }
            while (na3 > 0 && nd % 3 == 0) { nd /= 3; na3--; }
            while (na5 > 0 && nd % 5 == 0) { nd /= 5; na5--; }
            while (na7 > 0 && nd % 7 == 0) { nd /= 7; na7--; }
            if (na2 == a2 && na3 == a3 && na5 == a5 && na7 == a7) continue;
            int sub = minSteps(na2, na3, na5, na7);
            if (sub != INT_MAX) best = min(best, 1 + sub);
        }
        memoSteps[key] = best;
        return best;
    }

    void applyDigit(int d, int &a2, int &a3, int &a5, int &a7) {
        while (a2 > 0 && d % 2 == 0) { d /= 2; a2--; }
        while (a3 > 0 && d % 3 == 0) { d /= 3; a3--; }
        while (a5 > 0 && d % 5 == 0) { d /= 5; a5--; }
        while (a7 > 0 && d % 7 == 0) { d /= 7; a7--; }
    }

    string buildSuffix(int len, int a2, int a3, int a5, int a7) {
        string out(len, '1');
        for (int i = 0; i < len; i++) {
            int rem = len - i - 1;
            for (int d = 1; d <= 9; d++) {
                int na2 = a2, na3 = a3, na5 = a5, na7 = a7;
                applyDigit(d, na2, na3, na5, na7);
                if (minSteps(na2, na3, na5, na7) <= rem) {
                    out[i] = char('0' + d);
                    a2 = na2; a3 = na3; a5 = na5; a7 = na7;
                    break;
                }
            }
        }
        return out;
    }

    // smallest zero-free number of exactly 'len' digits with product divisible by requirement
    string smallestOfLength(int len, int e2, int e3, int e5, int e7) {
        if (minSteps(e2, e3, e5, e7) > len) return "";
        return buildSuffix(len, e2, e3, e5, e7);
    }

    string smallestNumber(string num, long long t) {
        int e2 = 0, e3 = 0, e5 = 0, e7 = 0;
        while (t % 2 == 0) { e2++; t /= 2; }
        while (t % 3 == 0) { e3++; t /= 3; }
        while (t % 5 == 0) { e5++; t /= 5; }
        while (t % 7 == 0) { e7++; t /= 7; }
        if (t != 1) return "-1";

        int n = num.size();

        // 1) check num itself
        bool zeroFree = num.find('0') == string::npos;
        if (zeroFree) {
            int a2 = e2, a3 = e3, a5 = e5, a7 = e7;
            for (char c : num) applyDigit(c - '0', a2, a3, a5, a7);
            if (a2 <= 0 && a3 <= 0 && a5 <= 0 && a7 <= 0) return num;
        }

        // 2) try same length, increasing some digit
        int firstZero = n;
        for (int i = 0; i < n; i++) if (num[i] == '0') { firstZero = i; break; }

        vector<array<int,4>> prefixState(firstZero + 1);
        prefixState[0] = {e2, e3, e5, e7};
        for (int i = 0; i < firstZero; i++) {
            auto st = prefixState[i];
            applyDigit(num[i] - '0', st[0], st[1], st[2], st[3]);
            prefixState[i + 1] = st;
        }

        for (int pos = firstZero; pos >= 0; pos--) {
            auto st = prefixState[pos];
            int remLen = n - pos - 1;
            int startD = (pos == firstZero) ? 1 : (num[pos] - '0' + 1);
            for (int d = startD; d <= 9; d++) {
                int a2 = st[0], a3 = st[1], a5 = st[2], a7 = st[3];
                applyDigit(d, a2, a3, a5, a7);
                if (minSteps(a2, a3, a5, a7) <= remLen) {
                    return num.substr(0, pos) + char('0' + d) + buildSuffix(remLen, a2, a3, a5, a7);
                }
            }
        }

        // 3) no same-length answer: find smallest length >= n+1 that works
        // minimum possible length overall is minSteps(e2,e3,e5,e7); if that's <= n it would've
        // been found in same-length search (since buildSuffix pads with useful digits), so search len = n+1, n+2, ...
        int base = minSteps(e2, e3, e5, e7);
        int len = max(base, n + 1);
        // safety cap: exponents are small (t <= 1e14), so base is small; but ensure we don't loop forever
        for (; len <= n + 60; len++) {
            string res = smallestOfLength(len, e2, e3, e5, e7);
            if (!res.empty()) return res;
        }

        return "-1";
    }
};