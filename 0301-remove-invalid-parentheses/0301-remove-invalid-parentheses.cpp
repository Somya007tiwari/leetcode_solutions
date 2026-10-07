class Solution {
public:

    vector<string> ans;

    void solve(string &s, int index,
               int leftCount, int rightCount,
               int leftRemove, int rightRemove,
               string curr) {

        // String ke end tak pahunch gaye
        if(index == s.size()) {

            // Agar saare invalid parentheses remove ho gaye
            if(leftRemove == 0 && rightRemove == 0) {
                ans.push_back(curr);
            }

            return;
        }

        char ch = s[index];

        // -------------------------------
        // CASE 1: Current character '('
        // -------------------------------
        if(ch == '(') {

            // Option 1: '(' ko remove karo
            if(leftRemove > 0) {
                solve(s, index + 1,
                      leftCount, rightCount,
                      leftRemove - 1, rightRemove,
                      curr);
            }

            // Option 2: '(' ko keep karo
            solve(s, index + 1,
                  leftCount + 1, rightCount,
                  leftRemove, rightRemove,
                  curr + ch);
        }

        // -------------------------------
        // CASE 2: Current character ')'
        // -------------------------------
        else if(ch == ')') {

            // Option 1: ')' ko remove karo
            if(rightRemove > 0) {
                solve(s, index + 1,
                      leftCount, rightCount,
                      leftRemove, rightRemove - 1,
                      curr);
            }

            // Option 2: ')' ko keep karo
            // ')' tabhi rakhenge jab '(' available ho
            if(rightCount < leftCount) {

                solve(s, index + 1,
                      leftCount, rightCount + 1,
                      leftRemove, rightRemove,
                      curr + ch);
            }
        }

        // -------------------------------
        // CASE 3: Normal character
        // -------------------------------
        else {

            // Letter ko simply add karo
            solve(s, index + 1,
                  leftCount, rightCount,
                  leftRemove, rightRemove,
                  curr + ch);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Minimum invalid parentheses find karo
        for(char ch : s) {

            if(ch == '(') {
                leftRemove++;
            }

            else if(ch == ')') {

                if(leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        // Backtracking start
        solve(s, 0,
              0, 0,
              leftRemove, rightRemove,
              "");

        // Duplicate answers remove karo
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};