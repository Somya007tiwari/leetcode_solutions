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
    // left subtree ka sabse right node
    TreeNode* findLastRight(TreeNode* root) {
        while (root->right) root = root->right;
        return root;
    }

    // node delete karke uski jagah jo subtree lagani hai wo return karta hai
    TreeNode* helper(TreeNode* root) {
        if (!root->left)  return root->right;   // case 1: left nahi
        if (!root->right) return root->left;    // case 2: right nahi

        TreeNode* rightChild = root->right;             // case 3: dono hain
        TreeNode* lastRight  = findLastRight(root->left);
        lastRight->right = rightChild;                  // right subtree jod do
        return root->left;                              // left upar aa gaya
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) return helper(root);      // root hi delete ho raha hai

        TreeNode* dummy = root;                         // original root yaad rakho
        while (root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else root = root->left;
            } else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else root = root->right;
            }
        }
        return dummy;
    }
};