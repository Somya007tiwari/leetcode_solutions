class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {

            char a = s[i];
            char b = t[i];

            // s -> t
            if (mp1.count(a)) {
                if (mp1[a] != b)
                    return false;
            }

            // t -> s
            if (mp2.count(b)) {
                if (mp2[b] != a)
                    return false;
            }

            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};