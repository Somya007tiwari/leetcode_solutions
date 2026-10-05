class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;

        // Initial score
        st.push(0);

        for (char ch : s) {

            if (ch == '(') {

                // Naya group start hua
                // Current score ko save kar do
                st.push(0);
            }

            else {

                // Current group ka score
                int curr = st.top();
                st.pop();

                // Agar curr = 0 hai
                // Matlab direct "()" mila
                int score;

                if (curr == 0) {
                    score = 1;
                }
                else {
                    // "(A)" ka score = 2 * A
                    score = 2 * curr;
                }

                // Ye score outer group ke score me add karo
                st.top() += score;
            }
        }

        return st.top();
    }
};