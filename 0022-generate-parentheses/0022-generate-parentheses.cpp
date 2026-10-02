class Solution {
public:

    void solve(int n, int open, int close, string &s,
               vector<string> &ans) {

        // Base Case:
        // Agar saare opening aur closing brackets use ho gaye
        // Toh current string ek valid combination hai
        if(open == n && close == n) {
            ans.push_back(s);
            return;
        }

        // Step 1: Opening bracket '(' add karo
        // Agar abhi tak n opening brackets use nahi hue
        if(open < n) {

            // Current string mein '(' add karo
            s.push_back('(');

            // Recursive call: open ko 1 se increase karo
            solve(n, open + 1, close, s, ans);

            // Backtracking:
            // Recursive call ke baad '(' remove karo
            // Taaki doosri possibility explore kar sakein
            s.pop_back();
        }

        // Step 2: Closing bracket ')' add karo
        // Closing brackets tabhi add honge
        // Jab opening brackets ki count zyada ho
        if(close < open) {

            // Current string mein ')' add karo
            s.push_back(')');

            // Recursive call: close ko 1 se increase karo
            solve(n, open, close + 1, s, ans);

            // Backtracking:
            // ')' remove karo aur previous state mein jao
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        // Saare valid combinations store karne ke liye
        vector<string> ans;

        // Initially string empty hai
        string s = "";

        // Recursion start karo
        // Initially open = 0 aur close = 0
        solve(n, 0, 0, s, ans);

        // Saare valid combinations return karo
        return ans;
    }
};