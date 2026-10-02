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

    // Inorder traversal: Left -> Root -> Right
    // BST ka inorder traversal sorted order deta hai
    void inorder(TreeNode* root, int &k, int &ans) {

        // Agar root NULL hai, toh return kar jao
        if(root == NULL) {
            return;
        }

        // Step 1: Pehle left subtree mein jao
        // Left side mein smaller elements hote hain
        inorder(root->left, k, ans);

        // Step 2: Current node ko visit karo
        // Ek element mil gaya, toh k ko decrease karo
        k--;

        // Agar k zero ho gaya,
        // iska matlab current node hi kth smallest hai
        if(k == 0) {
            ans = root->val;
            return;
        }

        // Step 3: Ab right subtree mein jao
        // Right side mein larger elements hote hain
        inorder(root->right, k, ans);
    }


    int kthSmallest(TreeNode* root, int k) {

        // Answer store karne ke liye variable
        int ans = -1;

        // Inorder traversal start karo
        inorder(root, k, ans);

        // kth smallest element return karo
        return ans;
    }
};