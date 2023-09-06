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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>>ans;
        
        queue<TreeNode*>q;
        q.push(root);
        bool flg = true;
        
        while(!q.empty()){
            int siz = q.size();
            vector<int>tmp(siz);
            
            for(int i = 0; i<siz; i++){
                auto x = q.front();
                q.pop();
                
                int ind;
                if(flg){
                    ind = i;
                }
                else{
                    ind = siz - i - 1;
                }
                tmp[ind] = x->val;
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
            flg = !flg;
            ans.push_back(tmp);
        }
        
        return ans;
    }
};