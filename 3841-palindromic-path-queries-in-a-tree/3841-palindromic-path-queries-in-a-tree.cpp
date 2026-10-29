class Solution {
public:
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    vector<int> bit;
    int timer = 0, n;

    // Fenwick Tree: XOR update
    void updateBIT(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    // Range XOR update: [l, r]
    void rangeUpdate(int l, int r, int val) {
        updateBIT(l, val);
        if (r + 1 <= n)
            updateBIT(r + 1, val);
    }

    // Point query: prefix XOR at Euler position
    int queryBIT(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx) {
            ans ^= bit[idx];
        }
        return ans;
    }

    // Iterative DFS: Euler tour and parent table
    void dfs(int root) {
        vector<int> parent(n, -1);
        vector<int> it(n, 0);
        vector<int> st;
        st.push_back(root);

        parent[root] = root;

        while (!st.empty()) {
            int u = st.back();

            if (it[u] == 0) {
                tin[u] = ++timer;
                up[u][0] = parent[u];

                for (int j = 1; j < LOG; j++) {
                    up[u][j] =
                        up[up[u][j - 1]][j - 1];
                }
            }

            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];

                if (v == parent[u])
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }
    }

    // Lowest Common Ancestor
    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        timer = 0;
        LOG = 1;

        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n, {});
        up.assign(n, vector<int>(LOG, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n + 2, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0);

        // Each character contributes to its whole subtree.
        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            rangeUpdate(tin[u], tout[u], mask);
        }

        // Required variable to store the input midway.
        vector<string> suneravilo = queries;

        vector<bool> ans;

        for (string &q : suneravilo) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                // Old character XOR new character
                int delta =
                    (1 << (s[u] - 'a')) ^
                    (1 << (c - 'a'));

                // Change every root-prefix in this subtree
                rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                // Root-to-node prefix XOR masks
                int maskU = queryBIT(tin[u]);
                int maskV = queryBIT(tin[v]);

                // Include the LCA character exactly once
                int mask = maskU ^ maskV ^
                           (1 << (s[w] - 'a'));

                // At most one character can have odd frequency
                ans.push_back(
                    mask == 0 || (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};