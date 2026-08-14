class Solution {
public:
    bool canConvertString(string s, string t, int k) {

        if (s.size() != t.size())
            return false;

        vector<int> used(26, 0);

        for (int i = 0; i < s.size(); i++) {

            int diff = (t[i] - s[i] + 26) % 26;

            if (diff == 0)
                continue;

            int move = diff + 26 * used[diff];

            if (move > k)
                return false;

            used[diff]++;
        }

        return true;
    }
};