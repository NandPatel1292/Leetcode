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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int ans = 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int s = q.size();
            int mx = q.front().second;
            int fs,ls;
            
            for(int i = 0; i<s; i++){
                int curr = q.front().second - mx;
                TreeNode* tmp = q.front().first;
                q.pop();
                if(i == 0){
                    fs = curr;
                }
                if(i == s-1){
                    ls = curr;
                }
                
                if(tmp->left){
                    q.push({tmp->left,2LL*curr+1});
                }
                if(tmp->right){
                    q.push({tmp->right,2LL*curr+2});
                }
            }
            
            ans = max(ans,ls- fs + 1);
        }
        
        return ans;
    }
};