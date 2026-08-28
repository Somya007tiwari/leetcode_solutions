class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                oddCount++;
                oddChar = i;
            }
        }

        string mid = "";
        if (n % 2 == 0) {
            if (oddCount != 0) return "";
        } else {
            if (oddCount != 1) return "";
            mid = string(1, char('a' + oddChar));
        }

        int half[26];
        for (int i = 0; i < 26; i++) half[i] = cnt[i] / 2;

        int m = n / 2;
        string targetHalf = target.substr(0, m);

        int counts[26];
        memcpy(counts, half, sizeof(half));
        int L = 0;
        for (int i = 0; i < m; i++) {
            int idx = targetHalf[i] - 'a';
            if (counts[idx] > 0) {
                counts[idx]--;
                L++;
            } else {
                break;
            }
        }

        if (L == m) {
            string H = targetHalf;
            string rev = H;
            reverse(rev.begin(), rev.end());
            string P = H + mid + rev;
            if (P > target) return P;
        }

        int curCounts[26];
        memcpy(curCounts, counts, sizeof(counts));
        string result = "";
        bool found = false;

        for (int i = L; i >= 0; i--) {
            if (i < m) {
                int tIdx = targetHalf[i] - 'a';
                int foundC = -1;
                for (int c = tIdx + 1; c < 26; c++) {
                    if (curCounts[c] > 0) {
                        foundC = c;
                        break;
                    }
                }
                if (foundC != -1) {
                    int remaining[26];
                    memcpy(remaining, curCounts, sizeof(curCounts));
                    remaining[foundC]--;

                    string suffix = "";
                    for (int c = 0; c < 26; c++) {
                        suffix += string(remaining[c], char('a' + c));
                    }

                    result = targetHalf.substr(0, i) + char('a' + foundC) + suffix;
                    found = true;
                    break;
                }
            }
            if (i - 1 >= 0) {
                int prevIdx = targetHalf[i - 1] - 'a';
                curCounts[prevIdx]++;
            }
        }

        if (!found) return "";

        string rev = result;
        reverse(rev.begin(), rev.end());
        return result + mid + rev;
    }
};