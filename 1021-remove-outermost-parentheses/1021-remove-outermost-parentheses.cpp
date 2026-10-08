class Solution {
public:
    string removeOuterParentheses(string s) {
        // Intuition:
        // Stack ki zaroorat nahi, sirf ek counter 'cnt' (depth) chahiye.
        //   '(' -> pehle check: agar cnt > 0 hai to ye outer nahi hai, add karo. Phir cnt++
        //   ')' -> pehle cnt--. Phir agar cnt > 0 hai to ye outer nahi hai, add karo.
        // Jab cnt == 0 pe '(' aaye => outermost opening (skip)
        // Jab cnt-- ke baad 0 ho jaye => outermost closing (skip)

        string ans = "";
        int cnt = 0;

        for (char c : s) {
            if (c == '(') {
                if (cnt > 0) ans += c;   // inner '(' hai
                cnt++;
            } else {
                cnt--;
                if (cnt > 0) ans += c;   // inner ')' hai
            }
        }
        return ans;
    }
};

// TC: O(N) -> single pass
// SC: O(1) extra (ans output ke alawa)