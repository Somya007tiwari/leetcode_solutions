class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int pref, suff, best, len;

        Node() {
            leftChar = rightChar = '#';
            pref = suff = best = len = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * node, l, mid, pos, ch);
        else
            update(2 * node + 1, mid + 1, r, pos, ch);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, pos, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};