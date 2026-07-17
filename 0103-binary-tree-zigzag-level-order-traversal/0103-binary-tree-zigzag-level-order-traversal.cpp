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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int rightToLeft = 0;

        while (!q.empty()) {
            int lvlSize = q.size();
            int left = 0, right = lvlSize - 1;

            vector<int> tmp(lvlSize);

            while (lvlSize--) {
                TreeNode* t = q.front();
                q.pop();

                if (rightToLeft == 1) {
                    tmp[right] = t->val;
                    right--;
                } else {
                    tmp[left] = t->val;
                    left++;
                }
                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
            }
            rightToLeft = 1 - rightToLeft;
            res.push_back(tmp);
        }
        return res;
    }
};