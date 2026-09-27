class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pairIdx(n);
        stack<int> st;

        // Step 1: precompute matching pairs
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top(); st.pop();
                pairIdx[i] = j;
                pairIdx[j] = i;
            }
        }

        // Step 2: traverse with direction flips
        string res;
        int dir = 1;
        for (int i = 0; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = pairIdx[i];
                dir = -dir;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};