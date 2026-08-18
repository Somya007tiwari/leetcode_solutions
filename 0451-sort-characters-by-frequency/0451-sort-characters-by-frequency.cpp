class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char, int> freq;
       for(int i = 0; i<s.size(); i++){
        char c = s[i];
        freq[c]++;
       }
        vector<pair<char,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(), vec.end(),[](pair<char,int> & a, pair<char,int> & b){
            return a.second > b.second;
        });
        string result = "";
        for(int i = 0; i < vec.size(); i++){
            result += string(vec[i].second , vec[i].first);
       }
       return result;
    }
};