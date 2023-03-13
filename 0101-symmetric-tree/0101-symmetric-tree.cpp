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
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            TreeNode* lf = q.front();
            q.pop();
            TreeNode* rg = q.front();
            q.pop();
            
            if(lf == NULL && rg == NULL){
                continue;
            }
            if(lf == NULL || rg == NULL || lf->val != rg->val){
                return false;
            }
            
            q.push(lf->left);
            q.push(rg->right);
            q.push(lf->right);
            q.push(rg->left);
        }
        
        return true;
        
    }
};