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
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // left nahi hai to curr ko visit karo, fir right jao
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                // left subtree ka rightmost node dhundo (predecessor)
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // thread nahi bana hai: link banao prev -> curr
                    prev->right = curr;
                    curr = curr->left;      // ab left mein jao
                }
                else {
                    // thread already hai matlab left subtree complete ho chuka
                    prev->right = NULL;     // thread todo (tree wapas original)
                    ans.push_back(curr->val); // ab curr ko visit karo
                    curr = curr->right;     // right subtree pe jao
                }
            }
        }
        return ans;
    }
};