class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        set<string> result = parseUnion(expression, pos);
        return vector<string>(result.begin(), result.end());
    }
    
private:
    // Parses a comma-separated list of concatenation-terms, 
    // stops at unmatched '}' or end of string.
    set<string> parseUnion(const string& expr, int& pos) {
        set<string> result;
        set<string> current = parseConcat(expr, pos);
        result.insert(current.begin(), current.end());
        
        while (pos < (int)expr.size() && expr[pos] == ',') {
            pos++; // skip ','
            current = parseConcat(expr, pos);
            result.insert(current.begin(), current.end());
        }
        
        return result;
    }
    
    // Parses a sequence of factors (concatenation), 
    // stops at ',' or '}' or end of string.
    set<string> parseConcat(const string& expr, int& pos) {
        vector<set<string>> factors;
        
        while (pos < (int)expr.size() && expr[pos] != ',' && expr[pos] != '}') {
            factors.push_back(parseFactor(expr, pos));
        }
        
        // Cartesian product of all factors
        set<string> result;
        result.insert(""); // start with empty string
        
        for (auto& factorSet : factors) {
            set<string> newResult;
            for (const string& prefix : result) {
                for (const string& suffix : factorSet) {
                    newResult.insert(prefix + suffix);
                }
            }
            result = newResult;
        }
        
        return result;
    }
    
    // Parses a single factor: either a {...} group or a run of letters.
    set<string> parseFactor(const string& expr, int& pos) {
        if (expr[pos] == '{') {
            pos++; // skip '{'
            set<string> inner = parseUnion(expr, pos);
            pos++; // skip '}'
            return inner;
        } else {
            // collect a maximal run of lowercase letters as one word
            int start = pos;
            while (pos < (int)expr.size() && islower(expr[pos])) {
                pos++;
            }
            return {expr.substr(start, pos - start)};
        }
    }
};