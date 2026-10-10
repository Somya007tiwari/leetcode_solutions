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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;                 // har level ka average yahan store hoga
        if (root == NULL) return ans;       // empty tree to khaali answer

        queue<TreeNode*> q;                 // BFS ke liye queue
        q.push(root);                       // root ko pehle push karo (level 0)

        while (!q.empty()) {
            int size = q.size();            // current level mein kitne nodes hain
                                            // (loop se pehle freeze karna zaroori hai,
                                            // kyunki andar queue ka size badalta rehta hai)

            long long sum = 0;              // is level ka sum. long long kyunki int overflow ho sakta hai

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // queue ke aage wala node nikaalo
                q.pop();                    // use queue se hata do

                sum += node->val;           // is node ki value level ke sum mein jod do

                if (node->left != NULL)     // left child hai to agle level ke liye push karo
                    q.push(node->left);

                if (node->right != NULL)    // right child hai to agle level ke liye push karo
                    q.push(node->right);
            }

            // ek level poora ho gaya, ab average nikaalo
            // (double) cast pehle, warna integer division se decimal kat jaayega
            ans.push_back((double)sum / size);
        }

        return ans;                         // saare levels ke averages
    }
};