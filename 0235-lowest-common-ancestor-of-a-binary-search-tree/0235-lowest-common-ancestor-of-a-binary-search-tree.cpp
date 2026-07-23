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
    void solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &res){
        // base case
        if(root == nullptr) return ;
        if(root == p || root == q){
            res = root;
            return;
        }

        if(root -> val > q -> val){
            solve(root ->left, p, q, res);
        }else if(root -> val < p -> val ){
            solve(root -> right, p, q, res);
        }else{
            res = root;
            return ;
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        if(p-> val < q -> val){
            solve(root, p, q, res);
        }else{
            solve(root, q, p, res);
        }
        return res;
    }
};