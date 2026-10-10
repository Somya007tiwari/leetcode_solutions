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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;                      // level number track karne ke liye

        while (!q.empty()) {
            int size = q.size();            // current level ke nodes (freeze karo)
            vector<int> row;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);   // normal left to right order mein store

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (level % 2 == 1)             // odd level hai to row ulti kar do
                reverse(row.begin(), row.end());

            ans.push_back(row);
            level++;
        }
        return ans;
    }
};