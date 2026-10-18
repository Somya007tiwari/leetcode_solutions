/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // col -> row -> sorted values
        map<int, map<int, multiset<int>>> nodes;

        // Queue stores: node, row, col
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            // Current node ki value store karo
            nodes[col][row].insert(node->val);

            // Left child: row + 1, col - 1
            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }

            // Right child: row + 1, col + 1
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> ans;

        // Columns left to right traverse karo
        for (auto p : nodes) {
            vector<int> colValues;

            // Har column mein rows top to bottom
            for (auto q : p.second) {

                // Same row aur column ki values sorted hongi
                for (auto val : q.second) {
                    colValues.push_back(val);
                }
            }

            ans.push_back(colValues);
        }

        return ans;
    }
};
