class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x) { s += x % 10; x /= 10; }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // {{digitSum, value}, originalIndex}
        vector<pair<pair<int,int>,int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({{digitSum(nums[i]), nums[i]}, i});

        sort(v.begin(), v.end());

        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i].second == i) continue;
            int j = i, len = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j].second;
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};