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
    void solve(TreeNode* root, int depth, int &res){
        if(root == nullptr) return;
        depth++;
        if(root->left == nullptr && root->right == nullptr){
           // cout<<"depth" << depth<<endl;
           if(depth > res){
            res = depth;
           }
        }
        solve(root->left, depth, res);
        solve(root->right, depth, res);
        depth--;
    }

public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        int depth = 0;
        solve(root, depth, res);
        // cout<<"depth" <<depth<<endl;
        // cout<<"res"<<res<<endl;
        return res;
    }
};