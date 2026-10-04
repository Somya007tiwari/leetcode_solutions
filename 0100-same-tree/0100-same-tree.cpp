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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: Dono nodes NULL hain
        // Matlab yaha tak tree same hai
        if (p == NULL && q == NULL) {
            return true;
        }

        // Case 2: Sirf ek node NULL hai
        // Structure different hai
        if (p == NULL || q == NULL) {
            return false;
        }

        // Case 3: Dono nodes ki value different hai
        if (p->val != q->val) {
            return false;
        }

        // Case 4:
        // Current nodes same hain,
        // ab left aur right subtree check karo
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};