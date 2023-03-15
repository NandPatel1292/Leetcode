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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool f = false;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            
            if(tmp == NULL){
                f = true;
            }
            else{
                if(f == true){
                    return false;
                }
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return true;
    }
};