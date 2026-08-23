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

private:
    void solve(TreeNode* root, int &res, int &depth){
        if(root == nullptr ) return;
        depth++;
        if(root->left == nullptr && root->right == nullptr){
            if(depth < res){
                res = depth;
            }
        }
        
        solve(root->left, res, depth);
        solve(root->right, res, depth);
        depth--;
        return;
    }

public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = INT_MAX;
        int depth = 0;
        solve(root, res, depth);
        return res;
    }
};