class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                int dx = i - xCenter, dy = j - yCenter;
                if (dx * dx + dy * dy <= radius * radius) return true;
            }
        }
        return false;
    }
};