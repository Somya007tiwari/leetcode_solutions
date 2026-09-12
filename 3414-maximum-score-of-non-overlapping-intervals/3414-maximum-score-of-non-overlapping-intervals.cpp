class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        // sort by right endpoint, then by index for tie-breaking determinism
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (intervals[a][1] != intervals[b][1]) return intervals[a][1] < intervals[b][1];
            return a < b;
        });

        vector<vector<int>> sorted_intervals(n);
        for (int i = 0; i < n; i++) sorted_intervals[i] = intervals[idx[i]];

        // dp[i][k] = best (score, lexicographically smallest list of original indices) 
        // using first i intervals (sorted), choosing up to k of them
        // We'll store as pair<long long, vector<int>>
        // dp[i][k]: considering intervals[0..i-1], choose at most k
        int K = 4;
        vector<vector<long long>> dpScore(n + 1, vector<long long>(K + 1, 0));
        vector<vector<vector<int>>> dpChoice(n + 1, vector<vector<int>>(K + 1));

        // binary search: find rightmost interval j (0-indexed in sorted) such that sorted_intervals[j][1] < sorted_intervals[i][0]
        // i.e., end < current start (strictly non-overlapping, since sharing boundary counts as overlap)
        vector<int> prevNonOverlap(n);
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1, res = -1;
            int curStart = sorted_intervals[i][0];
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (sorted_intervals[mid][1] < curStart) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            prevNonOverlap[i] = res; // -1 if none
        }

        auto betterChoice = [&](vector<int>& a, vector<int>& b) -> bool {
            // returns true if a is lexicographically smaller than b (both same length, sorted)
            for (size_t i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) return a[i] < b[i];
            }
            return false;
        };

        for (int i = 1; i <= n; i++) {
            int curIdx = i - 1; // index in sorted_intervals
            int origIdx = idx[curIdx];
            long long w = sorted_intervals[curIdx][2];
            int p = prevNonOverlap[curIdx]; // index in sorted (0-indexed), -1 if none

            for (int k = 0; k <= K; k++) {
                // option 1: don't take current interval
                dpScore[i][k] = dpScore[i - 1][k];
                dpChoice[i][k] = dpChoice[i - 1][k];

                // option 2: take current interval (if k >= 1)
                if (k >= 1) {
                    long long prevScore = (p == -1) ? 0 : dpScore[p + 1][k - 1];
                    vector<int> prevChoice = (p == -1) ? vector<int>() : dpChoice[p + 1][k - 1];
                    long long newScore = prevScore + w;
                    
                    if (newScore > dpScore[i][k]) {
                        dpScore[i][k] = newScore;
                        vector<int> newChoice = prevChoice;
                        newChoice.push_back(origIdx);
                        sort(newChoice.begin(), newChoice.end());
                        dpChoice[i][k] = newChoice;
                    } else if (newScore == dpScore[i][k]) {
                        vector<int> newChoice = prevChoice;
                        newChoice.push_back(origIdx);
                        sort(newChoice.begin(), newChoice.end());
                        if (betterChoice(newChoice, dpChoice[i][k])) {
                            dpChoice[i][k] = newChoice;
                        }
                    }
                }
            }
        }

        // find best among k=0..4
        long long bestScore = -1;
        vector<int> bestChoice;
        for (int k = 0; k <= K; k++) {
            if (dpScore[n][k] > bestScore) {
                bestScore = dpScore[n][k];
                bestChoice = dpChoice[n][k];
            } else if (dpScore[n][k] == bestScore) {
                if (betterChoice(dpChoice[n][k], bestChoice)) {
                    bestChoice = dpChoice[n][k];
                }
            }
        }

        return bestChoice;
    }
};