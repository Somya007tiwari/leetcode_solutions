
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // Step 2: Distance array
        // dist[node][count] = minimum cost
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, LLONG_MAX)
        );

        // Min heap: {distance, node, consecutive count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // Starting node has one character
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // Step 3: Dijkstra
        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (d != dist[u][cnt]) {
                continue;
            }

            // Destination reached
            if (u == n - 1) {
                return (int)d;
            }

            // Explore neighbours
            for (auto &[v, w] : adj[u]) {

                int newCnt;

                // Same character
                if (labels[u] == labels[v]) {
                    newCnt = cnt + 1;
                }
                else {
                    // Different character
                    newCnt = 1;
                }

                // Cannot exceed k consecutive characters
                if (newCnt > k) {
                    continue;
                }

                long long newDist = d + w;

                // Relaxation
                if (newDist < dist[v][newCnt]) {

                    dist[v][newCnt] = newDist;

                    pq.push({
                        newDist,
                        v,
                        newCnt
                    });
                }
            }
        }

        // No valid path exists
        return -1;
    }
};
