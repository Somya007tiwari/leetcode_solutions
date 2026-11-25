
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string temp = "";

        function<void(int)> solve = [&](int idx) {

            // Base case
            if (idx == digits.size()) {
                ans.push_back(temp);
                return;
            }

            // Get letters for current digit
            string letters = mp[digits[idx] - '0'];

            for (char ch : letters) {

                temp.push_back(ch);

                solve(idx + 1);

                // Backtracking
                temp.pop_back();
            }
        };

        solve(0);

        return ans;
    }
};
