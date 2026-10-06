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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (true) {
            if (node != NULL) {
                // node hai to stack mein daalo aur left jao
                st.push(node);
                node = node->left;
            }
            else {
                // left NULL ho gaya, ab stack check karo
                if (st.empty()) break;      // stack khaali = traversal khatam

                node = st.top();            // sabse recent node nikalo
                st.pop();
                ans.push_back(node->val);   // is node ko visit karo (root step)
                node = node->right;         // ab right subtree pe jao
            }
        }
        return ans;
    }
};