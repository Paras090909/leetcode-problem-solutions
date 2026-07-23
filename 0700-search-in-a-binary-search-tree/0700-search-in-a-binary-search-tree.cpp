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
    void helper(TreeNode* root, int val,  TreeNode*&res){
        // base case
        if(root == nullptr) return;
        if(root -> val == val){
        res = root;
        return;
        }

        if(root -> val > val){
            helper(root -> left, val, res);
        }else{
            helper(root -> right, val, res);
        }
        return ;

    }

public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = nullptr;
        helper(root, val,  res);
        return res;
        
    }
};