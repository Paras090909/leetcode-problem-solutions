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
    void solve(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            swap(t->left, t->right);

            if(t->left != nullptr) q.push(t->left);
            if(t -> right != nullptr) q.push(t->right);
        }
        return ;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        solve(root);
        return root;
    }
};