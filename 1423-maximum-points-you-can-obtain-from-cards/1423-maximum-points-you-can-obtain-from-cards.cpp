class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Total sum of all cards
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += cardPoints[i];
        }

        // If we take all cards
        if (k == n) {
            return totalSum;
        }

        // Window size of cards we don't take
        int windowSize = n - k;

        int windowSum = 0;

        // Calculate first window sum
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minSum = windowSum;

        // Sliding window
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i];
            windowSum -= cardPoints[i - windowSize];

            minSum = min(minSum, windowSum);
        }

        // Maximum score
        return totalSum - minSum;
    }
};