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
    void solve(TreeNode* root, TreeNode* &prev,TreeNode* &w1F, TreeNode* &w1S, TreeNode* &w2F, TreeNode* &w2S, int &wCount ){
        // base case
        if(root == nullptr) return;
        solve(root -> left, prev, w1F, w1S, w2F, w2S, wCount);
        if(prev == nullptr){
            prev = root;
        }else{
            if(root -> val < prev -> val){
                if(wCount == 0){
                    w1F = prev;
                    w1S = root;
                    wCount++;
                }else{
                    w2F = prev;
                    w2S = root;
                    wCount++; 
                }
            }
            prev = root;
        }
        solve(root -> right, prev, w1F, w1S, w2F, w2S, wCount);
    }

public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* w1F = nullptr;
        TreeNode* w1S = nullptr;
        TreeNode* w2F = nullptr;
        TreeNode* w2S = nullptr;
        int wCount = 0;
        solve(root, prev, w1F, w1S, w2F, w2S, wCount);
        if(wCount == 1){
            swap(w1F -> val, w1S ->val);
        }else{
            swap(w1F->val, w2S ->val);
        }

    }
};