class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        unordered_set<string> source;

        // Saari source cities store karo
        for (auto &path : paths) {
            source.insert(path[0]);
        }

        // Jo destination source nahi hai,
        // wahi final destination hai
        for (auto &path : paths) {

            string destination = path[1];

            if (source.find(destination) == source.end()) {
                return destination;
            }
        }

        return "";
    }
};