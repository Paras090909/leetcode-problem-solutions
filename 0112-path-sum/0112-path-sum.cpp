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
    void solve(TreeNode* root, int targetSum, int currSum, bool &result){
        if(root == nullptr) return;
        currSum+=root->val;
        if((root -> left == nullptr) && (root -> right == nullptr)){        // indicating leaf node
            if(currSum == targetSum){
                result = true;
                return;
            }
        }
        solve(root->left, targetSum,  currSum, result);
        solve(root->right, targetSum, currSum, result);
        return;
        
    }    

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        bool result = false;
        solve(root, targetSum, currSum, result);
        return result;      
    }
};