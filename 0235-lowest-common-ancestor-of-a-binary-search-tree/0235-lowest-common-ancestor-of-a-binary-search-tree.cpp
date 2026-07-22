/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

private:
    int helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode * &ans){
        // base case
        if(root == nullptr) return 0;
        int left = helper(root -> left, p, q, ans);
        int right = helper(root -> right, p, q, ans);
        int self = 0;
        if(root == p || root == q){
            self = 1;
        }
        int total = left + self + right;
        
        if(total == 2 && ans == nullptr){
            ans = root;
        }
        return total;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        helper(root, p, q, ans);
        return ans;
    }
};