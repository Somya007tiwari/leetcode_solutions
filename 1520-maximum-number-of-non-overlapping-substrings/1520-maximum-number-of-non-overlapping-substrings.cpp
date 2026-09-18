class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<int> intervalEnd(n, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] != i) continue;      // only anchor at first occurrence

            int start = i, end = last[c];
            bool valid = true;
            for (int j = i; j <= end; j++) {
                int cj = s[j] - 'a';
                if (first[cj] < start) { valid = false; break; }  // needs to extend LEFT -> invalid here
                if (last[cj] > end) end = last[cj];               // extend RIGHT as needed
            }
            intervalEnd[i] = valid ? end : -1;
        }

        vector<string> ans;
        function<void(int,int)> solve = [&](int l, int r) {
            int i = l;
            while (i <= r) {
                if (intervalEnd[i] == -1 || intervalEnd[i] > r) { i++; continue; }
                int e = intervalEnd[i];
                int before = ans.size();
                solve(i + 1, e - 1);
                if ((int)ans.size() == before)
                    ans.push_back(s.substr(i, e - i + 1));
                i = e + 1;
            }
        };

        solve(0, n - 1);
        return ans;
    }
};