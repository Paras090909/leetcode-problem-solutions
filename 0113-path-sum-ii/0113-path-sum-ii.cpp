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
    void solve(TreeNode* root, int targetSum, int currSum, vector<vector<int>>&result, vector<int>&tmp){
        if(root == nullptr) return;
        currSum+=root->val;
        tmp.push_back(root->val);

        if((root -> left == nullptr) && (root -> right == nullptr)){ // denotes leaft node
            if(currSum == targetSum){
                result.push_back(tmp);
            }
        }
        
        solve(root->left, targetSum,  currSum, result, tmp);
        solve(root->right, targetSum, currSum, result, tmp);
        tmp.pop_back();
        return;
        
    }    

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        vector<vector<int>>result;
        vector<int>tmp;
        solve(root, targetSum, currSum, result, tmp);
        return result;
    }
};