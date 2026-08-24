class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto interval : intervals) {
            
            // Agar ans empty hai ya overlap nahi ho raha
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            
            // Overlap ho raha hai
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};