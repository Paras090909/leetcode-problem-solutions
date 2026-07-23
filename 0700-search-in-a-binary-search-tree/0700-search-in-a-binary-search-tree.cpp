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
    void helper(TreeNode* root, int val,  TreeNode*&res, bool &found){
        // base case
        if(root == nullptr) return;
        if(root -> val == val){
        found = true;
        res = root;
        return;
        }

        if(root -> val > val){
            helper(root -> left, val, res, found);
        }else{
            helper(root -> right, val, res, found);
        }
        return ;

    }

public:
    TreeNode* searchBST(TreeNode* root, int val) {
        bool found = false;
        TreeNode* res = nullptr;
        // better to not use queue for storing 
        //queue<TreeNode*>q;
        helper(root, val,  res, found);
        return res;
        
    }
};