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
    void solve(TreeNode* root, vector<int>&container, int &sum){
        if(root == nullptr) return ;
        sum = sum*10 + root ->val;
        if(root -> left == nullptr && root -> right == nullptr){
            container.push_back(sum);
        }
        solve(root->left, container, sum);
        solve(root -> right, container, sum);
        sum = sum - sum%10;
        sum = sum/10;
        return;
    }

public:
    int sumNumbers(TreeNode* root) {
        vector<int>container;
        int sum = 0;
        int result = 0;
        solve(root, container, sum);
        for(int it : container){
            result+=it;
        }
        return result;
    }
};