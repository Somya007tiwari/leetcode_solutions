class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int revPos = 26 - (s[i] - 'a');   // 'a' -> 26, 'z' -> 1
            sum += revPos * (i + 1);          // 1-indexed position se multiply
        }
        return sum;
    }
};