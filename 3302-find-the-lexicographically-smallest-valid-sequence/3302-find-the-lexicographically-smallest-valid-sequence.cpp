class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = index in word1 where word2[i] can start
        // as a subsequence from there.
        vector<int> suf(m, -1);

        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                suf[j] = i;
                j--;
            }
        }

        // If we cannot match word2[1...] etc. this is still
        // okay; we will use at most one mismatch.
        vector<int> ans;

        int p = 0;       // current position in word1
        int mismatches = 0;

        for (int i = 0; i < m; i++) {

            bool found = false;

            for (int k = p; k < n; k++) {

                if (word1[k] == word2[i]) {

                    // Exact match.
                    ans.push_back(k);
                    p = k + 1;
                    found = true;
                    break;
                }

                // Try using the one allowed mismatch.
                if (mismatches == 0) {

                    /*
                        After choosing k as the mismatched character,
                        word2[i+1 ...] must be matched exactly.

                        If i is the last character, no suffix is needed.
                    */
                    if (i == m - 1) {
                        ans.push_back(k);
                        p = k + 1;
                        mismatches = 1;
                        found = true;
                        break;
                    }

                    /*
                        We need an exact subsequence for word2[i+1...]
                        after position k.
                    */
                    int need = i + 1;

                    if (suf[need] != -1 && suf[need] > k) {

                        ans.push_back(k);
                        p = k + 1;
                        mismatches = 1;
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                return {};
        }

        return ans;
    }
};