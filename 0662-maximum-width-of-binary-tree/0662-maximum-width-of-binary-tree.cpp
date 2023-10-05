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
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
    
        int ans = 0;        
        while(!q.empty()){
            auto x = q.front();
            int line = x.second;
            
            int mi,mx;
            int size = q.size();
            for(int i = 0; i<size; i++){
                int tmp = q.front().second - line; 
                auto node = q.front().first;
                q.pop();
                if(i == 0){
                    mi = tmp;
                    
                }
                if(i == size-1){
                    mx = tmp;
                }
                
                if(node->left){
                    q.push({node->left,tmp * 2LL +1});
                }
                if(node->right){
                    q.push({node->right,tmp * 2LL +2});
                }
            }
            
            ans = max(ans,mx - mi +1);
           
            
        }
        return ans;
    }
};