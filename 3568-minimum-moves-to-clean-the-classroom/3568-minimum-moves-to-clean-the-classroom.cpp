class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<pair<int,int>> litter;
        pair<int,int> start;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') litter.push_back({i, j});
                else if (classroom[i][j] == 'S') start = {i, j};
            }

        int k = litter.size();
        if (k == 0) return 0;

        vector<vector<int>> litterIndex(m, vector<int>(n, -1));
        for (int i = 0; i < k; i++) litterIndex[litter[i].first][litter[i].second] = i;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int fullMask = (1 << k) - 1;
        // dist[i][j][mask][e] -> min moves, flattened
        // size: m*n*(fullMask+1)*(energy+1)
        vector<int> dist(m * n * (fullMask + 1) * (energy + 1), -1);

        auto idx = [&](int i, int j, int mask, int e) {
            return ((i * n + j) * (fullMask + 1) + mask) * (energy + 1) + e;
        };

        queue<tuple<int,int,int,int>> q;
        int startIdx = idx(start.first, start.second, 0, energy);
        dist[startIdx] = 0;
        q.push({start.first, start.second, 0, energy});

        int ans = -1;

        while (!q.empty()) {
            auto [ci, cj, mask, ce] = q.front(); q.pop();
            int d = dist[idx(ci, cj, mask, ce)];

            if (mask == fullMask) {
                ans = d;
                break;
            }

            if (ce == 0) continue;

            for (int dir = 0; dir < 4; dir++) {
                int ni = ci + dx[dir], nj = cj + dy[dir];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (classroom[ni][nj] == 'X') continue;

                int ne = (classroom[ni][nj] == 'R') ? energy : ce - 1;
                int nmask = mask;
                if (litterIndex[ni][nj] != -1) nmask |= (1 << litterIndex[ni][nj]);

                int nIdx = idx(ni, nj, nmask, ne);
                if (dist[nIdx] == -1) {
                    dist[nIdx] = d + 1;
                    q.push({ni, nj, nmask, ne});
                }
            }
        }

        return ans;
    }
};