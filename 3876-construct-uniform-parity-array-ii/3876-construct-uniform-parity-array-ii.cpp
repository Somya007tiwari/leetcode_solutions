class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        bool allEven = true;

        for (int x : nums1) {
            if (x % 2 != 0) {
                allEven = false;
                break;
            }
        }

        return (mn % 2 == 1) || allEven;
    }
};