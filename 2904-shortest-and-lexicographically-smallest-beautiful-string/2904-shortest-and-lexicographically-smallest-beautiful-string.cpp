class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();
        string ans = "";

        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = i; j < n; j++) {

                if (s[j] == '1') {
                    count++;
                }

                // Exactly k ones mil gaye
                if (count == k) {

                    // Starting ke unnecessary zeros hatao
                    int start = i;

                    while (start <= j && s[start] == '0') {
                        start++;
                    }

                    string curr = s.substr(start, j - start + 1);

                    // Shorter substring
                    if (curr.length() < minLen) {
                        minLen = curr.length();
                        ans = curr;
                    }

                    // Same length -> lexicographically smaller
                    else if (curr.length() == minLen && curr < ans) {
                        ans = curr;
                    }

                    // Aage jaane se k+1 ones ho jayenge,
                    // so this starting point ke liye break
                    break;
                }
            }
        }

        return ans;
    }
};