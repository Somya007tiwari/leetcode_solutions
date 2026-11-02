/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        // Queue stores {node, index}
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        unsigned long long maxWidth = 0;

        while (!q.empty()) {

            int size = q.size();

            // First node ka index
            unsigned long long minIndex = q.front().second;

            unsigned long long first = 0;
            unsigned long long last = 0;

            for (int i = 0; i < size; i++) {

                auto [node, index] = q.front();
                q.pop();

                // Normalize index to prevent overflow
                index -= minIndex;

                // First and last index of current level
                if (i == 0)
                    first = index;

                if (i == size - 1)
                    last = index;

                // Left child ka index
                if (node->left) {
                    q.push({
                        node->left,
                        2 * index + 1
                    });
                }

                // Right child ka index
                if (node->right) {
                    q.push({
                        node->right,
                        2 * index + 2
                    });
                }
            }

            // Current level ki width
            unsigned long long width = last - first + 1;

            maxWidth = max(maxWidth, width);
        }

        return (int)maxWidth;
    }
};