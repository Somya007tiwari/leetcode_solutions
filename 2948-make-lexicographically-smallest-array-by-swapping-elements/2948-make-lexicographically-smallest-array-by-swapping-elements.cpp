#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        
        vector<int> result(n);
        vector<int> groupIndices;
        vector<int> groupValues;
        
        int prevVal = -1;
        for (int idx : order) {
            int val = nums[idx];
            if (prevVal != -1 && val - prevVal > limit) {
                sort(groupIndices.begin(), groupIndices.end());
                for (int k = 0; k < (int)groupIndices.size(); k++) {
                    result[groupIndices[k]] = groupValues[k];
                }
                groupIndices.clear();
                groupValues.clear();
            }
            groupIndices.push_back(idx);
            groupValues.push_back(val);
            prevVal = val;
        }
        
        if (!groupIndices.empty()) {
            sort(groupIndices.begin(), groupIndices.end());
            for (int k = 0; k < (int)groupIndices.size(); k++) {
                result[groupIndices[k]] = groupValues[k];
            }
        }
        
        return result;
    }
};