class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<long long> cnt(n + 1, 0), mult(n + 1, 0);
        for (auto& it : items) cnt[it[0]]++;
        for (int f = 1; f <= n; f++)
            for (int k = f; k <= n; k += f)
                mult[f] += cnt[k];

        long long m = LLONG_MAX;
        for (auto& it : items) m = min(m, (long long)it[1]);

        vector<pair<long long, long long>> v;           // {price, g}
        for (auto& it : items) {
            long long g = mult[it[0]] - 1;
            if (g > 0 && it[1] < 2 * m) v.push_back({it[1], g});
        }
        sort(v.begin(), v.end());

        long long rem = budget, D = 0;
        for (auto& [p, g] : v) {
            long long t = min(g, rem / p);
            D += t;
            rem -= t * p;
            if (t < g) break;                           // can't afford the next double
        }
        return 2 * D + rem / m;
    }
};