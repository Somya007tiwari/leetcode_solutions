class Solution {
    int dm[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int toDay(const string& s) {
        int m = stoi(s.substr(0, 2));
        int d = stoi(s.substr(3, 2));
        int days = 0;
        for (int i = 0; i < m - 1; i++) days += dm[i];
        return days + d;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int aA = toDay(arriveAlice), lA = toDay(leaveAlice);
        int aB = toDay(arriveBob),   lB = toDay(leaveBob);

        int start = max(aA, aB);
        int end   = min(lA, lB);
        return max(0, end - start + 1);
    }
};