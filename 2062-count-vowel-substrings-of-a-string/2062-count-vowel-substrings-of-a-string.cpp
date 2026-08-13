class Solution {
public:
    int countVowelSubstrings(string word) {
        int count = 0;
        for(int i=0; i<word.size(); i++){
            unordered_set<char>vowels;
            for(int j=i; j<word.size(); j++){
                if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j]== 'o' || word[j] == 'u'){
                    vowels.insert(word[j]);
                    if(vowels.size() == 5)
                    count ++;
                    } 
                    else {
                        break;
                    }
            }
        }
        return count;
    }
};