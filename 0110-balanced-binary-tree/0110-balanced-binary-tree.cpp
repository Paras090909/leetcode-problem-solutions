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
    int solve(TreeNode* root, bool &res){
        // base
        if(root == nullptr) return 0;
        //if(root->left == nullptr && root->right == nullptr) return 0;

        int left = solve(root->left, res);
        int right = solve(root->right, res);
        int diff = abs(left - right);
        if(diff > 1)  res = false;
        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool result = true;
        int val = solve(root, result);
        return result;    
    }
};