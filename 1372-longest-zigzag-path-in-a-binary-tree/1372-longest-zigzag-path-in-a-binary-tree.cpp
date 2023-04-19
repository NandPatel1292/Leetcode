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

// 0 as left
// 1 as right

class Solution {
public:
    int mx = 0;
    
    void solve(TreeNode* root,int dir,int len){
        if(root == NULL){
            return;
        }
        
        mx = max(mx,len);
        
        if(dir == 0){
            solve(root->left,dir,1);
            solve(root->right,dir^1,len+1);
        }
        else{
            solve(root->left,dir^1,len+1);
            solve(root->right,dir,1);
        }
        
        return;
    }
    
    int longestZigZag(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return 0;
        }
        
        solve(root->left,0,1);
        solve(root->right,1,1);
        
        return mx;
    }
};