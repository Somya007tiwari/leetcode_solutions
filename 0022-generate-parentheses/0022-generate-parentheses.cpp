class Solution {
public:

    void solve(int n, int open, int close, string &s,
               vector<string> &ans) {

        // Base Case
        if(open == n && close == n) {
            ans.push_back(s);
            return;
        }

        // We can add '('
        if(open < n) {
            s.push_back('(');

            solve(n, open + 1, close, s, ans);

            s.pop_back();
        }

        // We can add ')'
        if(close < open) {
            s.push_back(')');

            solve(n, open, close + 1, s, ans);

            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string s = "";

        solve(n, 0, 0, s, ans);

        return ans;
    }
};