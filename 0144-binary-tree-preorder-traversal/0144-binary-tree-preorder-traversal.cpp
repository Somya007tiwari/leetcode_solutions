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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // left nahi hai to curr ko visit karo, fir right jao
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                // left subtree ka rightmost node (predecessor) dhundo
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // thread nahi bana: link banao prev -> curr
                    prev->right = curr;
                    ans.push_back(curr->val);  // preorder: left jaane se PEHLE visit
                    curr = curr->left;
                }
                else {
                    // thread already hai: left subtree complete ho chuka
                    prev->right = NULL;        // thread todo
                    curr = curr->right;        // ab visit nahi karna, bas right jao
                }
            }
        }
        return ans;
    }
};