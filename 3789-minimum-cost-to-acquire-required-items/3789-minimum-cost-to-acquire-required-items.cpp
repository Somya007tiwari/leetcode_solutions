
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        // Case 1: Buy all items separately
        long long costA = 1LL * need1 * cost1
                        + 1LL * need2 * cost2;

        // Case 2: Buy both-type items for all requirements
        long long costB = 1LL * max(need1, need2) * costBoth;

        // Case 3: Buy both-type items for common requirements
        int mn = min(need1, need2);

        long long costC = 1LL * mn * costBoth
                        + 1LL * (need1 - mn) * cost1
                        + 1LL * (need2 - mn) * cost2;

        // Return minimum cost
        return min({costA, costB, costC});
    }
};
