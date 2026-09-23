class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (hoursNeeded(piles, mid) <= h) {
                hi = mid;       // mid works, try slower speed
            } else {
                lo = mid + 1;   // too slow, need faster speed
            }
        }
        
        return lo;
    }
    
private:
    long long hoursNeeded(vector<int>& piles, int speed) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;  // ceiling division
        }
        return hours;
    }
};