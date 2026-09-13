class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> A, B;
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c] == 1) A.push_back({r, c});
                if (img2[r][c] == 1) B.push_back({r, c});
            }
        }
        
        if (A.empty() || B.empty()) return 0;
        
        // Encode (dx, dy) as a single integer key to avoid pair hashing overhead
        unordered_map<int, int> count;
        int best = 0;
        int offset = n; // to keep encoded values non-negative
        
        for (auto& a : A) {
            for (auto& b : B) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;
                int key = (dx + offset) * (2 * n + 1) + (dy + offset);
                int val = ++count[key];
                best = max(best, val);
            }
        }
        
        return best;
    }
};