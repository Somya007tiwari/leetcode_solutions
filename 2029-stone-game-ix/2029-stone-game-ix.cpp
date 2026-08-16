class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt[3] = {0};

        // Count remainders
        for(int x : stones) {
            cnt[x % 3]++;
        }

        // If no remainder-1 and no remainder-2 stones
        if(cnt[1] == 0 && cnt[2] == 0)
            return false;

        // If remainder-0 stones are even
        if(cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If remainder-0 stones are odd
        return abs(cnt[1] - cnt[2]) > 2;
    }
};