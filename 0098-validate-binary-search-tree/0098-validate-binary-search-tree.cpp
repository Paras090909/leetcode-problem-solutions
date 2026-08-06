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
    void inorder(TreeNode* root, TreeNode* &prev, bool &res){
        // base case
        if(root == nullptr) return;
        inorder(root -> left, prev, res);
        if(prev == nullptr){
            prev = root;
        }
        else{
            if(root -> val <= prev -> val){
                res = false;
            }
            prev = root;
        }
        inorder(root -> right, prev, res);
        return;
    }

public:
    bool isValidBST(TreeNode* root) {
        bool res = true;
        TreeNode* prev = nullptr;
        inorder(root, prev, res);
        return res;
    }
};