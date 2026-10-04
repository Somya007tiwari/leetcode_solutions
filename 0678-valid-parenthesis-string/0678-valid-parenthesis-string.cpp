class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char ch : s) {

            if (ch == '(') {
                // '(' lene par dono possibilities me ek opening badhega
                minOpen++;
                maxOpen++;
            }

            else if (ch == ')') {
                // ')' ek opening ko close karega
                minOpen--;
                maxOpen--;
            }

            else { // ch == '*'

                // '*' ko ')' maan sakte hain
                minOpen--;

                // '*' ko '(' maan sakte hain
                maxOpen++;
            }

            // Agar maximum possible openings bhi negative ho gaye
            // matlab ')' bahut zyada hain
            if (maxOpen < 0) {
                return false;
            }

            // Minimum openings negative nahi ho sakte
            // '*' ko empty maan lenge
            minOpen = max(0, minOpen);
        }

        // Agar minimum possible unmatched '(' zero hai
        // toh valid configuration possible hai
        return minOpen == 0;
    }
};