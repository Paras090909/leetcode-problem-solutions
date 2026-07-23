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

        if(root -> val > q -> val){ // node val is 8, q val is 4  
            solve(root ->left, p, q, res);
        }else if(root -> val < p -> val ){ // node val 2, p val 7
            solve(root -> right, p, q, res);
        }else{ // found the splitting point node val 4 , p val 3, q val 5
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