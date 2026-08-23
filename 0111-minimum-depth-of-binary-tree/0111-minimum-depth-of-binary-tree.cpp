/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            res++;
            int s = q.size();
            while (s--) {
                TreeNode* t = q.front();
                q.pop();
                if (!t->left && !t->right) {
                    return res;
                }
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
            }
        }
        return 0;
    }
};