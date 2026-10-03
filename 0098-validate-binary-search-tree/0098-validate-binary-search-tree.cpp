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

    bool check(TreeNode* root, long long low, long long high) {

        // Agar node NULL hai,
        // toh abhi tak tree valid hai
        if(root == NULL) {
            return true;
        }

        // Current node ki value valid range ke andar honi chahiye
        // Agar range ke bahar hai, toh BST valid nahi hai
        if(root->val <= low || root->val >= high) {
            return false;
        }

        // Left subtree ke liye:
        // Values current node se chhoti honi chahiye
        bool left = check(root->left, low, root->val);

        // Right subtree ke liye:
        // Values current node se badi honi chahiye
        bool right = check(root->right, root->val, high);

        // Dono subtrees valid hone chahiye
        return left && right;
    }


    bool isValidBST(TreeNode* root) {

        // Initially root ki koi upper/lower limit nahi hai
        // Isliye -infinity aur +infinity pass karenge
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};