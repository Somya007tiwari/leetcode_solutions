class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') {
                // open bracket hai to bas push kar do
                st.push(ch);
            }
            else {
                // ')' aaya: agar top pe '(' hai to dono match, pop kar do
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    // match karne wala '(' nahi mila, isko bhi push karo
                    // (ye unmatched ')' hai)
                    st.push(ch);
                }
            }
        }
        // stack mein jo bacha wo sab unmatched brackets hain
        // har ek ke liye ek insertion lagega
        return st.size();
    }
};