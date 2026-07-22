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
    void helper(TreeNode* root, int val, queue<TreeNode*>&q, TreeNode*&res, bool &found){
        // base case
        if(root == nullptr) return;
        if(root -> val == val){
        found = true;
        res = root;
        }

        if(found){
            q.push(root);
            helper(root -> left, val, q, res, found);
            helper(root->right, val, q, res, found);
        }else{
            helper(root -> left, val, q, res, found);
            helper(root -> right, val, q, res, found);
        }
        return ;
    }

public:
    TreeNode* searchBST(TreeNode* root, int val) {
        bool found = false;
        TreeNode* res = nullptr;
        queue<TreeNode*>q;
        helper(root, val, q, res, found);
        return res;
        
    }
};