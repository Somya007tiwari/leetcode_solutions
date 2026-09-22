class Solution {
public:
    int k, n;
    vector<int> nums;
    vector<int> prodArr;
    vector<array<array<int,5>,5>> trans;

    void setLeaf(int node, int v) {
        v %= k;
        prodArr[node] = v;
        for (int s = 0; s < k; s++) {
            for (int x = 0; x < k; x++) trans[node][s][x] = 0;
            trans[node][s][(s * v) % k] = 1;
        }
    }

    void pull(int node) {
        int L = 2*node, R = 2*node+1;
        prodArr[node] = (prodArr[L] * prodArr[R]) % k;
        for (int s = 0; s < k; s++) {
            int mid = (s * prodArr[L]) % k;
            for (int x = 0; x < k; x++)
                trans[node][s][x] = trans[L][s][x] + trans[R][mid][x];
        }
    }

    void build(int node, int l, int r) {
        if (l == r) { setLeaf(node, nums[l]); return; }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        pull(node);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { setLeaf(node, val); return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        pull(node);
    }

    int curResidue;
    vector<long long> ans;

    void query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            for (int x = 0; x < k; x++) ans[x] += trans[node][curResidue][x];
            curResidue = (curResidue * prodArr[node]) % k;
            return;
        }
        int mid = (l + r) / 2;
        query(2*node, l, mid, ql, qr);
        query(2*node+1, mid+1, r, ql, qr);
    }

    vector<int> resultArray(vector<int>& nums_, int k_, vector<vector<int>>& queries) {
        nums = nums_; k = k_; n = nums.size();
        prodArr.assign(4*n, 0);
        trans.assign(4*n, {});
        build(1, 0, n-1);

        vector<int> result;
        result.reserve(queries.size());
        for (auto &q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n-1, index, value);
            ans.assign(k, 0);
            curResidue = 1 % k;
            query(1, 0, n-1, start, n-1);
            result.push_back((int)ans[x]);
        }
        return result;
    }
};